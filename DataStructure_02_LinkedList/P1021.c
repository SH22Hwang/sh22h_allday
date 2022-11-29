/* 2022-09-08
 * 연결리스트로 양방향 순환 큐 구현
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M; // 큐의 크기 N, 뽑아내려고 하는 수의 개수 M

typedef struct _node
{
    int data;
    int idx;
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
    head->idx = 0;
    head->next = tail;
    head->prev = tail;

    tail->data = 'T';
    tail->idx = 'i';
    tail->next = head;
    tail->prev = head;

    cur = head;
}

void pop()
{
    N--;
    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    cur = cur->next;

    node *temp = cur;
    for (int i = 1; i <= N; i++)
    {
        temp->idx = i;
        temp = temp->next;
    }
}

int main()
{
    scanf("%d%d", &N, &M); // 큐의 크기 N
                           // 뽑을 수 넣을 배열의 크기 M

    // int *arr = (int *)malloc(sizeof(int) * M); // 왜 여기서 문제가 생기지...?
    int arr[M] = {};

    int cnt = 0;
    char str[10000];

    scanf("%*c");          // 버퍼 에러 예방
    scanf("%[^\n]s", str); // 공백문자 포함 문자열 입력

    char *box = NULL;
    box = strtok(str, " ");

    while (box != NULL)
    {
        arr[cnt] = atoi(box);
        box = strtok(NULL, " ");
        if (box != NULL)
            cnt++;
    }

    // 원형 큐 생성
    init();

    for (int i = 1; i <= N; i++)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = i; // 순환 큐에 1부터 N까지 넣음
        newnode->idx = i;
        newnode->prev = cur;
        newnode->next = tail;

        cur->next = newnode;

        cur = newnode;
        tail->prev = cur;
    }

    // 탐색
    int result = 0;
    int index;
    node *tmp;

    cnt++;
    cur = head->next; // 첫 번째 노드
    head->next->prev = tail->prev;
    tail->prev->next = head->next;

    while (cnt) // cnt가 0이 될 때까지 반복
    {
        tmp = cur;
        for (int i = 1; i <= N; i++)
        {
            if (tmp->data == arr[M - cnt])
            {
                index = i;
                break;
            }
            else
                tmp = tmp->next;
        }

        if (index - 1 <= N - index)
        {
            while (1)
            {
                if (arr[M - cnt] == cur->data)
                {
                    cnt--; // arr과 일치하면 cnt 감소
                    pop();
                    break;
                }
                else
                {
                    result++;
                    cur = cur->next;
                }
            }
        }
        else
        {
            while (1)
            {
                if (arr[M - cnt] == cur->data)
                {
                    cnt--; // arr과 일치하면 cnt 감소
                    pop();
                    break;
                }
                else
                {
                    result++;
                    cur = cur->prev;
                }
            }
        }
    }

    printf("%d ", result);
    return 0;
}