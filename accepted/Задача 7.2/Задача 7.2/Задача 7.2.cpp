#include <iostream>
#include "MyList.h"
#include "WarAlgorithm.h"

bool isCorrect()
{
	int testNumberOfWarriors = 11;
	int testKilledWarrior = 3;
	int correctLastWarrior = 7;

	if (!isLastWarriorCorrect(testNumberOfWarriors, testKilledWarrior, correctLastWarrior))
	{
		printf("Ошибка в тесте №1.\n");
		return false;
	}

	testNumberOfWarriors = 8;
	testKilledWarrior = 1;
	correctLastWarrior = 8;

	if (!isLastWarriorCorrect(testNumberOfWarriors, testKilledWarrior, correctLastWarrior))
	{
		printf("Ошибка в тесте №2.\n");
		return false;
	}

	testNumberOfWarriors = 1;
	testKilledWarrior = 32;
	correctLastWarrior = 1;

	if (!isLastWarriorCorrect(testNumberOfWarriors, testKilledWarrior, correctLastWarrior))
	{
		printf("Ошибка в тесте №3.\n");
		return false;
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isCorrect())
	{
		printf("Тесты не пройдены.");
		return 0;
	}

	int numberOfWarriors = -1;
	int killedWarrior = -1;

	while (numberOfWarriors <= 0 || killedWarrior <= 0)
	{
		printf("Количество воинов: ");
		scanf_s("%d", &numberOfWarriors);
		printf("Какого по счету воина в кругу убивают: ");
		scanf_s("%d", &killedWarrior);

		if (numberOfWarriors <= 0 || killedWarrior <= 0)
		{
			printf("Каждое из чисел должно быть больше 0.\n");
		}
	}

	printf("Выживший воин будет находиться на позиции %d.", lastWarrior(numberOfWarriors, killedWarrior));

	return 0;
}