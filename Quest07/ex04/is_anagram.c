#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strdup(char* string) {
    char *copy = malloc(strlen(string));
    if (copy == NULL) return NULL;
    
    for (int index = 0; string[index] != 0; index++) {
        copy[index] = string[index];
    }

    return copy;
}

int is_anagram(char* param_1, char* param_2)
{
    if (strlen(param_1) == strlen(param_2)) {

        char *alpha_param1 = my_strdup(param_1);
        char *alpha_param2 = my_strdup(param_2);

        char stock;

        int follow = 0;
    
        for (int index = 1; index < strlen(alpha_param1); index++) {
            follow = 0;
            while (alpha_param1[index + follow] < alpha_param1[index - 1 + follow]) {
                stock = alpha_param1[index - 1 + follow];
                alpha_param1[index - 1 + follow] = alpha_param1[index + follow];
                alpha_param1[index + follow] = stock;
                follow--;
            }
        }

        for (int index = 1; index < strlen(alpha_param2); index++) {
            follow = 0;
            while (alpha_param2[index + follow] < alpha_param2[index - 1 + follow]) {
                stock = alpha_param2[index - 1 + follow];
                alpha_param2[index - 1 + follow] = alpha_param2[index + follow];
                alpha_param2[index + follow] = stock;
                follow--;
            }
        }

        int i;

        for (i = 0; alpha_param1[i] == alpha_param2[i] && alpha_param1[i] != 0; i++);

        if (i == strlen(alpha_param1)) {
            return 1;
        }

        free(alpha_param1);
        free(alpha_param2);
    }

    return 0;
}

int main() {
    printf("%d", is_anagram("aabbccd", "abcdabc"));

    return 0;
}