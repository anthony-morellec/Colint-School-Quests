#include <stdio.h>
#include <stdlib.h>

int* my_range(int param_1, int param_2)
{
    int min = param_1;
    int max = param_2;
    int range = max - min;

    if (min < max) {
        printf("[");
        for (int i = 0; i < range - 1; i++) {
            printf("%d, ", min);
            min++;
        }
    }
    printf("%d]", min);
    return 0;
}

int main(int ac, char **av) {
    if (ac == 3 && atoi(av[1]) < atoi(av[2])) {
        my_range(atoi(av[1]), atoi(av[2]));
    }
    else {
        printf("invalid input");
    }
    return 0;
}