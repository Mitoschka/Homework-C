#include <stdio.h>

char* bracketsCheck(const char* string)
{
	switch (*string)
	{
		case '\0':
		case ')':
		case '}':
		case ']':
		return (char*)string;
		case '(':
		{
			char* ret = bracketsCheck(string + 1);
			return (*ret == ')') ? bracketsCheck(ret + 1) : (char*)string;
		}
		case '{':
		{
			char* ret = bracketsCheck(string + 1);
			return (*ret == '}') ? bracketsCheck(ret + 1) : (char*)string;
		}
		case '[':
		{
			char* ret = bracketsCheck(string + 1);
			return (*ret == ']') ? bracketsCheck(ret + 1) : (char*)string;
		}
		default:
			return bracketsCheck(string + 1);
	}
}

bool test()
{
	const char test1[] = "((()";
	if (!bracketsCheck(test1))
	{
		return false;
	}

	const char test2[] = "(){}[]";
	if (!bracketsCheck(test2))
	{
		return false;
	}

	const char test3[] = "()))";
	if (!bracketsCheck(test3))
	{
		return false;
	}

	const char test4[] = "({)}";
	if (!bracketsCheck(test4))
	{
		return false;
	}

	const char test5[] = "[.](/)";
	if (!bracketsCheck(test5))
	{
		return false;
	}

	const char test6[] = "((()";
	if (!bracketsCheck(test6))
	{
		return false;
	}

	const char test7[] = "(}";
	if (!bracketsCheck(test7))
	{
		return false;
	}

	return true;
}

int main()
{
	if (!test())
	{
		printf("ERROR");
		return 1;
	}
	char buf[BUFSIZ];
	while (printf("String: ") && fgets(buf, BUFSIZ, stdin) && *buf != '\n')
	{
		printf("%s\n", (*bracketsCheck(buf)) ? "FAIL" : "OK");
	}
	return 0;
}