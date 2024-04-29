/*
 * E89 Pedagogical & Technical Lab
 * project:     chat
 * created on:  2024-04-28 - 00:44 +0200
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: stu_strcmp function
 */

int stu_strsemicmp(const char *s1, const char *s2)
{
    int compteur;

    compteur = 0;
    while (s1[compteur] != '\0') {
        if (s1[compteur] != s2[compteur]) {
            return (1);
        }
        compteur = compteur + 1;
    }
    return (0);
}
