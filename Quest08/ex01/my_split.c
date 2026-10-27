#include <stdlib.h>
#include <stdio.h>

int my_strlen(char* str) {
    int length = 0;

    for (length = 0; str[length] != 0; length++);

    return length;
}

int nb_split(char* param_1, char* param_2) {
    int nb = 0;
    int check = 0;

    for (int index = 0; index < my_strlen(param_1); index++) {
        while (param_1[index + check] == param_2[check]) {
            check++;
        }
        if (param_1[index + 1] == 0) {
            check = my_strlen(param_2);
        }
        
        if (check == my_strlen(param_2)) {
            nb++;

            check = 0;
        }
    }
    
    return nb;
}

char** my_split(char* param_1, char* param_2)
{
    int arr_length = 0;
    int check = 0;
    int stringi = 0;
    int size = 0;
    char* string;
    char** arr = malloc(nb_split(param_1, param_2));

    for (int index = 0; index < my_strlen(param_1); index++) {
        check = 0;

        size++;

        while (param_1[index + check] == param_2[check] && param_1[index + check] != 0) {
            check++;
        }

        if (param_1[index + 1] == 0 && param_1[index] != param_2[check-1]) {
            check = my_strlen(param_2);
            size++;
        }

        if (check == my_strlen(param_2)) {
            string = malloc(size);

            for (int i = 0; i < size-1; i++) {
                string[i] = param_1[stringi];
                stringi++;
            }
            
            size = 0;
            stringi += check;
            index += check - 1;

            if (my_strlen(string) > 0) {
                arr[arr_length] = string;
                arr_length++;
            }
        }
    }

    return arr;
}

int main() {
    char** main_arr = my_split("abc def gh-!", " ");

    printf("%s\n", main_arr[2]);

    return 0;
}