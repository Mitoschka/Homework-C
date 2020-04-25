#pragma once
#include "Graph.h"

//Проанализировать данные из файла.
void parseData(char path[], GraphEdges** graph, List** citiesInfo, bool isCityInCountry[], int* numberOfCapitals, int* numberOfCities);

//Запустить алгоритм, который будет содержать информацию о столицах в citiesInfo.
void runAlgorithm(int numberOfCapitals, int maxWeight, List** citiesInfo, bool isCityInCountry[], GraphEdges** graph);