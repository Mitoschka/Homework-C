#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data;
	struct Node* next;
};


void printList(Node* head)
{
	Node* ptr = head;
	printf("\n[ ");
	while (ptr != nullptr)
	{
		printf("(%d) ", ptr->data);
		ptr = ptr->next;
	}
	printf(" ]\n");
}

int length(Node* head)
{
	int length = 0;
	Node* current;
	for (current = head; current != nullptr; current = current->next)
	{
		length++;
	}
	return length;
}

void reverse(Node** headRef)
{
	if (length(*headRef) < 2)
	{
		return;
	}
	Node* prev = nullptr;
	Node* current = *headRef;
	while (current != nullptr)
	{
		Node* next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*headRef = prev;
}

Node* insertFirst(int data, Node* head)
{
	Node* link = (struct Node*) malloc(sizeof(Node));
	reverse(&head);
	link->data = data;
	link->next = head;
	reverse(&link);
	return link;
}

struct Node* deleteFirst(Node* head)
{
	Node* tempLink = head;
	head = head->next;
	free(tempLink);
	return head;
}

bool isEmpty(Node* head)
{
	return head == nullptr;
}

bool isDelimetr(char symbol)
{
	return symbol == ' ';
}

bool isOperation(char symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%';
}

int priority(char operation)
{
	return
		operation == '+' || operation == '-' ? 2 :
		operation == '*' || operation == '/' || operation == '%' ? 1 :
		3;
}

bool isNum(char symbol)
{
	return '0' <= symbol && symbol <= '9';
}

Node* processOperation(Node* list, char operation)
{
	int rightOperand = list->data;
	list = deleteFirst(list);
	int leftOperand = list->data;
	list = deleteFirst(list);
	printf("%d %c %d\n", leftOperand, operation, rightOperand);

	switch (operation)
	{
	case '+':  list = insertFirst(leftOperand + rightOperand, list); break;
	case '-':  list = insertFirst(leftOperand - rightOperand, list); break;
	case '*':  list = insertFirst(leftOperand * rightOperand, list); break;
	case '/':  list = insertFirst(leftOperand / rightOperand, list); break;
	case '%':  list = insertFirst(leftOperand % rightOperand, list); break;
	}
	return list;
}

bool testDelim(char symbol, bool result)
{
	return isDelimetr(symbol) == result;
}

bool testIsOperation(char symbol, bool result)
{
	return isOperation(symbol) == result;
}

bool testIsNum(char symbol, bool result)
{
	return isNum(symbol) == result;
}

bool testPriority(char symbol, int result)
{
	return priority(symbol) == result;
}

int main()
{
	if (!testDelim(' ', true) && !testDelim('1', false))
	{
		printf("error1");
		return 2;
	}
	if (!testIsOperation('+', true) && !testIsOperation('1', false))
	{
		printf("error2");
		return 2;
	}
	if (!testIsNum('1', true) && !testIsNum('a', false))
	{
		printf("error3");
		return 2;
	}
	if (!testPriority('+', 2) && !testPriority('*', 1), !testPriority('^', 3))
	{
		printf("error");
		return 2;
	}
	printf("Enter expressions in postfix form: \n");
	Node* headNumber = nullptr;
	char* element = (char*)malloc(sizeof(char));
	fgets(element, BUFSIZ, stdin);
	for (int i = 0; i < strlen(element); i++)
	{
		if (!isDelimetr(element[i]))
		{
			if (isOperation(element[i]))
			{
				headNumber = processOperation(headNumber, element[i]);
			}
			else
			{
				int start = i;
				while (i < strlen(element) && isNum(element[i]))
				{
					i++;
				}
				char* operand = (char*)malloc(sizeof(char) * (i - start));
				memcpy(operand, &element[start], i - start);
				reverse(&headNumber);
				headNumber = insertFirst(atoi(operand), headNumber);
				reverse(&headNumber);
				free(operand);
			}
		}
	}
	free(element);
	headNumber = deleteFirst(headNumber);
	printf("\n%d\n", headNumber->data);
	return 0;
}