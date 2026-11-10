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

int ln_linked_list(listnode* list_count) {
    int length = 0;

    while (list_count != NULL) {
        length++;
        list_count = list_count->next;
    }

    return length;
}

listnode* removing(listnode *list)
{
    if (list == NULL) {
        return 0;
    }
    else {
        while (list->val == list->next->val) {
                list = list->next;
        }

        listnode* remove_list = (listnode*)malloc(sizeof(listnode));

        remove_list->val = list->val;

        remove_list->next = removing(list->next);

        return remove_list;
    }

    return 0;
}

listnode* remove_duplicates_from_sorted_list(listnode* param_1)
{
    listnode* removed_dup = (listnode *)malloc(sizeof(listnode));

    removed_dup = removing(param_1);

    return removed_dup;
}

int main () {
    listnode* linked_list = (listnode *)malloc(sizeof(listnode));

    linked_list->val = 1;
    linked_list->next = (listnode *)malloc(sizeof(listnode));
    linked_list->next->val = 1;
    linked_list->next->next = (listnode *)malloc(sizeof(listnode));
    linked_list->next->next->val = 1;
    linked_list->next->next->next = (listnode *)malloc(sizeof(listnode));
    linked_list->next->next->next->val = 1;
    linked_list->next->next->next->next = NULL;

    printf_linked_list(remove_duplicates_from_sorted_list(linked_list));

    return 0;
}