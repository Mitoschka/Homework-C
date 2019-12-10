#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node* next;
};

bool search(node* list, int data)
{
	node* ptr = list;
	while (ptr != NULL)
	{
		if (ptr->data == data)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}


node* list(int a)
{
	node* head = new node;
	head->data = a;
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
	printReversed(node);
	return 0;
}