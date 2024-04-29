#ifndef MAZE_H_
#define MAZE_H_

struct coordonnee {
    int column;
    int line;
    int position;
    int j;
    int distance;
    int *propa;
};

struct maze {
    int line;
    int column;
    char *buffer;
    int depart;
    int out;
    int way_out;
};

int print_base10(int nb);
void tc_putchar(char c);
int sortie(struct maze *way, struct coordonnee *start);
void goSouth(struct maze *way, struct coordonnee *start);
void goNorth(struct maze *way, struct coordonnee *start);
void goEast(struct maze *way, struct coordonnee *start);
void goWest(struct maze *way, struct coordonnee *start);

#endif
