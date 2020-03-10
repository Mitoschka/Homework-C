#pragma once

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

void initList(List* list, int numberOfElements);

ListElement* getHead(List* list);