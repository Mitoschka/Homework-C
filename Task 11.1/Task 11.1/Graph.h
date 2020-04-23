#pragma once

struct Graph;

//Создание графа.
Graph** createGraph(int maxNumbersOfTown);

//Инициализация графа.
void initGraphs(Graph** graph, int actualnumberOfCities);

//Добавление элемента с весом.
void addToGraph(Graph* graph, int element, int weight);

int getSize(Graph* graph);

int getNote(Graph* graph, int index);

int getWeight(Graph* graph, int index);

// Удаление графа.
void deleteGraph(Graph** graph, int size);