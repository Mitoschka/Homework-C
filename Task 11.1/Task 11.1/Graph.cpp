#include "Graph.h"

const int maxSize = 1000;

struct GraphEdges
{
	GraphEdges()
	{
		nodes = new int[maxSize];
		sizeOfNodes = 0;
		weights = new int[maxSize];
	}

	int* nodes;
	int sizeOfNodes;
	int* weights;
};

GraphEdges** createGraph(int maxNumbersOfTown)
{
	return new GraphEdges * [maxNumbersOfTown];
}

void initEdges(GraphEdges** graph, int actualnumberOfCities)
{
	for (int i = 0; i != actualnumberOfCities; ++i)
	{
		graph[i] = new GraphEdges();
	}
}

int getSize(GraphEdges* edge)
{
	return edge->sizeOfNodes;
}

int getNode(GraphEdges* edge, int index)
{
	return edge->nodes[index];
}

int getWeight(GraphEdges* edge, int index)
{
	return edge->weights[index];
}

void addToGraph(GraphEdges* edge, int element, int weight)
{
	edge->nodes[edge->sizeOfNodes] = element;
	edge->weights[edge->sizeOfNodes] = weight;
	++edge->sizeOfNodes;
}

void deleteGraph(GraphEdges** graph, int size)
{
	for (int i = 0; i != size; ++i)
	{
		delete graph[i]->nodes;
		delete graph[i]->weights;
		delete graph[i];
	}

	delete[] graph;
}