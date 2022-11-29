#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct _node
{
    char left;
    char right;
} node;

node tree[26] = {0};
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

    node newnode;
    newnode.left = left;
    newnode.right = right;

    tree[parent - 'A'] = newnode;
}

void preorder(char parent)
{
    if (parent == '.')
        return;

    printf("%c", parent);
    preorder(tree[parent - 'A'].left);
    preorder(tree[parent - 'A'].right);
}

void inorder(char parent)
{
    if (parent == '.')
        return;

    inorder(tree[parent - 'A'].left);
    printf("%c", parent);
    inorder(tree[parent - 'A'].right);
}

void postorder(char parent)
{
    if (parent == '.')
        return;

    postorder(tree[parent - 'A'].left);
    postorder(tree[parent - 'A'].right);
    printf("%c", parent);
}