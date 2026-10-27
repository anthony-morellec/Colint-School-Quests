#include <stdio.h>
#include <string.h>

int hidenp(char* param_1, char* param_2)
{
    if (strlen(param_1) <= strlen(param_2)) {
        int param_1dex = 0;
        
        for (int index = 0; index < strlen(param_2); index++) {
            if (param_1[param_1dex] == param_2[index]) {
                param_1dex++;
            }
        }

        if (param_1dex == strlen(param_1)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    printf("%d", hidenp("abcd", "abc"));

    return 0;
}