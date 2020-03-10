#include "myTree.h"
#include <iostream>

MyTree* createTree()
{
	MyTree* newTree = new MyTree;
	return newTree;
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
}