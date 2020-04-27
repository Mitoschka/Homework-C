#include "MyStack.h"

struct StackElement
{
	char symbol = ' ';
	StackElement *next = nullptr;
};

struct MyStack
{
	StackElement *head = nullptr;
};

MyStack* createStack()
{
	MyStack * stack = new MyStack;
	return stack;
}

void pushToStack(MyStack *stack, char symbol)
{
	StackElement *newElement = new StackElement;
	newElement->symbol = symbol;
	newElement->next = stack->head;
	stack->head = newElement;
}

char headOfStack(MyStack *stack)
{
	return stack->head->symbol;
}

bool isStackEmpty(MyStack *stack)
{
	return (stack->head == nullptr);
}

char popFromStack(MyStack *stack)
{
	char symbol = stack->head->symbol;
	StackElement *temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
	return symbol;
}

void deleteStack(MyStack *stack)
{
	while (stack->head != nullptr)
	{
		StackElement *temp = stack->head->next;
		delete stack->head;
		stack->head = temp;
	}

	delete stack;
}

MyStack * reverseStack(MyStack *stack)
{
	MyStack * tempStack = createStack();
	while (stack->head != nullptr)
	{
		pushToStack(tempStack, popFromStack(stack));
	}
	deleteStack(stack);
	return tempStack;
}