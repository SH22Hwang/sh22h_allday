#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    char data;
    struct _node *next;
    struct _node *prev;
} node;

node *head;
node *tail;
node *cur;

void init()
{
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));

    head->data = 'H'; // 쌍따옴표 X
    head->next = tail;
    head->prev = NULL;

    tail->data = 'T';
    tail->next = NULL;
    tail->prev = head;

    cur = head;
}

void push(char c)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = c;
    newnode->prev = cur;
    newnode->next = cur->next;

    cur->next->prev = newnode;
    cur->next = newnode;

    cur = newnode;
}

int N;

int main()
{
    init();

    char str[100000];
    scanf(" %s", str);
    for (int i = 0; str[i] != NULL; i++)
        push(str[i]);

    // scanf("%*c");
    scanf(" %d", &N);

    cur = tail->prev;
    // while (N--)
    for (int i = 0; i < N; i++)
    {
        char temp;
        scanf(" %c", &temp);

        switch (temp)
        {
        case ('L'):
        {
            if (cur != head)
                cur = cur->prev;
            break;
        }
        case ('D'):
        {
            if (cur->next != tail)
                cur = cur->next;
            break;
        }
        case ('B'):
        {
            if (cur != head)
            {
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
                cur = cur->prev;
            }
            break;
        }
        case ('P'):
        {
            char word;
            scanf(" %c", &word);
            push(word);
            break;
        }
        }
    }

    node *result = head->next;
    while (result->next)
    {
        printf("%c", result->data);
        result = result->next;
    }

    return 0;
}