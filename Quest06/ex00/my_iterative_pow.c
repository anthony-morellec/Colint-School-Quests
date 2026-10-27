#include <stdio.h>

int my_iterative_pow(int param_1, int param_2)
{
    int pow = 0;
    if (param_2 == 0) {
        pow = 1;
    }
    else
    {
        if(param_2 > 0) {
            pow = param_1;
            for (int i = 1; i < param_2; i++) {
                pow *= param_1;
            }
        }
    }

    return pow;
}

int main() {
    printf("%d", my_iterative_pow(0, 0));

    return 0;
}