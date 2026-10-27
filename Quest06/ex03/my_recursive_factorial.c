#include <stdio.h>

int my_recursive_factorial(int param_1)
{
    if (param_1 == 0) {
        return 1;
    }
    if (param_1 < 0) {
        return 0;
    }

    if (param_1 > 1) {
        return param_1 * my_recursive_factorial(param_1-1);
    }

    return param_1;
}

int main() {
    printf("%d", my_recursive_factorial(5));

    return 0;
}