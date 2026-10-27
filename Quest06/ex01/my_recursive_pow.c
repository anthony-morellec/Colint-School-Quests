#include <stdio.h>

int my_recursive_pow(int param_1, int param_2)
{
    if (param_2 > 1) {
        printf("%d\n", param_1);
        return param_1 * my_recursive_pow(param_1, param_2-1);
    }
    else
    {
        if(param_2 == 0) {
            return 1;
        }
        if(param_2 < 0) {
            return 0;
        }
    }
    
    return param_1;
}

int main() {
    printf("%d", my_recursive_pow(3, -1));

    return 0;
}