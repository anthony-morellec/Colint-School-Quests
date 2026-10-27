#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* my_union(char* param_1, char* param_2)
{
    char *string = malloc(strlen(param_1));
    int check;
    int yes;
    int str = 0;

    for (int index = 0; index < strlen(param_1); index++) {
        check = 0;
        yes = 0;

        for (int i = 0; i < strlen(string); i++) {
            if (param_1[index] != string[i]) {
                check++;
            }
        }

        for (int d = 0; d < strlen(param_2); d++) {
            if (param_1[index] == param_2[d]) {
                yes++;
            }
        }

        if (check == strlen(string) && yes > 0) {
            string[str] = param_1[index];
            str++;
        }
    }

    return string;
}

int main() {
    printf("%s", my_union("ddf6vewg64f", "gtwthgdwthdwfteewhrtag6h4ffdhsd"));

    return 0;
}