#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

double stack[MAX_SIZE];
int idx_top = -1;

int is_empty()
{
    return idx_top < 0 ? 1 : 0;
}

int is_full()
{
    return idx_top < MAX_SIZE - 1 ? 0 : 1;
}

void push(double x)
{
    if (!is_full())
        stack[++idx_top] = x;
}

double pop()
{
    return is_empty() ? -1 : stack[idx_top--];
}

void calculate(char c)
{
    double num2 = pop();
    double num1 = pop();

    switch (c)
    {
    case '+':
        push(num1 + num2);
        break;
    case '-':
        push(num1 - num2);
        break;
    case '*':
        push(num1 * num2);
        break;
    case '/':
        push(num1 / num2);
        break;
    default:
        break;
    }
}

int main()
{
    int num_operand;
    scanf("%d", &num_operand);

    char exp[101];
    scanf("%s", exp);
    int len = strlen(exp);

    double arr_operand[26];
    for (int i = 0; i < num_operand; i++)
        scanf(" %lf", &arr_operand[i]);

    for (int i = 0; i < len; i++)
        exp[i] >= 'A' && exp[i] <= 'Z' ? push(arr_operand[exp[i] - 'A'])
                                       : calculate(exp[i]);

    printf("%.2lf", pop());

    return 0;
}