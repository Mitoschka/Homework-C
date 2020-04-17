#include "MyList.h"
#include "WarAlgorithm.h"

int lastWarrior(int numberOfWarriors, int killedWarrior)
{
	List* list = createList();

	initList(list, numberOfWarriors);

	ListElement* listElement = beforeHeadElement(list);

	while (listElement != nextListElement(listElement)) //пока не наткнемся на элемент, который ссылается на себя, будем убивать
	{
		for (int i = 0; i != killedWarrior - 1; ++i)
		{
			listElement = nextListElement(listElement);
		}
		ListElement* tempListElement = nextListElement(listElement);
		changeNextToNextNext(listElement);
		delete tempListElement;
	}

	int result = valueOfListElement(listElement);
	delete listElement;

	delete list;

	return result;
}

//отдельная функция для теста функции, чтобы не копипастить в мейне
bool isLastWarriorCorrect(int numberOfWarriors, int killedWarrior, int correctLastWarrior)
{
	return lastWarrior(numberOfWarriors, killedWarrior) == correctLastWarrior;
}