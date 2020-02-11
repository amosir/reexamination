#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct TreeNode
{
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(char ch)
    {
        this->ch = ch;
        this->left = NULL;
        this->right = NULL;
    }
} TreeNode;
static int pos = 0;
TreeNode *buildTree(string str)
{
    if (pos >= str.length())
    {
        return NULL;
    }
    if (str[pos] == '#')
    {
        pos++;
        return NULL;
    }
    TreeNode *root = new TreeNode(str[pos]);
    pos++;
    root->left = buildTree(str);
    root->right = buildTree(str);
    return root;
};
void inOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout << root->ch << " ";
        inOrder(root->right);
    }
}
int main()
{
    string sequence;
    cin >> sequence;
    int len = sequence.length();
    TreeNode *root = buildTree(sequence);
    inOrder(root);
    return 0;
}