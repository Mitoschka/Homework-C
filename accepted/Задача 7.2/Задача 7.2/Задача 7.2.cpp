#include <iostream>

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

int lastWarrior(int numberOfWarriors, int killedWarrior)
{
	List* list = new List;

	for (int i = numberOfWarriors; i != 0; --i) //делаем циклический список, каждое значение списка - порядковый номер воина
	{
		ListElement* listElement = new ListElement;
		listElement->value = i;
		listElement->next = list->head;
		list->head = listElement;
	}

	ListElement* listElement = new ListElement;
	listElement = list->head;

	while (listElement->next != nullptr)
	{
		listElement = listElement->next;
	}
	listElement->next = list->head;

	while (listElement != listElement->next) //пока не наткнемся на элемент, который ссылается на себя, будем убивать
	{
		for (int i = 0; i != killedWarrior - 1; ++i)
		{
			listElement = listElement->next;
		}
		ListElement* tempListElement = new ListElement;
		tempListElement = listElement->next;
		listElement->next = listElement->next->next;
		delete tempListElement;
	}

	int result = listElement->value;
	delete listElement;

	return result;
}

//отдельная функция для теста функции, чтобы не копипастить в мейне
bool isLastWarriorCorrect(int numberOfWarriors, int killedWarrior, int correctLastWarrior)
{
	return lastWarrior(numberOfWarriors, killedWarrior) == correctLastWarrior;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int testNumberOfWarriors = 11;
	int testKilledWarrior = 3;
	int correctLastWarrior = 7;

	if (!isLastWarriorCorrect(testNumberOfWarriors, testKilledWarrior, correctLastWarrior))
	{
		printf("Ошибка в тесте №1.\n");
		return 0;
	}

	testNumberOfWarriors = 8;
	testKilledWarrior = 1;
	correctLastWarrior = 8;

	if (!isLastWarriorCorrect(testNumberOfWarriors, testKilledWarrior, correctLastWarrior))
	{
		printf("Ошибка в тесте №2.\n");
		return 0;
	}

	testNumberOfWarriors = 1;
	testKilledWarrior = 32;
	correctLastWarrior = 1;

	if (!isLastWarriorCorrect(testNumberOfWarriors, testKilledWarrior, correctLastWarrior))
	{
		printf("Ошибка в тесте №3.\n");
		return 0;
	}

	int numberOfWarriors = -1;
	int killedWarrior = -1;

	while (numberOfWarriors <= 0 || killedWarrior <= 0)
	{
		printf("Количество воинов: ");
		scanf("%d", &numberOfWarriors);
		printf("Какого по счету воина в кругу убивают: ");
		scanf("%d", &killedWarrior);

		if (numberOfWarriors <= 0 || killedWarrior <= 0)
		{
			printf("Каждое из чисел должно быть больше 0.\n");
		}
	}

	printf("Выживший воин будет находиться на позиции %d.", lastWarrior(numberOfWarriors, killedWarrior));

	return 0;
}