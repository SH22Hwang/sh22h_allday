#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
    struct _node *prev;
} node;

int N, M;
node *head;
node *tail;
node *cur;

void init()
{
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));

    head->data = 'H';
    tail->data = 'T';

    head->next = tail;
    head->prev = tail;

    tail->next = head;
    tail->prev = head;
    cur = head;
}

int main()
{
    scanf("%d%d", &N, &M);
    printf("<");

    init();

    // 1부터 N까지 순서대로 노드를 만드는 코드
    for (int i = 1; i <= N; i++)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = i;

        cur->next = newnode;

        newnode->prev = cur;
        newnode->next = tail;

        cur = newnode;
        tail->prev = cur;
    }

    node *temp = head->next;
    int key = 0;
    for (int j = 0; j <= N; j++)
    {
        key = M;

        while (key--)
        { // 꼬리 3칸 이동
            temp = temp->next;
        }
        // printf(c++ ? ", %d" : "%d", tmp->data);
        printf("%d ", temp->data);

        // 연결리스트에서 노드 삭제하는 법
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    /*
for(;;){
    printf("%d ",temp->data);
    temp = temp->prev;
}
*/

    return 0;
}