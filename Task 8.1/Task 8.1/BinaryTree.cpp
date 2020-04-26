#include "BinaryTree.h"
#include <string.h>
#include <stdio.h>

const int maxSize = 20;

struct TreeElement
{
	int key = 0;
	char value[maxSize]{};
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

void addElementToTree(Tree* tree, int newKey, char newValue[])
{
	TreeElement* newElement = new TreeElement;
	newElement->key = newKey;
	strcpy(newElement->value, newValue);

	TreeElement* cursor = tree->head;
	if (cursor != nullptr)
	{
		while (true)
		{
			if (newKey == cursor->key)
			{
				strcpy(cursor->value, newValue);
				delete newElement;
				break;
			}
			if (newKey < cursor->key)
			{
				if (cursor->left == nullptr)
				{
					cursor->left = newElement;
					newElement->parent = cursor;
					break;
				}
				cursor = cursor->left;
			}
			else if (newKey > cursor->key)
			{
				if (cursor->right == nullptr)
				{
					cursor->right = newElement;
					newElement->parent = cursor;
					break;
				}
				cursor = cursor->right;
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		tree->head = newElement;
	}
}

TreeElement* minimumElement(TreeElement* treeElement)
{
	if (treeElement->left == nullptr)
	{
		return treeElement;
	}
	return minimumElement(treeElement->left);
}

TreeElement* next(TreeElement* treeElement)
{
	if (treeElement->right != nullptr)
	{
		return minimumElement(treeElement->right);
	}
	TreeElement* tempElement = treeElement->parent;
	while (tempElement != nullptr && treeElement == tempElement->right)
	{
		treeElement = tempElement;
		tempElement = tempElement->parent;
	}
	return tempElement;
}

TreeElement* deleteElementFromTree(TreeElement* treeElement, int keyToDelete)
{
	if (treeElement == nullptr)
	{
		return treeElement;
	}
	if (keyToDelete < treeElement->key)
	{
		treeElement->left = deleteElementFromTree(treeElement->left, keyToDelete);
	}
	else if (keyToDelete > treeElement->key)
	{
		treeElement->right = deleteElementFromTree(treeElement->right, keyToDelete);
	}
	else if (treeElement->left != nullptr && treeElement->right != nullptr)
	{
		TreeElement* tempElement = minimumElement(treeElement->right);
		treeElement->key = tempElement->key;
		strcpy(treeElement->value, tempElement->value);
		treeElement->right = deleteElementFromTree(treeElement->right, treeElement->key);
	}
	else
	{
		if (treeElement->left != nullptr)
		{
			treeElement = treeElement->left;
		}
		else if (treeElement->right != nullptr)
		{
			treeElement = treeElement->right;
		}
		else
		{
			treeElement = nullptr;
		}
	}
	return treeElement;
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
		return;
	}
	deleteTreeElement(tree->head);
}