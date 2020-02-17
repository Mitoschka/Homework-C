#pragma once

typedef struct BinaryTree
{
	int key;//ключ
	char *item;//поле данных
	struct tree *left;//левый потомок
	struct tree *right;//правый потомок
} Node;

Node *addNode(Node *tree, int key, char *value);

Node* searchByKey(Node* tree, int key);

Node* removeByKey(Node* tree, int key);

void freeTree(Node* tree);