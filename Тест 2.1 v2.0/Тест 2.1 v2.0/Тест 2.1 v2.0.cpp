#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int const size = 1000;

struct node 
{
	int data;
	struct node* next;
};


node* list(int element)
{
	node* head = new node;
	head->data = element;
	head->next = NULL;
	return (head);
}

node* add(node* head, int val)
{
	node* temp, * p;
	p = head->next;
	temp = new node;
	head->next = temp;
	temp->data = val;
	temp->next = p;
	return (temp);
}

void openFile()
{
	FILE* file = fopen("file.txt", "r");
	if (file == nullptr)
	{
		file = fopen("file.txt", "w");
		fclose(file);
		file = fopen("file.txt", "r");
	}
}

void printFromFile(FILE* file)
{
	openFile();
	char string[size];
	int numOfLines = 0;
	if ((file = fopen("file.txt", "r")) == nullptr)
	{
		printf("error\n");
	}
	else
	{
		while (fgets(string, size, file))
		{
			printf("%s", string);
			numOfLines++;
		}
	}
	printf("Количество строк: %d\n", numOfLines);
	fclose(file);
	printf("Все данные были распечатаны\n");
}

bool search(node* list, int data)
{
	node* ptr = list;
	while (ptr != nullptr)
	{
		if (ptr->data == data)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

void printReversed(struct node* node)
{
	if (node != nullptr)
	{
		printReversed(node->next);
		printf("%d\n", node->data);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* file = fopen("file.txt", "r+t");
	printFromFile(file);
	int N = 0;
	int data = 0;
	for (int i = 0; i < N; i++)
	{
		printf("Input %i element", i + 1);
		node* data = (node*)malloc(sizeof(node));
		scanf("%d", data);
		add(data, i);
	}
	int result = 0;
	result = printReversed(node);
	printf("\n\nResult: %d\n", result);
	return 0;
}