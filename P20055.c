#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int life, index, robot;
    struct _node *next;
    struct _node *prev;
} node;

node *head; // 올리는 위치 (처음에는 1번 노드)
node *tail; // 올리는 위치 바로 전 (처음에는 2N번 노드)
node *out;  // 내리는 위치 (처음에는 N번 노드)
node *cur;  // 현재 위치

int N, K, life_counter = 0;

void push(int l, int idx) // 원형 연결 리스트
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->life = l;
    newnode->index = idx;
    newnode->robot = 0;

    if (idx == N)
        out = newnode;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        cur->next = newnode;
        newnode->prev = cur;
        newnode->next = head;
    }

    tail = newnode;
    head->prev = tail;
    cur = newnode;
}

int is_over() // 과정종료
{
    return life_counter >= K ? 1 : 0;
}

void turn() // 1. 한 칸 회전 & 로봇 내리기
{
    out->robot = 0; // out 비우기
    head = head->prev;
    tail = tail->prev;
    out = out->prev;

    cur = head;
    out->robot = 0; // out 비우기
}

void move() // 2. 로봇 옆으로 한 칸 이동
{
    out->robot = 0;                 // out 비우기
    cur = out->prev;                // 가장 먼저 벨트에 올라간 로봇부터
    for (int i = 0; i < N - 2; i++) // head바로 앞까지 반복... out, head 제외한 나머지
    {
        if (cur->robot == 1 && cur->next->robot == 0 && cur->next->life >= 1) // move 조건
        {
            cur->robot = 0;
            cur->next->life -= 1;
            cur->next->robot = 1;

            if (cur->next->life == 0)
                life_counter++;
        }

        if (is_over()) // 과정종료
            break;
        else
            cur = cur->prev;
    }
}

void place() // 3. 로봇 올리기
{
    cur = head;
    if (cur->life >= 1)
    {
        cur->robot = 1;
        cur->life -= 1;

        if (cur->life == 0)
            life_counter++;
    }
}

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= 2 * N; i++) // 2N만큼 원형 연결 리스트 생성
    {
        int temp;
        scanf("%d", &temp);

        push(temp, i);
    }

    int stage = 0;
    cur = head;
    while (is_over() == 0) // 단계는 1, 2, 3, 4 과정을 하나로 묶은 것
    {
        stage++;
        // cur = cur->prev; // 1. 한 칸 회전, 로봇 내리기
        turn();

        move(); // 2. 로봇 옆으로 한 칸 이동

        if (is_over()) // 과정종료
            break;

        place(); // 3. 로봇 올리기
    }

    printf("%d", stage);
    return 0;
}