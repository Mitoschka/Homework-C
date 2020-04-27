#include "Prim.h"

#include <stdio.h>

void readGraphFromFile(char path[], int* numberOfNodes, int graph[maxNumberOfNodes][maxNumberOfNodes])
{
	FILE* file = fopen(path, "r");

	int actualNumberOfNodes = 0;
	fscanf(file, "%d", &actualNumberOfNodes);
	*numberOfNodes = actualNumberOfNodes;

	for (int i = 0; i != actualNumberOfNodes; ++i)
	{
		for (int j = 0; j != actualNumberOfNodes; ++j)
		{
			fscanf(file, "%d", &graph[i][j]);
		}
	}

	fclose(file);
}

void buildMinSpanningTree(int numberOfNodes, int graph[maxNumberOfNodes][maxNumberOfNodes], int spanningTree[maxNumberOfNodes][maxNumberOfNodes])
{
	const int largeNumber = 100000;
	bool isNodeVisited[maxNumberOfNodes]{ false };
	isNodeVisited[0] = true;
	bool isNodeAdded = true;
	while (isNodeAdded)
	{
		isNodeAdded = false;
		int tempOutNode = -1;
		int tempInNode = -1;
		int tempMinimum = largeNumber;
		for (int i = 0; i != numberOfNodes; ++i)
		{
			if (isNodeVisited[i])
			{
				for (int j = 0; j != numberOfNodes; ++j)
				{
					if (!isNodeVisited[j] && tempMinimum > graph[i][j] && graph[i][j] != 0)
					{
						tempOutNode = i;
						tempInNode = j;
						tempMinimum = graph[i][j];
						isNodeAdded = true;
					}
				}
			}
		}
		if (isNodeAdded)
		{
			spanningTree[tempInNode][tempOutNode] = tempMinimum;
			spanningTree[tempOutNode][tempInNode] = tempMinimum;
			isNodeVisited[tempInNode] = true;
			isNodeVisited[tempOutNode] = true;
		}
	}
}

void printGraph(int numberOfNodes, int graph[maxNumberOfNodes][maxNumberOfNodes])
{
	for (int i = 0; i != numberOfNodes; ++i)
	{
		for (int j = 0; j != numberOfNodes; ++j)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}