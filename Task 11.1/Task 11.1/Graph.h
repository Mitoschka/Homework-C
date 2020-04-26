#pragma once

struct GraphEdges;

//Создание графа.
GraphEdges** createGraph(int maxNumbersOfTown);

//Инициализация графа.
void initEdges(GraphEdges** graph, int actualNumberOfCities);

//Добавление элемента с весом.
void addToGraph(GraphEdges* edge, int element, int weight);

int getSize(GraphEdges* edge);

int getNode(GraphEdges* edge, int index);

int getWeight(GraphEdges* edge, int index);

// Удаление графа.
void deleteGraph(GraphEdges** graph, int size);