#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int num;
    struct Node *next;
} Node;
Node *buildLink(Node *head, int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->num = num;
    // 链表为空时
    if (head == NULL)
    {
        head = node;
        return head;
    }
    else
    {
        // 插到到头结点之前
        if (head->num > num)
        {
            node->next = head;
            head = node;
            return head;
        }
        // 插到中间或尾部,pre指向待插入位置的前一个元素
        Node *pre = head;
        while (pre->num <= num && pre->next != NULL && pre->next->num <= num)
        {
            pre = pre->next;
        }
        node->next = pre->next;
        pre->next = node;
        return head;
    }
}
void visitLinkList(Node *head)
{
    for (Node *pos = head; pos != NULL; pos = pos->next)
    {
        printf("%d ", pos->num);
    }
    printf("\n");
}
int main()
{
    int cnt;
    scanf("%d", &cnt);
    Node *head = NULL;
    for (int i = 0; i < cnt; i++)
    {
        int temp;
        scanf("%d", &temp);
        head = buildLink(head, temp);
    }
    visitLinkList(head);
    return 0;
}