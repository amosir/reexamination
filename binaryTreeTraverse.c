#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 101
typedef struct TreeNode
{
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

static int pos = 0;
TreeNode *buildTree(char str[], int len)
{
    if (pos >= len)
    {
        return NULL;
    }

    if (str[pos] == '#')
    {
        pos++;
        return NULL;
    }
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->ch = str[pos++];
    root->left = buildTree(str, len);
    root->right = buildTree(str, len);
    return root;
}
void traverseTree(TreeNode *root)
{
    if (root != NULL)
    {
        traverseTree(root->left);
        printf("%c ", root->ch);
        traverseTree(root->right);
    }
}
int main()
{
    char str[MAX_LEN];
    scanf("%s", str);
    TreeNode *root = buildTree(str, strlen(str));
    traverseTree(root);
    return 0;
}
