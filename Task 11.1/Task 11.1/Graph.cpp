#include "Graph.h"

struct Graph
{
	Graph()
	{
		nodes = new int[1];
		sizeOfNodes = 0;
		weights = new int[1];
	}

	int* nodes;
	int sizeOfNodes;
	int* weights;
};

Graph** createGraph(int maxNumbersOfTown)
{
	return new Graph * [maxNumbersOfTown];
}

void initGraphs(Graph** graph, int actualnumberOfCities)
{
	for (int i = 0; i != actualnumberOfCities; ++i)
	{
		graph[i] = new Graph();
	}
}

int getSize(Graph* graph)
{
	return graph->sizeOfNodes;
}

int getNote(Graph* graph, int index)
{
	return graph->nodes[index];
}

int getWeight(Graph* graph, int index)
{
	return graph->weights[index];
}

void addToGraph(Graph* graph, int element, int weight)
{
	int* temporary = new int[graph->sizeOfNodes + 1];
	int* tempWeights = new int[graph->sizeOfNodes + 1];
	for (int i = 0; i != graph->sizeOfNodes; ++i)
	{
		temporary[i] = graph->nodes[i];
		tempWeights[i] = graph->weights[i];
	}
	temporary[graph->sizeOfNodes] = element;
	tempWeights[graph->sizeOfNodes] = weight;
	delete[] graph->nodes;
	delete[] graph->weights;
	graph->nodes = new int[graph->sizeOfNodes + 1];
	graph->weights = new int[graph->sizeOfNodes + 1];
	for (int i = 0; i != graph->sizeOfNodes + 1; ++i)
	{
		graph->nodes[i] = temporary[i];
		graph->weights[i] = tempWeights[i];
	}
	graph->sizeOfNodes = graph->sizeOfNodes + 1;
	delete[] temporary;
	delete[] tempWeights;
}

void deleteGraph(Graph** graph, int size)
{
	for (int i = 0; i != size; ++i)
	{
		delete graph[i]->nodes;
		delete graph[i]->weights;
		delete graph[i];
	}

	delete[] graph;
}