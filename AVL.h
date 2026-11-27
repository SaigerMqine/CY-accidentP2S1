#include <stdio.h>
#include <stdlib.h>

typedef struct Vic{
    int age;
    int type;
    struct Vic* suivant;
}Vic;

typedef Vic* pVic;

typedef struct Vehicule{
    int ID;
    int trajet;
    pVic victimes;
    struct Vehicule* suivant;
}Vehicule;

typedef Vehicule* pVehicule;

typedef struct Arbre{
    long yearId;
    int equilibre;
    pVehicule vehicules;
    struct Arbre *fg;
    struct Arbre *fd;
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
