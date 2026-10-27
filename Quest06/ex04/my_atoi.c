#include <stdio.h>

int my_atoi(char* param_1)
{
    int index = 0;
    int atoi = 0;

    if (param_1[0] == '+' || param_1[0] == '-') {
            index++;
    }

    while (param_1[index] != 0) {
        if (param_1[index] >= '0' && param_1[index] <= '9') {
            atoi *= 10;
            atoi += param_1[index] - '0';
        }
        else {
            if (param_1[0] != ' ') {
                return atoi;
            }
        }
        index++;
    }
    if (param_1[0] == '-') {
        atoi = -atoi;
    }

    return atoi;
}

int main() {
    printf("%d", my_atoi("+42abc"));

    return 0;
}