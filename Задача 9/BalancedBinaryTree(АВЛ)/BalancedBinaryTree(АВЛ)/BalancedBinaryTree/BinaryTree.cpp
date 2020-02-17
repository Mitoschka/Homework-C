#include "BinaryTree.h"
#include <stdio.h>


unsigned char height(Node* localeNode) //получение высоты вершины
{//если вершины нет, ответ 0 иначе высота поддерева этой вершины
	return localeNode ? localeNode->height : 0;
}

int difference(Node* localeNode)
{//разность высот между сыновьями
	return height(localeNode->right) - height(localeNode->left); //вычисление разницы
}

void fixHeight(Node* localeNode)
{//обновим высоту, если сбалансированность нарушена
	unsigned char hleft = height(localeNode->left); //высота левого сына
	unsigned char hright = height(localeNode->right); //высота правого сына
	//высота вершины - это высота сына с макс высотой плюс 1
	localeNode->height = (hleft>hright ? hleft : hright) + 1;
}

Node* rotateRight(Node* localeNode) //правый поворот вокруг nd
{
	Node* temp = localeNode->left;
	localeNode->left = temp->right;
	temp->right = localeNode;
	fixHeight(localeNode);
	fixHeight(localeNode);
	free(temp);
	return localeNode;
}

Node* rotateLeft(Node* localeNode) //левый поворот вокруг nd
{
	Node* temp = localeNode->right;
	localeNode->right = temp->left;
	temp->left = localeNode;
	fixHeight(localeNode);
	fixHeight(temp);
	return temp;
}

Node* balance(Node* localeNode)
{//балансировка узла localeNode древа
	fixHeight(localeNode);
	if (difference(localeNode) == 2)
	{
		if (difference(localeNode->right) < 0)
		{
			localeNode->right = rotateRight(localeNode->right);
		}
		return rotateLeft(localeNode);
	}
	if (difference(localeNode) == -2)
	{
		if (difference(localeNode->left) > 0)
		{
			localeNode->left = rotateLeft(localeNode->left);
		}
		return rotateRight(localeNode);
	}
	return localeNode; //балансировка не нужна
}

Node *addNode(Node *tree, char *key, char *value) 
{
	//добавление узлов в древо
	int tSame = 0;//для выбора ветви
	if (tree != NULL)
	{
		tSame = strcmp(key, tree->key);
	}

	if (tree == NULL)
	{//если дерева нет, то формируем корень
		tree = (Node *)malloc(sizeof(Node));//память под узел
		tree->key = strdup(key);//ключ
		tree->item = strdup(value);//поле данных
		tree->count = 1;
		//инициализация ветвей пустыми
		tree->left = NULL;
		tree->right = NULL;
	}
	//определяем ветвь для вставки данных
	//один и тот же ключ, заменим значение
	else if (tSame == 0)
	{
		tree->count++;
		tree->item = strdup(value);//поле данных
	}

	//вставим в левую или правую ветви
	else if (tSame < 0)
	{
		tree->left = addNode(tree->left, key, value);
	}
	else
	{
		tree->right = addNode(tree->right, key, value);
	}
	return balance(tree);
}

Node* searchByKey(Node* tree, char *key)
{//поиск узла по заданному ключу
	int tSame;
	Node *found = NULL;
	if (tree == NULL)
	{
		return tree;
	}
	//узел найден по ключу
	if ((tSame = strcmp(key, tree->key)) == 0)
	{
		found = tree;
		return found;
	}
	//выбор направления поиска по ключу
	else if (tSame < 0 && tree->left != NULL)
	{
		found = searchByKey(tree->left, key);
	}
	else if (tSame > 0 && tree->right != NULL)
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
	if (localeNode->left == 0)
	{
		return localeNode->right;
	}
	localeNode->left = removeMin(localeNode->left); // иначе идем в левого сына
	return balance(localeNode); //балансируем дерево
}

Node* removeByKey(Node* tree, char *key)
{//удаление узла из древа по ключу key
	// если дерево пустое, уходим
	if (!tree)
	{
		return NULL;
	}
	int tSame = strcmp(key, tree->key);
	//если элемент меньше вершины идем в левого сына
	if (tSame < 0)
	{
		tree->left = removeByKey(tree->left, key);
	}
	//если элемент больше вершины, идем в правого сына
	else if (tSame > 0)
	{
		tree->right = removeByKey(tree->right, key);
	}
	else
	{//мы пришли в вершину, которую нужно удалить		
		Node* ndLeft = tree->left;
		Node* ndRight = tree->right;
		free(tree);//физическое удаление вершины	
		printf("Запись удалена...\n");
		if (!ndRight)
		{
			return ndLeft;
		}
		Node* min = findMin(ndRight);
		min->right = removeMin(ndRight); //правый сын минимальной вершины - это правое поддерево удаляемой без минимума
		min->left = ndLeft; //левый сын минимальной вершины - левый сын удаляемой
		return balance(min); //балансируем меньшую вершину
	}
	return balance(tree); //мы ничего не нашли, балансируем дерево
}

void freeTree(Node* tree) 
{
	//освобождение памяти в каждом узле древа
	if (tree == NULL) return;
	if (tree->left)   freeTree(tree->left);
	if (tree->right)  freeTree(tree->right);
	free(tree);
}