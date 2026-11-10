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

#ifndef STRUCT_LISTNODE_ARRAY
#define STRUCT_LISTNODE_ARRAY
typedef struct s_listnode_array
{
    int size;
    listnode **array;
} listnode_array;
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

listnode* merge_k_sorted_lists(listnode_array* param_1)
{
    return param_1
}

int main () {
    listnode* linked_list1 = (listnode *)malloc(sizeof(listnode));
    listnode* linked_list2 = (listnode *)malloc(sizeof(listnode));
    listnode* linked_list3 = (listnode *)malloc(sizeof(listnode));

    listnode_array* linked_list_array = (listnode_array *)malloc(sizeof(listnode_array));

    linked_list1->val = 1;
    linked_list1->next = (listnode *)malloc(sizeof(listnode));
    linked_list1->next->val = 4;
    linked_list1->next->next = (listnode *)malloc(sizeof(listnode));
    linked_list1->next->next->val = 5;
    linked_list1->next->next->next = NULL;

    linked_list2->val = 1;
    linked_list2->next = (listnode *)malloc(sizeof(listnode));
    linked_list2->next->val = 3;
    linked_list2->next->next = (listnode *)malloc(sizeof(listnode));
    linked_list2->next->next->val = 4;
    linked_list2->next->next->next = NULL;

    linked_list3->val = 2;
    linked_list3->next = (listnode *)malloc(sizeof(listnode));
    linked_list3->next->val = 6;
    linked_list3->next->next = NULL;

    linked_list_array[0] = linked_list1;
    linked_list_array[1] = linked_list2;
    linked_list_array[2] = linked_list3;

    printf_linked_list(merge_k_sorted_lists(linked_list_array));

    return 0;
}