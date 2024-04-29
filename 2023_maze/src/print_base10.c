#include <unistd.h>
#include "maze.h"

void tc_putchar(char c) {
    write(1, &c, 1);
}

int nb_len(int nb)
{
    int c;

    c = 1;
    nb = (nb < 0) ? -nb : nb;
    while (nb >= 10) {
        nb /= 10;
        c++;
    }
    return (c);
}

int get_digit(int nb, int index)
{
    nb = (nb < 0) ? -nb : nb;
    while (index > 0) {
        nb = nb / 10;
        index--;
    }
    return (nb % 10);
}

int print_base10(int nb) {
    int result;
    int c;

    c = nb_len(nb);
    result = c - 1;
    if (nb < 0) {
        tc_putchar('-');
    } while (result >= 0) {
        tc_putchar(get_digit(nb, result) + '0');
        result--;
    }
    tc_putchar(' ');
    return(c);
}
