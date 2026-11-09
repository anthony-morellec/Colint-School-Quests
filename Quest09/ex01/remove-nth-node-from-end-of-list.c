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

listnode* removing(listnode *list, listnode *remove_list, int nth, int test)
{
    if (list == NULL) {
        return remove_list;
    }

    if (test != nth) {
        remove_list->val = list->val;
        remove_list->next = (listnode *)malloc(sizeof(listnode));
        return removing(list->next, remove_list->next, nth, test--);
    }
    else {
        return removing(list->next, remove_list, nth, test--);
    }
}

listnode* remove_nth_node_from_end_of_list(listnode* param_1, int param_2)
{
    listnode* removed_link_list = (listnode *)malloc(sizeof(listnode));

    removed_link_list = removing(param_1, NULL, param_2, 5);

    /*for (int index = 1; index < ln_linked_list(param_1); index++) {
        if (index != ln_linked_list(param_1) - param_2) {

        }
    }*/

    return removed_link_list;
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

    printf_linked_list(remove_nth_node_from_end_of_list(linked_list, 2));

    return 0;
}