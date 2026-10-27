#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* rcapitalize(char* param_1)
{
    char *string = malloc(strlen(param_1));

    for (int index = 0; index < strlen(param_1); index++) {

        if (param_1[index] >= 'a' && param_1[index] <= 'z' && (param_1[index+1] == ' ' || param_1[index + 1] == 0 || param_1[index + 1] == 9)) {
            string[index] = (param_1[index] - 32);
        }
        else {
            if (param_1[index] >= 'A' && param_1[index] <= 'Z' && param_1[index+1] != ' ' && param_1[index + 1] != 0 && param_1[index + 1] != 9) {
                string[index] = (param_1[index] + 32);
            }
            else {
                string[index] = param_1[index];
            }
        }
    }
    
    return string;
}

int main() {
    printf("%s", rcapitalize("hello\tworld"));

    return 0;
}