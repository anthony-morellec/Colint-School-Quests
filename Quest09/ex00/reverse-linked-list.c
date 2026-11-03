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

/*listnode* reverse(listnode *head, listnode *rev, int test)
{
    if (test >= 5) {
        return rev;
    }
    rev = (listnode *)malloc(sizeof(listnode));
    rev->val = 1; 
    test++;
    // comment faire un next mais dans l'autre sens
    reverse(head, rev->next, test);
}*/

listnode* reverse_linked_list(listnode* param_1)
{
    listnode* reverse_link = (listnode *)malloc(sizeof(listnode));
    listnode* head = (listnode *)malloc(sizeof(listnode));
    listnode* er = (listnode *)malloc(sizeof(listnode));
    // reverse_link = reverse(param_1, reverse_link, 0);

    // while () {}
    
    head = param_1->next;
    param_1->next = NULL;

    er = head->next;
    head->next = param_1;
    
    er->next = head;

    /*reverse_link->val = param_1->next->next->next->next->val;
    reverse_link->next = (listnode *)malloc(sizeof(listnode));
    reverse_link->next->val = param_1->next->next->next->val;
    reverse_link->next->next = (listnode *)malloc(sizeof(listnode));
    reverse_link->next->next->val = param_1->next->next->val;
    reverse_link->next->next->next = (listnode *)malloc(sizeof(listnode));
    reverse_link->next->next->next->val = param_1->next->val;
    reverse_link->next->next->next->next = (listnode *)malloc(sizeof(listnode));
    reverse_link->next->next->next->next->val = param_1->val;
    reverse_link->next->next->next->next->next = NULL;*/

    int size = 0;
    int *res = (int *)malloc(6 * sizeof(int));
    solve(er, res, &size);
    printArray(res, size);

    return reverse_link;
}

int main () {
    listnode* link_list = (listnode *)malloc(sizeof(listnode));;

    link_list->val = 1;        
    link_list->next = (listnode *)malloc(sizeof(listnode));
    link_list->next->val = 2;
    link_list->next->next = (listnode *)malloc(sizeof(listnode));
    link_list->next->next->val = 5;
    link_list->next->next->next = NULL;

    reverse_linked_list(link_list);

    return 0;
}