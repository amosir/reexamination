#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50
typedef struct Node
{
    char ch;
    struct Node *left;
    struct Node *right;
} Node;
// 根据前序和中序构建二叉树
Node *buildTree(char preSequence[], int preLeft, int preRight, char inSequence[], int inLeft, int inRight)
{
    if (preLeft > preRight)
    {
        return NULL;
    }
    Node *root = (Node *)malloc(sizeof(Node));
    root->ch = preSequence[preLeft];
    // 根节点在中序序列中的索引
    int pos = 0;
    while (preSequence[preLeft] != inSequence[pos])
    {
        pos++;
    }
    // 递归地构建左右节点
    root->left = buildTree(preSequence, preLeft + 1, preLeft + pos - inLeft, inSequence, inLeft, pos - 1);
    root->right = buildTree(preSequence, preLeft + pos - inLeft + 1, preRight, inSequence, pos + 1, inRight);
    return root;
}
// 后续遍历
void postVisit(Node *root)
{
    if (root != NULL)
    {
        postVisit(root->left);
        postVisit(root->right);
        printf("%c", root->ch);
    }
}
int main()
{
    char preSequence[SIZE], inSequence[SIZE];
    while (scanf("%s %s", preSequence, inSequence) != EOF)
    {
        getchar();
        Node *root = buildTree(preSequence, 0, strlen(preSequence) - 1, inSequence, 0, strlen(inSequence) - 1);
        postVisit(root);
        printf("\n");
    };
    return 0;
}