#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int data;
    int pos;
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
    tail->data = 'T';

    head->pos = 0;
    tail->pos = -1;

    head->next = tail;
    head->prev = tail;

    tail->next = head;
    tail->prev = head;

    cur = head;
}

// void makeNode(int arr[])
// {
//     for (int i = 0; i < size; i++)
//     {
//         node *newnode = (node *)malloc(sizeof(node));
//         newnode->data = arr[i];

//         cur->next = newnode;
//         newnode->prev = cur;
//         newnode->next = tail;

//         cur = newnode;
//         tail->prev = cur;
//     }
// }

int main()
{
    char str[10000];
    int size, cnt = 0;

    scanf("%d", &size);

    // int arr[10000] = {
    //     NULL,
    // };
    int *arr = (int *)malloc(sizeof(int) * size); // size길이의 배열 생성

    // int arr[size] = {
    //     0,
    // }; // ← 이거(VLA) 는 안 됨.쥐엔장 !

    scanf("%*c");
    scanf("%[^\n]s", str);

    char *box = NULL;
    box = strtok(str, " ");
    while (box != NULL)
    {
        arr[cnt] = atoi(box);
        box = strtok(NULL, " ");
        if (box != NULL)
            cnt++;
    }

    init();

    for (int j = 0; j < size; j++)
    {
        node *newnode = (node *)malloc(sizeof(node)); // 새 노드 만듦
        newnode->data = arr[j];                       // 새 노드에 arr에 있는 데이터 넣음
        newnode->pos = j + 1;
        cur->next = newnode; // 새 노드 끼워넣기
        newnode->prev = cur;
        newnode->next = tail;

        cur = newnode; // cur 변경
        tail->prev = cur;
    }

    // node 탐색하기
    node *temp = head->next;       // 맨 처음 노드 선택
    head->next->prev = tail->prev; // 계산을 위해 head, tail 삭제
    tail->prev->next = head->next;

    // 맨 처음 노드(풍선)삭제
    printf("1 ");
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    for (int k = 0; k < size - 1; k++)
    {
        int key = temp->data;
        if (key < 0) // key가 음수이면 key만큼 이전 노드로 이동
        {
            while (key++)
                temp = temp->prev;
        }
        else
        {
            while (key--)
                temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("%d ", temp->pos);
    }

    return 0;
}