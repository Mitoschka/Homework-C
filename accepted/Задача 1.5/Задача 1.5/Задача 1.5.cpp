#include <stdio.h>

char* brackets_check(const char* s) {
	switch (*s) {
	case '\0':
	case ')':
	case '}':
	case ']':
		return (char*)s;
	case '(': {
		char* ret = brackets_check(s + 1);
		return (*ret == ')') ? brackets_check(ret + 1) : (char*)s;
	}
	case '{': {
		char* ret = brackets_check(s + 1);
		return (*ret == '}') ? brackets_check(ret + 1) : (char*)s;
	}
	case '[': {
		char* ret = brackets_check(s + 1);
		return (*ret == ']') ? brackets_check(ret + 1) : (char*)s;
	}
	default:
		return brackets_check(s + 1);
	}
}

int main(void) {
	char buf[BUFSIZ];

	while (printf("String: ") && fgets(buf, BUFSIZ, stdin) && *buf != '\n')
		printf("%s\n", (*brackets_check(buf)) ? "FAIL" : "OK");

	return 0;
}