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

listnode* removing(listnode *list, int nth, int index)
{
    if (index == nth) {
        list = list->next;
    }
    
    if (list != NULL) {
        listnode* remove_list = (listnode*)malloc(sizeof(listnode));

        remove_list->val = list->val;

        remove_list->next = removing(list->next, nth, index+1);

        return remove_list;
    }

    return 0;
}

listnode* remove_nth_node_from_end_of_list(listnode* param_1, int param_2)
{
    listnode* removed_link_list = (listnode *)malloc(sizeof(listnode));

    if (param_2 <= ln_linked_list(param_1) && param_2 > 0) {
        removed_link_list = removing(param_1, (ln_linked_list(param_1) - param_2 + 1), 1);
    }

    return removed_link_list;
}

int main () {
    listnode* linked_list = (listnode *)malloc(sizeof(listnode));

    linked_list->val = 1;

    printf_linked_list(remove_nth_node_from_end_of_list(linked_list, 1));

    return 0;
}