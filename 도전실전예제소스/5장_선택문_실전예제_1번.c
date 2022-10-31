#include <stdio.h>

int main()
{
	int num1, num2, res;
	char op;
	printf("사칙 연산 입력(정수) : ");
	scanf("%d%c%d", &num1, &op, &num2);
	if (op == '+') {
		res = num1 + num2;
	}
	else if (op == '-') {
		res = num1 - num2;
	}
	else if (op == '*') {
		res = num1 * num2;
	}
	else if (op == '/') {
		res = num1 / num2;
	}

	switch(op) {
	case '+':
		res = num1 + num2;
		break;
	case '-':
		res = num1 - num2;
		break;
	case '*':
		res = num1 * num2;
		break;
	case'/':
		res = num1 / num2;
		break;
	}

	printf("%d%c%d=%d", num1, op, num2, res);
	return 0;
}