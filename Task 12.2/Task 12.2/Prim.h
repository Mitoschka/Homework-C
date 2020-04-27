#pragma once

const int maxNumberOfNodes = 20;

void readGraphFromFile(char path[], int* numbOfNodes, int graph[maxNumberOfNodes][maxNumberOfNodes]);

void buildMinSpanningTree(int numbOfNodes, int graph[maxNumberOfNodes][maxNumberOfNodes], int spanningTree[maxNumberOfNodes][maxNumberOfNodes]);

void printGraph(int numbOfNodes, int spanningTree[maxNumberOfNodes][maxNumberOfNodes]);
