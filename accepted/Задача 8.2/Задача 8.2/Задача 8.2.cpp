﻿#include <iostream>
#include <fstream>
#include <string>

#include "myTree.h"
#include "myExpression.h"

using namespace std;

const int maxSize = 100;

bool isTest1Correct()
{
	MyTree* tree = createTree();
	char expression[maxSize] = { '*',' ', '(', '/', '(', '+', '9', '3', ')', ' ', '(', '+', '2', '2', ')', ')', '(', '-', '7', '4', ')' };
	int correctAnswer = 9;
	putExpressionToTree(tree, expression);
	bool isCorrect = correctAnswer == resultOfExpression(tree);
	deleteTree(tree);
	return isCorrect;
}

bool isTest2Correct()
{
	MyTree* tree = createTree();
	char expression[maxSize] = { '4' };
	int correctAnswer = 4;
	putExpressionToTree(tree, expression);
	bool isCorrect = correctAnswer == resultOfExpression(tree);
	deleteTree(tree);
	return isCorrect;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isTest1Correct())
	{
		printf("Тест 1 не пройден.");
		return 0;
	}

	if (!isTest2Correct())
	{
		printf("Тест 2 не пройден.");
		return 0;
	}

	MyTree* tree = createTree();
	char expression[maxSize];
	FILE* file;
	errno_t err = fopen_s(&file, "expression.txt", "r");
	if (err != 0)
	{
		printf("Ошибка открытия файла.");
		deleteTree(tree);
		return 0;
	}
	fgets(expression, sizeof(expression), file);
	err = fclose(file);
	if (err != 0)
	{
		printf("Ошибка закрытия файла.");
		deleteTree(tree);
		return 0;
	}

	putExpressionToTree(tree, expression);

	printf("Выражение из файла: ");
	printTree(tree);
	printf("\n");

	printf("Значение выражения: %d", resultOfExpression(tree));

	deleteTree(tree);

	return 0;
}