#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

void my_print_words_array(string_array* param_1)
{
    for (int i = 0; i < param_1->size; i++) {
        printf("%s\n", param_1->array[i]);
    }
}

int main(int ac, char **av) {
    if (ac == 2) {
        my_print_words_array(av[1]);
    }
    else {
        printf("invalid input");
    }
    return 0;
}