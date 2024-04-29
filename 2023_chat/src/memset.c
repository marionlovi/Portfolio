/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-28 - 19:06 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: memset function
 */

int stu_memset(char *str, int nb)
{
    int i;

    i = 0;
    while (i < nb) {
        str[i] = '\0';
        i = i + 1;
    }
    return (0);
}
