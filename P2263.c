/* 동륭햄이 써준 코드..?
 * 중위순회, 후위순회를 주고 전위순회를 구하라..?
 * 후위순회의 끝은 항상 루트노드
 */

#include <stdio.h>

int N;
int inorder[100005];
int postorder[100005];
int idx[100005];

void preorder(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start > in_end || post_start > post_end)
        return;

    int root = postorder[post_end]; // 후위순회의 끝은 항상 루트노드이다.
    printf("%d ", root);

    preorder(in_start, idx[root] - 1, post_start, post_start + (idx[root] - in_start) - 1);
    preorder(idx[root] + 1, in_end, post_start + (idx[root] - in_start), post_end - 1);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);

    for (int i = 0; i < N; i++)
        idx[inorder[i]] = i; // ?

    preorder(0, N - 1, 0, N - 1);
    return 0;
}