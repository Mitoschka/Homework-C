#include <stdio.h>
#include <malloc.h>

typedef struct node 
{
	struct node* next;
	int val;
	unsigned int cnt;
} slist;

int  slistAdd(slist** lst, int val);
void slistClear(slist* lst);
slist* slistInput(FILE* _in);

int main(void) {
	const slist* element;
	slist* lst;

	printf("Enter: \n");
	lst = slistInput(stdin);

	for (element = lst; element != NULL; element = element->next)
	{
		printf("Element - %d; repeated %u times\n", element->val, element->cnt);
	}
	slistClear(lst);
	return 0;
}

//ввод
slist* slistInput(FILE* _in) 
{
	int val = 0;
	slist* lst = NULL;
	while ((fscanf(_in, "%d", &val) == 1) && !ferror(_in)) 
	{
		if (val == 0)
		{
			break;
		}
		slistAdd(&lst, val);
	}
	return lst;
}

//добавление
int slistAdd(slist** lst, int val) 
{
	slist* nextElement = NULL;
	slist* element = *lst;
	slist* memory = *lst;
	while ((element != NULL) && (element->val <= val)) 
	{
		if (element->val == val) 
		{
			element->cnt += 1;
			return 1;
		}
		memory = element;
		element = element->next;
	}

	nextElement = (slist*)malloc(sizeof(slist));
	if (nextElement == NULL)
	{
		return 0;
	}
	nextElement->val = val;
	nextElement->cnt = 1;

	if (*lst == element) 
	{
		nextElement->next = *lst;
		*lst = nextElement;
	}
	else 
	{
		memory->next = nextElement;
		nextElement->next = element;
	}
	return 1;
}

//очистка
void slistClear(slist* lst) 
{
	slist* memory;
	while (lst != NULL) 
	{
		memory = lst;
		lst = lst->next;
		free(memory);
	}
}