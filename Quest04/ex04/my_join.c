#include <stdio.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif


char* my_join(string_array* param_1, char* param_2)
{
    char *string = "";
    for (int i = 0; i < param_1->size; i++) {
        string += param_1->array[i];
        if (i < param_1->size - 1) {
            string += param_2;
        }
    }
    printf("%s\n", string);

    return 0;
}