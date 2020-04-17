#pragma once

struct ListElement;

struct List;

List* createList();

ListElement* createListElement();

ListElement* beforeHeadElement(List* list);

ListElement* nextListElement(ListElement* listElement);

int valueOfListElement(ListElement* listElement);

void initList(List* list, int numberOfElements);

void changeNextToNextNext(ListElement* listElement);

ListElement* getHead(List* list);

void deleteList(List* list);