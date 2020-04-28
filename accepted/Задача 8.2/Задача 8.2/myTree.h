#pragma once

struct TreeElement;

struct MyTree;

// Создание дерева
MyTree* createTree();

// Вернуть голову дерева.
TreeElement* getHead(MyTree* tree);

// Вернуть значение в элементе дерева.
char getValue(TreeElement* treeElement);

// Вернуть левого потомка.
TreeElement* getLeft(TreeElement* treeElement);

// Вернуть правого потомка.
TreeElement* getRight(TreeElement* treeElement);

// Добавление элемента в дерево
void addElementInTree(MyTree* tree, char newValue);

// Вывод дерева на экран
void printTree(MyTree* tree);

// Поместить выражение в дерево
void putExpressionToTree(MyTree* tree, char expression[]);

// Посчитать выражение по дереву.
int count(TreeElement* treeElement);

// Удаление дерева
void deleteTree(MyTree* tree);