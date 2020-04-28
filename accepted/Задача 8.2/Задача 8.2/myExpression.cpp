#include "myExpression.h"
#include "myTree.h"

int resultOfExpression(MyTree* tree)
{
	return count(getHead(tree));
}