#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// typedef struct _node
// {
//     char c;
//     struct _node *left;
//     struct _node *right;
// } node;

// node tree[MAX_SIZE];

char tree[MAX_SIZE] = {0};
int size = 0;

void push(char parent, char right, char left);
char find_node(char parent);

void preorder(char parent);  // 전위순회
void inorder(char parent);   // 중위순회
void postorder(char parent); // 후위순회 다 재귀함수로 만들어야 함

int main()
{
    int num_node;
    scanf("%d", &num_node);

    for (int i = 1; i <= num_node; i++)
    {
        char p, l, r;
        scanf(" %c %c %c", &p, &l, &r);

        push(p, l, r);
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');

    return 0;
}

void push(char parent, char left, char right)
{
    if (size == 0)
    {
        tree[1] = parent;
        tree[2] = left;
        tree[3] = right;
    }
    else
    {
        int pos = find_node(parent);

        tree[pos] = parent;
        tree[pos * 2] = left;
        tree[pos * 2 + 1] = right;
    }

    size += 3;
}

char find_node(char parent)
{
    for (int i = 1; i <= size; i++)
    {
        if (tree[i] == parent)
        {
            return i;
        }
    }

    return 0;
}

void preorder(char parent)
{
    int idx = find_node(parent);

    printf("%c", tree[idx]);

    if (tree[idx * 2] >= 'A' && tree[idx * 2] <= 'Z')
        preorder(tree[idx * 2]);

    if (tree[idx * 2 + 1] >= 'A' && tree[idx * 2 + 1] <= 'Z')
        preorder(tree[idx * 2 + 1]);
}

void inorder(char parent)
{
    int idx = find_node(parent);

    if (tree[idx * 2] >= 'A' && tree[idx * 2] <= 'Z')
        inorder(tree[idx * 2]);

    printf("%c", tree[idx]);

    if (tree[idx * 2 + 1] >= 'A' && tree[idx * 2 + 1] <= 'Z')
        inorder(tree[idx * 2 + 1]);
}

void postorder(char root)
{
    int idx = find_node(root);

    if (tree[idx * 2] >= 'A' && tree[idx * 2] <= 'Z')
        postorder(tree[idx * 2]);

    if (tree[idx * 2 + 1] >= 'A' && tree[idx * 2 + 1] <= 'Z')
        postorder(tree[idx * 2 + 1]);

    printf("%c", tree[idx]);
}