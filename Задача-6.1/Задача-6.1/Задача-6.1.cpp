#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
	char* data;
	struct node* next;
};


void printList(node* head) 
{
	struct node* ptr = head;
	printf("\n[ ");
	while (ptr != nullptr) 
	{
		printf("(%s) ", ptr->data);
		ptr = ptr->next;
	}
	printf(" ]\n");
}

node* insertFirst(char* data, node* head) 
{
	struct node* link = (struct node*) malloc(sizeof(node));
	link->data = data;
	link->next = head;
	return link;
}

struct node* deleteFirst(node* head) 
{
	struct node* tempLink = head;
	head = head->next;
	return head;
}

bool isEmpty(node* head) 
{
	return head == nullptr;
}

int length(node* head) 
{
	int length = 0;
	struct node* current;
	for (current = head; current != nullptr; current = current->next) 
	{
		length++;
	}
	return length;
}

void reverse(struct node** headRef) 
{
	if (length(*headRef) < 2) 
	{
		return;
	}
	struct node* prev = nullptr;
	struct node* current = *headRef;
	struct node* next;
	while (current != nullptr) 
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*headRef = prev;
}


bool delim(char symbol) 
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

node* processOperation(node* list, char operation) 
{
	int leftOperand = atoi(list->data);
	list = deleteFirst(list);
	int rightOperand = atoi(list->data);
	list = deleteFirst(list);
	printf("%d %c %d\n", leftOperand, operation, rightOperand);
	char* tmpNum = new char[100];
	switch (operation) 
	{
		case '+':  sprintf(tmpNum, "%d", leftOperand + rightOperand);	break;
		case '-':  sprintf(tmpNum, "%d", leftOperand - rightOperand);	break;
		case '*':  sprintf(tmpNum, "%d", leftOperand * rightOperand);	break;
		case '/':  sprintf(tmpNum, "%d", leftOperand / rightOperand);	break;
		case '%':  sprintf(tmpNum, "%d", leftOperand % rightOperand);	break;
	}
	reverse(&list);
	list = insertFirst(tmpNum, list);
	reverse(&list);
	return list;
}

bool testDelim(char symbol, bool result)
{
	return delim(symbol) == result;
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
	struct node* headNumber = nullptr;
	struct node* headOperation = nullptr;
	char* element = new char[1];
	fgets(element, BUFSIZ, stdin);
	for (int i = 0; i < strlen(element); i++)
	{
		if (!delim(element[i])) 
		{
			if (isOperation(element[i])) 
			{
				while (!isEmpty(headOperation) && priority(headOperation->data[0]) >= priority(element[i]))
				{
					reverse(&headOperation);
					headNumber = processOperation(headNumber, headOperation->data[0]);

					headOperation = deleteFirst(headOperation);
					reverse(&headOperation);
				}
				char* curop = new char[1];
				memcpy(curop, &element[i], 1);
				headOperation = insertFirst(curop, headOperation);
			}
			else
			{
				int start = i;
				while (i < strlen(element) && isNum(element[i]))
				{
					i++;
				}
				char* operand = new char[i - start];
				memcpy(operand, &element[start], i - start);
				reverse(&headNumber);
				headNumber = insertFirst(operand, headNumber);
				reverse(&headNumber);
			}
		}
	}
	reverse(&headOperation);
	char* result = new char [1];
	while (!isEmpty(headOperation))
	{
		headNumber = processOperation(headNumber, headOperation->data[0]);
		headNumber = deleteFirst(headNumber);
		result = headNumber->data;
		headOperation = deleteFirst(headOperation);
	}
	printf("\n%s\n", result);
	return 0;
}
