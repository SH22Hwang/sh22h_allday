/**
 * @file P1966.c
 * @date 2022-12-16
 * @name 큐
 *
 * 정렬하고 큐에 넣은 다음 팝해야 할 듯.
 * 1. 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
 * 2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
 *
 * 필요한 것:
 * 1. 큐 구조화
 * 2. 문서의 중요도 현황 배열
 *
 *
 * 문제 분석
 * 3 // 테스트 케이스의 수
 * 1 0 // 문서의 개수, 알고싶은 문서의 위치 (0: 맨 왼쪽(앞))
 * 5 // 문서들의 중요도
 * // 출력: 1
 * 4 2
 * 1 2 3 4
 * // 출력: 2
 * 6 0
 * 1 1 9 1 1 1
 * // 출력: 5
 */

#include <stdio.h>

#define MAX_SIZE 1001

typedef struct _node
{
    int idx;
    int imp;
} node;

node queue[MAX_SIZE];
int idx_rear = 0, idx_front = 0;

void push(node x);
node pop();
int next_pos(int idx);
int is_empty();

int main()
{
    int tc, num_paper, target;

    scanf("%d", &tc);

    while (tc--)
    {
        int importance[10] = {0}; // 중요도는 1~9 중요도 문서의 수
        int cnt = 0;              // 문서 인쇄 순서
        scanf(" %d %d", &num_paper, &target);

        for (int i = 0; i < num_paper; i++) // push
        {
            node temp = {i, 0};     // idx: i
            scanf("%d", &temp.imp); // imp: 입력
            importance[temp.imp]++;

            push(temp);
        }

        for (;;) // 계속 pop
        {
            int flag = 1; // 출력 여부 결정
            node doc = pop();

            // pop한 문서 중요도 보고 더 중요한 문서 있는지 확인
            for (int k = doc.imp + 1; k < 10; k++)
            {
                if (importance[k] > 0)
                {
                    push(doc);
                    flag = 0;
                    break; // 다음 문서로
                }
            }

            if (flag == 1)
            {
                cnt++;
                importance[doc.imp]--;

                if (doc.idx == target)
                {
                    printf(">>> %d\n", cnt);
                    break; // 다음 테스트케이스로
                }
            }
        }

        // 큐 비우기 <<< 문제의 코드
        while (!is_empty())
        {
            pop();
        }
    }

    return 0;
}

void push(node x)
{
    idx_rear = next_pos(idx_rear);
    queue[idx_rear] = x;
}

node pop()
{
    if (is_empty())
    {
        node t = {-1, -1};
        return t;
    }
    else
    {
        idx_front = next_pos(idx_front);
        return queue[idx_front];
    }
}

int next_pos(int idx)
{
    return idx == MAX_SIZE - 1 ? 1 : idx + 1;
}

int is_empty()
{
    return idx_rear == idx_front ? 1 : 0;
}
