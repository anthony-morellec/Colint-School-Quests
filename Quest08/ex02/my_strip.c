#include <stdlib.h>
#include <stdio.h>

char* my_strip(char* param_1)
{
    int e = 0;
    int i = 0;
    int check = 0;
    
    for (int index = 0; param_1[index] != 0; index++) {
        if ((param_1[index] != ' ' || param_1[index - 1] != 0 && param_1[index + 1] != ' ' && param_1[index + 1] != 0) && param_1[index] != 9) {
            for (int n = index; n > 0; n--) {
                if (param_1[n] == ' ') {
                    check++;
                }
            }
            if (check != index) {
                e++;
            }
        }
    }

    char* string = malloc(e);
    check = 0;
            
    for (int index = 0; param_1[index] != 0; index++) {
        if ((param_1[index] != ' ' || param_1[index - 1] != 0 && param_1[index + 1] != ' ' && param_1[index + 1] != 0) && param_1[index] != 9) {
            for (int n = index; n > 0; n--) {
                if (param_1[n] == ' ') {
                    check++;
                }
            }
            if (check != index) {
                string[i] = param_1[index];
                i++;
            }
        }
    }

    return string;
}

int main() {
    printf("%s", my_strip("\t\tworld\t"));

    return 0;
}