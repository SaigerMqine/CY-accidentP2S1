#include <stdio.h>
#include <stdlib.h>

typedef struct Arbre{
    int v;
    struct Arbre *fg;
    struct Arbre *fd;
    int equilibre;
}Arbre;

typedef Arbre *pArbre;

pArbre creerArbre(int a);
pArbre RotationGauche(pArbre a);
pArbre RotationDroite(pArbre a);
int insertABR(pArbre a, int e);
void parcoursPrefixe(pArbre a);
pArbre DoubleRotationDroite(pArbre a);
pArbre DoubleRotationGauche(pArbre a);
void parcoursLargeur(pArbre a);
