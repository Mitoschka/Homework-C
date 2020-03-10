#include "myStack.h"
#include "myExpression.h"
#include "myTree.h"

void parseElement(char value, MyStack* stack)
{
	const char plus = '+';
	const char minus = '-';
	const char multiplication = '*';
	const char division = '/';

	if (value == plus || value == minus || value == multiplication || value == division)
	{
		int secondNumber = deleteElementFromStack(stack);
		int firstNumber = deleteElementFromStack(stack);
		int tempResult = 0;

		if (value == plus)
		{
			tempResult = firstNumber + secondNumber;
			addElementInStack(stack, tempResult);
			return;
		}

		if (value == minus)
		{
			tempResult = firstNumber - secondNumber;
			addElementInStack(stack, tempResult);
			return;
		}

		if (value == multiplication)
		{
			tempResult = firstNumber * secondNumber;
			addElementInStack(stack, tempResult);
			return;
		}

		if (value == division)
		{
			tempResult = firstNumber / secondNumber;
			addElementInStack(stack, tempResult);
			return;
		}
	}
	else
	{
		int valueToInt = value - '0';
		addElementInStack(stack, valueToInt);
	}
}

void putElementFromTreeToStack(TreeElement* treeElement, MyStack* stack)
{
	if (treeElement->left != nullptr)
	{
		putElementFromTreeToStack(treeElement->left, stack);
	}

	if (treeElement->right != nullptr)
	{
		putElementFromTreeToStack(treeElement->right, stack);
	}

	parseElement(treeElement->value, stack);
}

int resultOfExpression(MyTree* tree)
{
	MyStack* stack = createStack();
	putElementFromTreeToStack(tree->head, stack);
	int result = deleteElementFromStack(stack);

	deleteStack(stack);

	return result;
}