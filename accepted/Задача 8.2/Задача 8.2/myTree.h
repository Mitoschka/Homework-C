#pragma once

struct MyTree;

// Создание дерева
MyTree* createTree();

// Добавление элемента в дерево
void addElementInTree(MyTree* tree, char newValue);

// Вывод дерева на экран
void printTree(MyTree* tree);

// Поместить выражение в дерево
void putExpressionToTree(MyTree* tree, char expression[]);

// Удаление дерева
void deleteTree(MyTree* tree);