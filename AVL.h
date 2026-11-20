#include <stdio.h>
#include <stdlib.h>

typedef struct Arbre{
    int v;
    struct Arbre *fg;
    struct Arbre *fd;
    int equilibre;
}Arbre;

typedef Arbre *pArbre;
