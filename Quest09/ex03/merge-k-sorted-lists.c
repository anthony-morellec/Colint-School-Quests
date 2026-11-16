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

void print_linked_list(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);

        if (i < size - 1) {
            printf("->");
        }
    }
}

void printf_array(listnode_array* param_1, int nb) {
    printf("[");

    for (int index = 0; index < nb; index++) {
        int size = 0;
        int *res = (int *)malloc(6 * sizeof(int));

        listnode* print_list = (listnode *)malloc(sizeof(listnode));
        print_list = param_1->array[index];

        solve(print_list, res, &size);

        print_linked_list(res, size);

        if (index < nb - 1) {
            printf(", ");
        }
    }

    printf("]");
}

listnode* merge_k_sorted_lists(listnode_array* param_1)
{
    printf_array(param_1, 3);

    return 0;
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

    linked_list_array->array = (listnode **)malloc(sizeof(listnode_array));

    linked_list_array->array[0] = linked_list1;
    linked_list_array->array[1] = linked_list2;
    linked_list_array->array[2] = linked_list3;

    merge_k_sorted_lists(linked_list_array);

    return 0;
}