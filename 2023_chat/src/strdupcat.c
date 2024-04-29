/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-15 - 14:53 +0200
 * 1st author:  tony.yam - tony.yam
 * description: strdupcat
 */

#include <stdlib.h>
#include "chat.h"

static unsigned int stu_strlen(const char *str)
{
    int counter;

    counter = 0;
    while (str[counter] != '\0') {
        counter = counter + 1;
    }
    return (counter);
}

static char *stu_strcpy(char *dest, const char *src)
{
    int counter;

    counter = 0;
    while (src[counter] != '\0') {
        dest[counter] = src[counter];
        counter = counter + 1;
    }
    dest[counter] = '\0';
    return (dest);
}

static char *stu_strcat(char *dest, char *src)
{
    int cntr_dest;
    int cntr_src;

    cntr_dest = stu_strlen(dest);
    cntr_src = 0;
    while (src[cntr_src] != '\0') {
        dest[cntr_dest] = src[cntr_src];
        cntr_dest = cntr_dest + 1;
        cntr_src = cntr_src + 1;
    }
    dest[cntr_dest] = '\0';
    return (dest);
}

char *strdupcat(char *str1, char *str2)
{
    int len1;
    int len2;
    char *big_str;

    len1 = stu_strlen(str1);
    len2 = stu_strlen(str2);
    big_str = malloc((len1 + len2) * sizeof(char) + 1);
    if (!big_str){
        return (NULL);
    }
    stu_strcpy(big_str, str1);
    stu_strcat(big_str, str2);
    return (big_str);
}
