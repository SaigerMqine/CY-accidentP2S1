#include <stdio.h>
#include <stdlib.h>

typedef struct Arbre{
    int v;
    struct Arbre *fg;
    struct Arbre *fd;
    int equilibre;
}Arbre;

typedef Arbre *pArbre;

pArbre creerArbre(int a){
    pArbre n = malloc(sizeof(Arbre));
    if(n == NULL){
        exit(1);
    }
    n->v = a;
    n->equilibre = 0;
    n->fg = NULL;
    n->fd = NULL;
    return n;
}

pArbre RotationGauche(pArbre a){
    if(a == NULL || a->fd == NULL){
        return a;
    }
    pArbre temp = a->fd;
    a->fd = temp->fg;
    temp->fg = a;
    return temp;
}

pArbre RotationDroite(pArbre a){
    if(a == NULL || a->fg == NULL){
        return a;
    }
    pArbre temp = a->fg;
    a->fg = temp->fd;
    temp->fd = a;
    return temp;
}

int insertABR(pArbre a, int e){
    if(a == NULL){
        return 0;
    }
    pArbre temp = a;
    if(temp->v == e){
        printf("le noeud exite deja");
        return 0;
    }
    if(e < temp->v){
        if(temp->fg == NULL){
            temp->fg = creerArbre(e);
            return 1;
        }
        return(insertABR(temp->fg, e));
    }
    if(e > temp->v){
        if(temp->fd == NULL){
            temp->fd = creerArbre(e);
            return 1;
        }
        return(insertABR(temp->fd, e));
    }
    return 0;
}

void parcoursPrefixe(pArbre a){
    if(a != NULL){
        printf("%d ", a->v);
        parcoursPrefixe(a->fg);
        parcoursPrefixe(a->fd);
    }
}

pArbre DoubleRotationDroite(pArbre a){
    if(a == NULL || a->fg == NULL){
        return a;
    }
    a->fg = RotationGauche(a->fg);
    a = RotationDroite(a);
    return a;
}

pArbre DoubleRotationGauche(pArbre a){
    if(a == NULL || a->fd == NULL){
        return a;
    }
    a->fd = RotationDroite(a->fd);
    a = RotationGauche(a);
    return a;
}

void parcoursLargeur(pArbre a) {
    if (a == NULL) {
        return;
    }
    pArbre file[1000];
    int debut = 0;
    int fin = 0;
    file[fin++] = a;
    while (debut < fin) {
        pArbre courant = file[debut++];
        printf("%d ", courant->v);
        if (courant->fg != NULL) {
            file[fin++] = courant->fg;
        }
        if (courant->fd != NULL) {
            file[fin++] = courant->fd;
        }
    }
}
