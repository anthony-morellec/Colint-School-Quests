#include <stdlib.h>
#include <stdio.h>
// pas sûr de ce que fait struct.h
#include "struct.h"

#ifndef STRUCT_LISTNODE
// comment pourrais-je utiliser STRUCT_LISTNODE ?
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

listnode* reverse(listnode *head, listnode *rev)
{
    if (head == NULL) {
        return rev;
    }
    rev = (listnode *)malloc(sizeof(listnode));
    rev->val = head->val;
    // comment faire un next mais dans l'autre sens
    return reverse(head->next, rev->next);
}

listnode* reverse_linked_list(listnode* param_1)
{
    listnode* reverse_link = (listnode *)malloc(sizeof(listnode));

    // comment inverser une liste chainé de manière efficace quand on ne sait pas le nombre d'objets dans cette liste à l'avance ?
    
    reverse_link = reverse(param_1, reverse_link);

    //for (int index = 0; index < length(param_1, 0); index++);

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
    solve(reverse_link, res, &size);
    printArray(res, size);

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
    link_list->next->next->next->next->next = (listnode *)malloc(sizeof(listnode));
    link_list->next->next->next->next->next->val = 6;
    link_list->next->next->next->next->next->next = NULL;

    // comment entrer une valeur de type "listnode *" ?
    reverse_linked_list(link_list);

    return 0;
}