#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void creatureTheFile(FILE* file)
{
	file = fopen("test.txt", "w");
	fclose(file);
}

void reverce()
{
	char string[100];//Будет содержать в себе предложение
	char buf[100];//Буффер строки str
	char** words;//Будет содержать в себе слова из str
	char* current;//Указатель на текущее слово в предложении
	char delimiter[] = " .,;!&";//Разделители между словами
	char chr;//Символьная переменная, для организации повторного ввода и т.д. 
	long nCount;//nCount - будет содержать в себе число слов 
	do
	{
		printf("Enter sentence :\n");
		scanf("%[^\n]%c", string, &chr);
		sprintf(buf, "%s", string);
		current = strtok(buf, delimiter);//Выделяем из строки 1-е слово
		nCount = 0;//Обнуляем счётчик слов 
		while (current)
		{
			nCount++;//Считаем слова
			//Продолжаем выделять из строки слова
			current = strtok(NULL, delimiter);
		}
		if (nCount == 0)
			printf("Input string is empty\n");
		else
		{
			nCount = 0;
			sprintf(buf, "%s", string);
			//Выделяем память на подстроки со словами из str
			words = (char**)malloc(nCount * sizeof(char*));
			//Заново разбиваем исходную строку на слова
			current = strtok(buf, delimiter);//Выделяем из строки 1-е слово
			while (current)
			{
				//Память под подстроку со словом
				words[nCount] = (char*)malloc(strlen(current) * sizeof(char));
				sprintf(words[nCount], "%s", current);
				//Продолжаем выделять из строки слова
				current = strtok(NULL, delimiter);
				nCount++;
			}
			printf("Sentence with reverse words\n");
			//А теперь выводим words в обратном порядке
			buf[0] = '\0';//В буф будем накапливать слова в обр порядке
			while (0 < (nCount--))
			{
				//printf("%s ",words[nCount]);
				strcat(buf, words[nCount]);
				strcat(buf, " ");
				//И удаляем память под уже не нужный нам элемент 
				words[nCount] = (char*)realloc(words[nCount], sizeof(char*));
			}
			//Снова уменьшаем память под 1 указатель
			words = (char**)realloc(words, sizeof(char*));
		}
		printf("%s\n", buf);
		printf("Enter 1 for new input\n");
		scanf("%d%c", &nCount, &chr);
		FILE* file;
		if ((file = fopen("test.txt", "w")) == nullptr)
		{
			printf("error\n");
		}
		else
		{
			fputs(buf,file);
			fclose(file);
			printf("All data has been printed\n");
		}
	} while (nCount == 1);
}


int main(FILE* file)
{
	creatureTheFile(file);
	reverce();
	return 0;
}
