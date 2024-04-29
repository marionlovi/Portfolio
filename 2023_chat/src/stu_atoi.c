/*
 * E89 Pedagogical & Technical Lab
 * project:     libstu
 * created on:  2024-02-05 - 09:47 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: stu_atoi function
 */

int stu_atoi(const char *str)
{
    int res;
    int count;
    int signe;

    count = 0;
    res = 0;
    signe = 1;
    while (str[count] == '-') {
        count = count + 1;
        signe = signe * -1;
    }
    while (str[count] >= '0' && str[count] <= '9') {
        res = (res * 10) + (str[count] - '0');
        count = count + 1;
    }
    return (res * signe);
}
