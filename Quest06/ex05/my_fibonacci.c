#include <stdio.h>

int my_fibonacci(int param_1)
{
    int suite = 0;
    int suite0 = 0;
    int suite1 = 1;

    for (int index = 0; index <= param_1; index++) {
        switch (index) {
            case 0:
                suite = suite0;
                break;
            case 1:
                suite = suite1;
                break;
            default:
                suite = suite0 + suite1;
                suite0 = suite1;
                suite1 = suite;
                break;
        }
    }

    if (param_1 < 0) {
        suite = -1;
    }

    return suite;
}

int main() {
    printf("b : %d", my_fibonacci(5));

    return 0;
}