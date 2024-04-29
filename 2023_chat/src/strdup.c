/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_chat
 * created on:  2024-04-24 - 16:34 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: strdup function
 */

#include <stddef.h>
#include <stdlib.h>
#include "dprint.h"
#include "chat.h"

char *stu_strdup(char *str)
{
    char *new;

    new = malloc((stu_strlen(str) * sizeof(char)) + 1);
    if (!new) {
        return (NULL);
    }
    return (stu_strcpy(new, str, stu_strlen(str)));
}
