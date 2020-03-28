#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    struct node *next;
} node;
node *createCircle(int maxNum)
{
    // 分别是链表尾和当前新创建的节点
    node *end, *pos;
    // 创建链表头
    node *head = (node *)malloc(sizeof(node));
    head->num = 1;
    head->next = NULL;
    end = head;
    for (int i = 2; i <= maxNum; i++)
    {
        pos = (node *)malloc(sizeof(node));
        pos->num = i;
        end->next = pos;
        end = end->next;
    }
    // 成环
    end->next = head;
    return head;
}
int main()
{
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        int num;
        scanf("%d", &num);
        node *head = createCircle(num);
        for (int j = 0; j < num; j++)
        {
            head = head->next;
            // 目标节点
            node *target = head->next;
            head->next = target->next;
            printf("%d ", target->num);
            free(target);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}