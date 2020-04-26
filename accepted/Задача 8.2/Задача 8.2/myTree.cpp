#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "myTree.h"


struct TreeElement
{
	char value;
	TreeElement* left = nullptr;
	TreeElement* right = nullptr;
};

struct MyTree
{
	TreeElement* head = nullptr;
};

MyTree* createTree()
{
	MyTree* newTree = new MyTree;
	return newTree;
}

TreeElement* getHead(MyTree* tree)
{
	return tree->head;
}

char getValue(TreeElement* treeElement)
{
	return treeElement->value;
}

TreeElement* getLeft(TreeElement* treeElement)
{
	return treeElement->left;
}

TreeElement* getRight(TreeElement* treeElement)
{
	return treeElement->right;
}

bool isOperator(char value)
{
	return value == '+' || value == '-' || value == '*' || value == '/';
}

bool isNumber(char value)
{
	return value >= '0' && value <= '9';
}

void addInHeadOfTree(MyTree* tree, TreeElement* newElement)
{
	tree->head = newElement;
}

void addInNotHead(MyTree* tree, TreeElement* cursor, TreeElement* newElement, bool& isElementAdded)
{
	if (!isElementAdded)
	{
		if (cursor->left == nullptr)
		{
			cursor->left = newElement;
			isElementAdded = true;
			return;
		}
		if (isOperator(cursor->left->value))
		{
			addInNotHead(tree, cursor->left, newElement, isElementAdded);
		}
	}
	if (!isElementAdded)
	{
		if (cursor->right == nullptr)
		{
			cursor->right = newElement;
			isElementAdded = true;
			return;
		}
		if (isOperator(cursor->right->value))
		{
			addInNotHead(tree, cursor->right, newElement, isElementAdded);
		}
	}
}

void addElementInTree(MyTree* tree, char newValue)
{
	TreeElement* newElement = new TreeElement;
	newElement->value = newValue;
	if (tree->head == nullptr)
	{
		addInHeadOfTree(tree, newElement);
		return;
	}

	TreeElement* cursor = tree->head;
	bool addedElement = false;
	addInNotHead(tree, cursor, newElement, addedElement);
}

void printTreeElement(TreeElement* treeElement)
{
	if (treeElement->left != nullptr)
	{
		if (isOperator(treeElement->value))
		{
			printf("( ");
		}
		printTreeElement(treeElement->left);
	}

	printf("%c ", treeElement->value);

	if (treeElement->right != nullptr)
	{
		printTreeElement(treeElement->right);
		printf(") ");
	}
}

void printTree(MyTree* tree)
{
	setlocale(LC_ALL, "Russian");

	if (tree->head == nullptr)
	{
		printf("Дерево пусто.");
		return;
	}

	printTreeElement(tree->head);
}

void putExpressionToTree(MyTree* tree, char expression[])
{
	for (int i = 0; i != strlen(expression); ++i)
	{
		char element = expression[i];
		if (isOperator(element) || isNumber(element))
		{
			addElementInTree(tree, element);
		}
	}
}

int count(TreeElement* treeElement)
{
	const char plus = '+';
	const char minus = '-';
	const char multiplication = '*';
	const char division = '/';

	if (treeElement->value == plus || treeElement->value == minus || treeElement->value == multiplication || treeElement->value == division)
	{
		if (treeElement->value == plus)
		{
			return count(treeElement->left) + count(treeElement->right);
		}

		if (treeElement->value == minus)
		{
			return count(treeElement->left) - count(treeElement->right);
		}

		if (treeElement->value == multiplication)
		{
			return count(treeElement->left) * count(treeElement->right);
		}

		if (treeElement->value == division)
		{
			return count(treeElement->left) / count(treeElement->right);
		}
	}
	else
	{
		return treeElement->value - '0';
	}

	return 0;
}

void deleteTreeElement(TreeElement* treeElement)
{
	if (treeElement->left != nullptr)
	{
		deleteTreeElement(treeElement->left);
	}

	if (treeElement->right != nullptr)
	{
		deleteTreeElement(treeElement->right);
	}

	delete treeElement;
}

void deleteTree(MyTree* tree)
{
	deleteTreeElement(tree->head);
	delete tree;
}