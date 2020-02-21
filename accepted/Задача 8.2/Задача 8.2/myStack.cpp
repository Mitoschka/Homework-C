#include "myStack.h"

struct StackElement
{
	int value;
	StackElement* next;
};

struct MyStack
{
	StackElement* head = nullptr;
};

MyStack* createStack()
{
	MyStack* stack = new MyStack;
	return stack;
}

void addElementInStack(MyStack* stack, int value)
{
	StackElement* newElement = new StackElement;
	newElement->value = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

int deleteElementFromStack(MyStack* stack)
{
	int value = stack->head->value;
	StackElement* temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
	return value;
}

void deleteStack(MyStack* stack)
{
	while (stack->head != nullptr)
	{
		StackElement* temp = stack->head->next;
		delete stack->head;
		stack->head = temp;
	}

	delete stack;
}