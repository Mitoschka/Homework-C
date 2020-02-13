#pragma once


typedef struct BinartTree
{
	int count;//число вхождений
	char *key, *item;//ключи и поле данных
	unsigned char height; //высота поддерева
	struct tree *left;//левый потомок
	struct tree *right;//правый потомок
} Node;

unsigned char height(Node* tNode);

int bfactor(Node* tNode);

void fixheight(Node* tNode);

Node* rotateright(Node* tNode);

Node* rotateleft(Node* tNode);

Node* balance(Node* tNode);

Node *addNode(Node *tree, char *key, char *value);

Node* searchByKey(Node* tree, char *key);

Node* findmin(Node* tNode);

Node* removemin(Node* tNode);

Node* removeByKey(Node* tree, char *key);