#pragma once

struct Tree;

struct TreeElement;

// Создать дерева.
Tree* createTree();

// Вернуть голову дерева.
TreeElement* getHead(Tree* tree);

// Добавить элемент в дерево.
void addElementToTree(Tree* tree, int newKey, char newValue[]);

// Удалить элемент из дерева.
TreeElement* deleteElementFromTree(TreeElement* treeElement, int keyToDelete);

// Проверить, находится ли элемент в дереве.
bool isContain(Tree* tree, int keyToChecked);

// Вернуть значение по ключу.
char* getValue(Tree* tree, int keyToReturn);

// Удалить дерево.
void deleteTree(Tree* tree);