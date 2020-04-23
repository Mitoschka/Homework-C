#include "Graph.h"
#include "MyList.h"

#include <stdio.h>

void ParseData(char path[], Graph** graph, List** citiesInfo, bool isCityInCountry[], int* numberOfCapitals, int* numberOfCities)
{
	FILE* file = fopen(path, "r");
	int actualnumberOfCities = 0;
	int numberOfRoads = 0;
	fscanf(file, "%d%d", &actualnumberOfCities, &numberOfRoads);
	initGraphs(graph, actualnumberOfCities);
	*numberOfCities = actualnumberOfCities;

	for (int i = 0; i != numberOfRoads; ++i)
	{
		int inNote = 0;
		int outNote = 0;
		int weight = 0;
		fscanf(file, "%d%d%d", &inNote, &outNote, &weight);
		addToGraph(graph[inNote], outNote, weight);
		addToGraph(graph[outNote], inNote, weight);
	}

	const int maxNumberOfCapitals = 1000;
	int actualNumberOfCapitals = 0;

	fscanf(file, "%d", &actualNumberOfCapitals);

	for (int i = 0; i != actualNumberOfCapitals; ++i)
	{
		citiesInfo[i] = createList();
		int capital = 0;
		fscanf(file, "%d", &capital);
		addElementInList(citiesInfo[i], capital);
		isCityInCountry[capital] = true;
	}
	fclose(file);
	*numberOfCapitals = actualNumberOfCapitals;
}

void RunAlgorithm(int numberOfCapitals, int maxWeight, List** citiesInfo, bool isCityInCountry[], Graph** graph)
{
	bool isCityAdded = true;
	while (isCityAdded)
	{
		isCityAdded = false;
		for (int i = 0; i != numberOfCapitals; ++i)
		{
			int tempMinWeight = maxWeight;
			int tempCity = -1;
			ListElement* cursor = getHead(citiesInfo[i]);
			while (cursor != nullptr)
			{
				for (int k = 0; k != getSize(graph[valueFromElement(cursor)]); ++k)
				{
					if (!isCityInCountry[getNote(graph[valueFromElement(cursor)], k)] && getWeight(graph[valueFromElement(cursor)], k) < tempMinWeight)
					{
						tempMinWeight = getWeight(graph[valueFromElement(cursor)], k);
						tempCity = getNote(graph[valueFromElement(cursor)], k);
					}
				}
				cursor = getNext(cursor);
			}
			if (tempCity != -1)
			{
				addElementInList(citiesInfo[i], tempCity);
				isCityInCountry[tempCity] = true;
				isCityAdded = true;
			}
		}
	}
}