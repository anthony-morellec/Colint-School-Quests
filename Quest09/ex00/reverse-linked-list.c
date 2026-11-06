#include <stdlib.h>
#include <stdio.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif

void solve(listnode *head, int *res, int *size)
{
    if (head == NULL)
        return;
    res[(*size)++] = head->val;
    solve(head->next, res, size);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        printf("->");
    }
    printf("NULL\n");
}

void printf_linked_list(listnode *param_1) {
    int size = 0;
    int *res = (int *)malloc(6 * sizeof(int));
    solve(param_1, res, &size);
    printArray(res, size);
}

listnode* reverse(listnode *list, listnode *transfert, listnode *reverse_list)
{
    if (list == NULL) {
        return reverse_list;
    }

    transfert = list->next;
    list->next = reverse_list;

    return reverse(transfert, reverse_list, list);
}

listnode* reverse_linked_list(listnode* param_1)
{
    listnode* reverse_link = (listnode *)malloc(sizeof(listnode));

    if (reverse_link != NULL) {
        reverse_link = reverse(param_1, NULL, NULL);
    }

    return reverse_link;
}

int main () {
    listnode* linked_list = (listnode *)malloc(sizeof(listnode));

    linked_list->val = 1;
    linked_list->next = (listnode *)malloc(sizeof(listnode));
    linked_list->next->val = 2;
    linked_list->next->next = (listnode *)malloc(sizeof(listnode));
    linked_list->next->next->val = 3;
    linked_list->next->next->next = (listnode *)malloc(sizeof(listnode));
    linked_list->next->next->next->val = 4;
    linked_list->next->next->next->next = (listnode *)malloc(sizeof(listnode));
    linked_list->next->next->next->next->val = 5;
    linked_list->next->next->next->next->next = NULL;

    printf_linked_list(reverse_linked_list(linked_list));

    return 0;
}