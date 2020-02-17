#include "BinaryTree.h"
#include <stdio.h>

Node *addNode(Node *tree, int key, char *value) 
{
	//добавление узлов в древо
	if (tree == NULL)
	{//если дерева нет, то формируем корень
		tree = (Node*)malloc(sizeof(Node));//память под узел
		tree->key = key;//ключ
		tree->item = strdup(value);//поле данных
		//инициализация ветвей пустыми
		tree->left = NULL;
		tree->right = NULL;
	}
	//определяем ветвь для вставки данных
	//один и тот же ключ, заменим значение
	else if (key == tree->key)
	{
		tree->item = strdup(value);//поле данных
	}

	//вставим в левую или правую ветви
	else if (key < tree->key)
	{
		tree->left = addNode(tree->left, key, value);
	}
	else
	{
		tree->right = addNode(tree->right, key, value);
	}
	return tree;
}

Node* searchByKey(Node* tree, int key)
{//поиск узла по заданному ключу
	Node *found = NULL;
	if (tree == NULL)
	{
		return tree;
	}
	//узел найден по ключу
	if (key == tree->key)
	{
		found = tree;
		return found;
	}
	//выбор направления поиска по ключу
	else if (key < tree->key && tree->left != NULL)
	{
		found = searchByKey(tree->left, key);
	}
	else if (key > tree->key && tree->right != NULL)
	{
		found = searchByKey(tree->right, key);
	}
	//ключ не найден
	return found;
}


Node* findMin(Node* localeNode) // поиск узла с минимальным ключом в дереве p 
{
	return localeNode->left ? findMin(localeNode->left) : localeNode; //если есть левый сын, идем в него иначе ответ в этой вершине
}

Node* removeMin(Node* localeNode)
{//удаление узла с минимальным ключом из дерева p
	//если нет левого сына удалим эту вершину
	if (localeNode->left == NULL)
	{
		return localeNode->right;
	}
	localeNode->left = removeMin(localeNode->left); // иначе идем в левого сына
	return localeNode;
}

Node* removeByKey(Node* tree, int key)
{//удаление узла из древа по ключу key
	// если дерево пустое, уходим
	if (!tree)
	{
		return NULL;
	}
	//если элемент меньше вершины идем в левого сына
	if (key < tree->key)
	{
		tree->left = removeByKey(tree->left, key);
	}
	//если элемент больше вершины, идем в правого сына
	else if (key > tree->key)
	{
		tree->right = removeByKey(tree->right, key);
	}
	else
	{//мы пришли в вершину, которую нужно удалить		
		Node* nodeLeft= tree->left;
		Node* nodeRight = tree->right;
		free(tree);//физическое удаление вершины	
		printf("Запись удалена...\n");
		if (!nodeRight)
		{
			return nodeLeft;
		}
		Node* min = findMin(nodeRight);
		min->right = removeMin(nodeRight); //правый сын минимальной вершины - это правое поддерево удаляемой без минимума
		min->left = nodeLeft; //левый сын минимальной вершины - левый сын удаляемой
		return min;
	}
	return tree; 
}

void freeTree(Node* tree) 
{
	//освобождение памяти в каждом узле древа
	if (tree->left)
	{
		freeTree(tree->left);
	}
	if (tree->right)
	{
		freeTree(tree->right);
	}
	free(tree);
}