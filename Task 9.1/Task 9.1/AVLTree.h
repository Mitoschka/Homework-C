#pragma once

struct Tree;

struct TreeElement;

// Создать дерева.
Tree* createTree();

// Вернуть голову дерева.
TreeElement* getHead(Tree* tree);

// Установить новое значение в голову дерева.
void newHead(Tree* tree, TreeElement* newHead);

// Добавить элемент в дерево.
TreeElement* addElementToTree(Tree* tree, TreeElement* treeElement, int newKey, char newValue[]);

TreeElement* removeElementFromTree(TreeElement* treeElement, int keyToDelete);

// Проверить, находится ли элемент в дереве.
bool isContain(Tree* tree, int keyToChecked);

// Вернуть значение по ключу.
char* getValue(Tree* tree, int keyToReturn);

// Удалить дерево.
void deleteTree(Tree* tree);
