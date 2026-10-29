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

#include "struct.h"

listnode* reverse_linked_list()
{
    listnode *reverse;

    reverse = (struct s_listnode *)malloc(sizeof(struct s_listnode));

    for (int index = 0; index < 5; index++) {
        reverse->val = index;        
        reverse->next = reverse;
    }
    
    printf("%d", &reverse);
    return reverse;
}

int main () {
    reverse_linked_list();

    return 0;
}