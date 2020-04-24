#include <iostream>

#include "Prim.h"

bool isCorrect()
{
	int testGraph[maxNumberOfNodes][maxNumberOfNodes] = {};
	int expectedSpanningTree[maxNumberOfNodes][maxNumberOfNodes] = {};
	int actualSpanningTree[maxNumberOfNodes][maxNumberOfNodes] = {};
	int numberOfNodes = 0;
	char pathTest[] = "testgraph.txt";
	char pathExpected[] = "expected.txt";
	readGraphFromFile(pathTest, &numberOfNodes, testGraph);
	readGraphFromFile(pathExpected, &numberOfNodes, expectedSpanningTree);

	buildMinSpanningTree(numberOfNodes, testGraph, actualSpanningTree);

	for (int i = 0; i != numberOfNodes; ++i)
	{
		for (int j = 0; j != numberOfNodes; ++j)
		{
			if (expectedSpanningTree[i][j] != actualSpanningTree[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isCorrect())
	{
		printf("test failed");
		return 1;
	}

	int graph[maxNumberOfNodes][maxNumberOfNodes] = {};
	int spanningTree[maxNumberOfNodes][maxNumberOfNodes] = {};
	int numberOfNodes = 0;

	char path[] = "graph.txt";
	readGraphFromFile(path, &numberOfNodes, graph);

	printf("Граф из файла: \n");

	printGraph(numberOfNodes, graph);

	buildMinSpanningTree(numberOfNodes, graph, spanningTree);

	printf("Минимальное остовное дерево: \n");

	printGraph(numberOfNodes, spanningTree);

	return 0;
}
/*
Мои тесты.
Вход:
5
0 3 4 0 1
3 0 5 0 0
4 5 0 2 6
0 0 2 0 7
1 0 6 7 0

Выход:
0 3 4 0 1
3 0 0 0 0
4 0 0 2 0
0 0 2 0 0
1 0 0 0 0

___________
Вход:
7
0 9 0 5 15 6 0
9 0 8 7 7 0 0
0 8 0 0 5 0 0
5 7 0 0 0 0 0
15 7 5 0 0 8 9
6 0 0 0 8 0 11
0 0 0 0 9 11 0

Выход:
0 0 0 5 0 6 0
0 0 0 7 7 0 0
0 0 0 0 5 0 0
5 7 0 0 0 0 0
0 7 5 0 0 0 9
6 0 0 0 0 0 0
0 0 0 0 9 0 0*/