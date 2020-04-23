#pragma once
#include "Graph.h"

//Проанализировать данные из файла.
void ParseData(char path[], Graph** graph, List** citiesInfo, bool isCityInCountry[], int* numberOfCapitals, int* numberOfCities);

//Запустить алгоритм, который будет содержать информацию о столицах в citiesInfo.
void RunAlgorithm(int numberOfCapitals, int maxWeight, List** citiesInfo, bool isCityInCountry[], Graph** graph);