#include "AVLTree.h"
#include <string.h>
#include <stdio.h>

const int maxSize = 20;

struct TreeElement
{
	int key = 0;
	char value[maxSize]{};
	int height = 1;
	TreeElement* parent = nullptr;
	TreeElement* left = nullptr;
	TreeElement* right = nullptr;
};

struct Tree
{
	TreeElement* head = nullptr;
};

Tree* createTree()
{
	Tree* newTree = new Tree;
	return newTree;
}

TreeElement* getHead(Tree* tree)
{
	return tree->head;
}

void newHead(Tree* tree, TreeElement* newHead)
{
	tree->head = newHead;
}

int getHeight(TreeElement* treeElement)
{
	return (treeElement == nullptr) ? treeElement->height : 0;
}

int balanceFactor(TreeElement* treeElement)
{
	int heightLeft = (treeElement->left != nullptr) ? treeElement->left->height : 0;
	int heightRight = (treeElement->right != nullptr) ? treeElement->right->height : 0;
	return heightRight - heightLeft;
}

void fixHeight(TreeElement* treeElement)
{
	int heightLeft = (treeElement->left != nullptr) ? treeElement->left->height : 0;
	int heightRight = (treeElement->right != nullptr) ? treeElement->right->height : 0;
	treeElement->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

TreeElement* rotateRight(TreeElement* treeElement)
{
	TreeElement* left = treeElement->left;
	treeElement->left = left->right;
	left->right = treeElement;
	fixHeight(treeElement);
	fixHeight(left);
	return left;
}

// левый поворот вокруг q
TreeElement* rotateLeft(TreeElement* treeElement)
{
	TreeElement* right = treeElement->right;
	treeElement->right = right->left;
	right->left = treeElement;
	fixHeight(treeElement);
	fixHeight(right);
	return right;
}

// балансировка узла p
TreeElement* balanceElement(TreeElement* treeElement)
{
	fixHeight(treeElement);
	if (balanceFactor(treeElement) == 2)
	{
		if (balanceFactor(treeElement->right) < 0)
		{
			treeElement->right = rotateRight(treeElement->right);
		}
		return rotateLeft(treeElement);
	}
	if (balanceFactor(treeElement) == -2)
	{
		if (balanceFactor(treeElement->left) > 0)
		{
			treeElement->left = rotateLeft(treeElement->left);
		}
		return rotateRight(treeElement);
	}
	return treeElement;
}

// вставка ключа k в дерево с корнем p
TreeElement* addElementToTree(Tree* tree, TreeElement* treeElement, int newKey, char newValue[])
{
	if (tree->head == nullptr)
	{
		TreeElement* newElement = new TreeElement;
		newElement->key = newKey;
		strcpy(newElement->value, newValue);
		tree->head = newElement;
		return newElement;
	}
	if (treeElement == nullptr)
	{
		TreeElement* newElement = new TreeElement;
		newElement->key = newKey;
		strcpy(newElement->value, newValue);
		return newElement;
	}
	if (newKey == treeElement->key)
	{
		strcpy(treeElement->value, newValue);
		return treeElement;
	}
	else if (newKey < treeElement->key)
	{
		treeElement->left = addElementToTree(tree, treeElement->left, newKey, newValue);
	}
	else
	{
		treeElement->right = addElementToTree(tree, treeElement->right, newKey, newValue);
	}
	return balanceElement(treeElement);
}

// поиск узла с минимальным ключом в дереве p 
TreeElement* findMinimum(TreeElement* treeElement)
{
	return (treeElement->left != nullptr) ? findMinimum(treeElement->left) : treeElement;
}

// удаление узла с минимальным ключом из дерева p
TreeElement* removeMinimum(TreeElement* treeElement)
{
	if (treeElement->left == nullptr)
	{
		return treeElement->right;
	}
	treeElement->left = removeMinimum(treeElement->left);
	return balanceElement(treeElement);
}

// удаление ключа k из дерева p
TreeElement* removeElementFromTree(TreeElement* treeElement, int keyToDelete)
{
	if (treeElement == nullptr)
	{
		return nullptr;
	}
	if (keyToDelete < treeElement->key)
	{
		treeElement->left = removeElementFromTree(treeElement->left, keyToDelete);
	}
	else if (keyToDelete > treeElement->key)
	{
		treeElement->right = removeElementFromTree(treeElement->right, keyToDelete);
	}
	else
	{
		TreeElement* left = treeElement->left;
		TreeElement* right = treeElement->right;
		delete treeElement;
		if (right == nullptr)
		{
			return left;
		}
		TreeElement* minimum = findMinimum(right);
		minimum->right = removeMinimum(right);
		minimum->left = left;
		return balanceElement(minimum);
	}
	return balanceElement(treeElement);
}

bool isContain(Tree* tree, int keyToChecked)
{
	TreeElement* cursor = tree->head;
	if (cursor != nullptr)
	{
		while (keyToChecked != cursor->key)
		{
			if (keyToChecked < cursor->key)
			{
				if (cursor->left == nullptr)
				{
					return false;
				}
				cursor = cursor->left;
			}
			else if (keyToChecked > cursor->key)
			{
				if (cursor->right == nullptr)
				{
					return false;
				}
				cursor = cursor->right;
			}
		}
		return true;
	}
	return false;
}

char* getValue(Tree* tree, int keyToReturn)
{
	TreeElement* cursor = tree->head;
	if (cursor != nullptr)
	{
		while (keyToReturn != cursor->key)
		{
			if (keyToReturn < cursor->key)
			{
				if (cursor->left == nullptr)
				{
					return nullptr;
				}
				cursor = cursor->left;
			}
			else if (keyToReturn > cursor->key)
			{
				if (cursor->right == nullptr)
				{
					return nullptr;
				}
				cursor = cursor->right;
			}
		}
		return cursor->value;
	}
	return nullptr;

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

void deleteTree(Tree* tree)
{
	if (tree->head == nullptr)
	{
		delete tree;
	}
	deleteTreeElement(tree->head);
	delete tree;
}