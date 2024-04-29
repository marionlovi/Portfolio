#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include "stu.h"
#include "ls.h"

int weight_compare(char first_str, char second_str)
{
    int a;
    int b;

    a = first_str;
    b = second_str;
    if(a >= 97 && a <= 122) {
        a = a - 32;
    }
    if(b >= 97 && b <= 122) {
        b = b - 32;
    }
    if (a <= b) {
        return 0;
    } else {
        return 1;
    }
}

void swap(char **a, char **b)
{
    char *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int max_lenght(char *str_a, char *str_b)
{
    if (stu_strlen(str_a) < stu_strlen(str_b)) {
        return stu_strlen(str_b);
    } else {
        return stu_strlen(str_a);
    }
}

void strtab_sort(char **strtab)
{
    int i;
    int j;
    int index;
    int longer;

    j = 1;
    i = 0;
    if (strtab == NULL || strtab[0] == NULL) {
        return;
    }
    while (strtab[j] != NULL) {
        index = 0;
        longer = max_lenght(strtab[j], strtab[i]);
        while (index <= longer) {
            if (strtab[i][index] !=  strtab[j][index]) {
                if (weight_compare(strtab[i][index], strtab[j][index]) == 1) {
                    swap(&strtab[i], &strtab[j]);
                    i = -1;
                    j = 0;
                }
                index = longer;
            }
            index += 1;
        }
        j += 1;
        i += 1;
    }
}
