#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* my_union(char* param_1, char* param_2)
{
    char *string = malloc(strlen(param_1));
    int check;
    int str = 0;

    for (int index = 0; index < strlen(param_1); index++) {
        check = 0;

        for (int i = 0; i < strlen(string); i++) {
            if (param_1[index] != string[i]) {
                check++;
            }
        }

        if (check == strlen(string)) {
            string[str] = param_1[index];
            str++;
        }
    }

    for (int index2 = 0; index2 < strlen(param_2); index2++) {
        check = 0;
        
        for (int i2 = 0; i2 < strlen(string); i2++) {
            if (param_2[index2] != string[i2]) {
                check++;
            }
        }

        if (check == strlen(string)) {
            string[str] = param_2[index2];
            str++;
        }
    }

    return string;
}

int main() {
    printf("%s", my_union("zpadinton", "paqefwtdjetyiytjneytjoeyjnejeyj"));

    return 0;
}