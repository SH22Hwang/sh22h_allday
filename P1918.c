#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int stack[MAX_SIZE];
int idx_top = -1;

int is_empty()
{
    return idx_top < 0 ? 1 : 0;
}

void push(int x)
{
    if (!is_full())
        stack[++idx_top] = x;
}

int pop()
{
    if (is_empty())
        return -1;
    else
        return stack[idx_top--];

    // return is_empty() ? -1 : stack[idx_top--];
}

int top()
{
    if (is_empty())
        return -1;
    else
        return stack[idx_top];
    // return is_empty() ? -1 : stack[idx_top--];
}

void clear()
{
    while (!is_empty())
        printf("%c", pop());
}

int get_priority(char o)
{
    switch (o)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 0;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '(':
        return -1;
        break;
    case ')':
        return -1;
        break;
    default:
        break;
    }
}

int main()
{
    char expression[101];
    scanf("%s", expression);

    int len = strlen(expression);

    for (int i = 0; i < len; i++)
    {
        if (expression[i] >= 'A' && expression[i] <= 'Z')
        {
            printf("%c", expression[i]);
        }
        else
        {
            if (is_empty())
            {
                push(expression[i]);
            }
            else
            {
                if (expression[i] == '(')
                {
                    push(expression[i]);
                }
                else if (expression[i] == ')')
                {
                    while (1)
                    {
                        if (top() != '(')
                            printf("%c", pop());
                        else
                        {
                            pop();
                            break;
                        }
                    }
                }
                else
                {
                    while (!is_empty() && (get_priority(top()) >= get_priority(expression[i])))
                        printf("%c", pop());

                    push(expression[i]);
                }
            }
        }
    }

    clear();
    return 0;
}