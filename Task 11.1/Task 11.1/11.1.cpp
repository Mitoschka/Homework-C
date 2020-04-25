#include <iostream>

#include "MyList.h"
#include "Graph.h"
#include "CapitalsAlgorithm.h"

const int maxNumberOfCities = 1000;

const int maxLength = 1000;

const int maxNumberOfCapitals = 1000;

bool isCorrect()
{
	bool isCorrect = true;
	GraphEdges ** graph = createGraph(maxNumberOfCities);
	List ** citiesInfo = createArrayOfList(maxNumberOfCapitals);
	int numberOfCapitals = 0;
	int numberOfCities = 0;
	bool isCityInCountry[maxNumberOfCapitals]{ false };
	char path[] = "test.txt";

	parseData(path, graph, citiesInfo, isCityInCountry, &numberOfCapitals, &numberOfCities);
	runAlgorithm(numberOfCapitals, maxLength, citiesInfo, isCityInCountry, graph);

	citiesInfo[0] = reverseList(citiesInfo[0]);
	citiesInfo[1] = reverseList(citiesInfo[1]);

	if (valueFromElement(getHead(citiesInfo[0])) != 0 || valueFromElement(getHead(citiesInfo[1])) != 3)
	{
		printf("wrong capitals test");
		isCorrect = false;
	}

	if (numberOfElementsInList(citiesInfo[0]) != 3 || numberOfElementsInList(citiesInfo[1]) != 2)
	{
		printf("wrong number of cities test");
		isCorrect = false;
	}

	if (!isContain(citiesInfo[0], 1) || !isContain(citiesInfo[0], 2))
	{
		printf("wrong cities  of 1 capital test");
		isCorrect = false;
	}

	if (!isContain(citiesInfo[1], 4))
	{
		printf("wrong cities  of 2 capital test");
		isCorrect = false;
	}

	deleteGraph(graph, numberOfCities);

	deleteArrayOfList(citiesInfo, numberOfCapitals);

	return isCorrect;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isCorrect())
	{
		printf("Тест(ы) не пройден(ы)");
		return 1;
	}

	int numberOfCities = 0;
	int numberOfRoads = 0;

	GraphEdges ** graph = createGraph(maxNumberOfCities);
	List ** citiesInfo = createArrayOfList(maxNumberOfCapitals);
	int numberOfCapitals = 0;
	bool isCityInCountry[maxNumberOfCapitals]{ false };
	char path[] = "cities.txt";

	parseData(path, graph, citiesInfo, isCityInCountry, &numberOfCapitals, &numberOfCities);
	runAlgorithm(numberOfCapitals, maxLength, citiesInfo, isCityInCountry, graph);

	printf("Список государств со столицами: ");
	for (int i = 0; i != numberOfCapitals; ++i)
	{
		citiesInfo[i] = reverseList(citiesInfo[i]);
		printf("\nСтолица: %d", removeElementFromList(citiesInfo[i]));
		printf("\nГорода в составе государства: ");
		int numberOfRestTowns = numberOfElementsInList(citiesInfo[i]);
		for (int j = 0; j != numberOfRestTowns; ++j)
		{
			printf("%d ", removeElementFromList(citiesInfo[i]));
		}
	}

	deleteGraph(graph, numberOfCities);

	deleteArrayOfList(citiesInfo, numberOfCapitals);

	return 0;
}