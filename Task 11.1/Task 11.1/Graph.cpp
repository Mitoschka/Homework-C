#include "Graph.h"

struct GraphEdges
{
	GraphEdges()
	{
		nodes = new int[1];
		sizeOfNodes = 0;
		weights = new int[1];
	}

	int* nodes;
	int sizeOfNodes;
	int* weights;
};

GraphEdges** createGraph(int maxNumbersOfTown)
{
	return new GraphEdges * [maxNumbersOfTown];
}

void initGraphs(GraphEdges** graph, int actualnumberOfCities)
{
	for (int i = 0; i != actualnumberOfCities; ++i)
	{
		graph[i] = new GraphEdges();
	}
}

int getSize(GraphEdges* graph)
{
	return graph->sizeOfNodes;
}

int getNode(GraphEdges* graph, int index)
{
	return graph->nodes[index];
}

int getWeight(GraphEdges* graph, int index)
{
	return graph->weights[index];
}

void addToGraph(GraphEdges* graph, int element, int weight)
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