#include <stdio.h>

int my_iterative_factorial(int param_1)
{
    int fact = param_1;

    if (param_1 == 0) {
        return 1;
    }
    if (param_1 < 0) {
        return 0;
    }

    param_1--;
    
    while (param_1 > 0) {
        fact *= param_1;
        param_1--;
    }

    return fact;
}

int main() {
    printf("%d", my_iterative_factorial(13));

    return 0;
}