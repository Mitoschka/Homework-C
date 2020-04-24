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