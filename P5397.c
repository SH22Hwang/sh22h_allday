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
    node *tmp = (node *)malloc(sizeof(node));
    tmp = head->next;
    while (tmp != tail)
    {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    // free(tmp);
}

int main()
{
    int num;
    scanf("%d", &num);
    while (num--)
    {
        init();
        // char temp[1000001]; // 런타임 에러 (AssertionFailed)
        // scanf(" %s", temp); // 배열에 관한 에러이니 이 쯤이 문제인듯

        // char *str = (char *)malloc(strlen(temp));
        // strcpy(str, temp);

        char str[12];
        scanf(" %s", str);

        for (int i = 0; i < strlen(str); i++)
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
        printf("\n");
    }
    return 0;
}
/*
* 작동이 되긴하는데 시간 초과인 코드

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

void print_list()
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp = head->next;
    while (tmp != tail)
    {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    free(tmp);
}

int main()
{
    init();

    int num;
    scanf("%d", &num);
    while (num--)
    {

        char str[1000000];
        scanf(" %s", str);
        for (int i = 0; i < strlen(str); i++)
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

        push('\n');
    }
    print_list();
    return 0;
}
*/