#pragma once

struct GraphEdges;

//Создание графа.
GraphEdges** createGraph(int maxNumbersOfTown);

//Инициализация графа.
void initGraphs(GraphEdges** graph, int actualNumberOfCities);

//Добавление элемента с весом.
void addToGraph(GraphEdges* graph, int element, int weight);

int getSize(GraphEdges* graph);

int getNode(GraphEdges* graph, int index);

int getWeight(GraphEdges* graph, int index);

// Удаление графа.
void deleteGraph(GraphEdges** graph, int size);