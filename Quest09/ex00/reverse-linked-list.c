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

// fonctions que j'ai trouvé pour pouvoir débugger pour maintenant
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

listnode* reverse(listnode *param_1, listnode *param_2, listnode *param_3)
{
    if (param_1 == NULL)
        return param_3;
    param_2 = param_1->next;
    param_1->next = param_3;
    reverse(param_2, param_3, param_1);
}

listnode* reverse_linked_list(listnode* param_1)
{
    listnode* reverse_link = (listnode *)malloc(sizeof(listnode));

    reverse_link = reverse(param_1, NULL, NULL);

    return reverse_link;
}

int main () {
    listnode* link_list = (listnode *)malloc(sizeof(listnode));;

    link_list->val = 1;        
    link_list->next = (listnode *)malloc(sizeof(listnode));
    link_list->next->val = 2;
    link_list->next->next = (listnode *)malloc(sizeof(listnode));
    link_list->next->next->val = 3;
    link_list->next->next->next = (listnode *)malloc(sizeof(listnode));
    link_list->next->next->next->val = 4;
    link_list->next->next->next->next = (listnode *)malloc(sizeof(listnode));
    link_list->next->next->next->next->val = 5;
    link_list->next->next->next->next->next = NULL;

    printf_linked_list(reverse_linked_list(link_list));

    return 0;
}