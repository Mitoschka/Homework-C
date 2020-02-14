#pragma once


typedef struct BinaryTree
{
	int count;//число вхождений
	int key;//ключ
	char *item;//поле данных
	unsigned char height; //высота поддерева
	struct tree *left;//левый потомок
	struct tree *right;//правый потомок
} Node;



Node *addNode(Node *tree, int key, char *value);

Node* searchByKey(Node* tree, int key);

Node* findMin(Node* localeNode);

Node* removeMin(Node* localeNode);

Node* removeByKey(Node* tree, int key);

void freeTree(Node* tree);