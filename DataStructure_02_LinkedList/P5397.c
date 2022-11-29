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

    head->data = 'H';
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

void print_list()
{
    cur = head->next;
    while (cur != tail)
    {
        printf("%c", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    int num;
    scanf("%d", &num);
    while (num--)
    {
        init();
        char str[1000001];
        scanf(" %s", str);
        int length = strlen(str); // strlen이 원인!!!
        for (int i = 0; i < length; i++)
        {
            switch (str[i])
            {
            case ('<'):
            {
                if (cur != head)
                    cur = cur->prev;
                break;
            }
            case ('>'):
            {
                if (cur->next != tail)
                    cur = cur->next;
                break;
            }
            case ('-'):
            {
                if (cur != head)
                {
                    cur->next->prev = cur->prev;
                    cur->prev->next = cur->next;
                    cur = cur->prev;
                }
                break;
            }
            default:
                push(str[i]);
            }
        }
        print_list();
    }
    return 0;
}