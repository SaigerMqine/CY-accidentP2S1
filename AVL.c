pVic creerVictime(Victime vic) {        //crée une victime
    pVic nouv = malloc(sizeof(Vic));
    if(v == NULL){
        exit(1);
    }
    nouv->age = vic.age;
    nouv->type = vic.type;
    nouv->suivant = NULL;
    return nouv;
}

pVehicule creerVehicule(Victime vic) {        //crée un vehicule et rentre premiere victime
    pVehicule nouv = malloc(sizeof(Vehicule));
    if(v == NULL){
        exit(1);
    }
    nouv->ID = vic.idVehicule;
    nouv->trajet = vic.typeTrajet;
    nouv->victimes = creerVictime(vic);
    nouv->suivant = NULL;
    return nouv;
}

pArbre creerArbre(Victime vic){         //crée un noeud et rentre premier vehicule
    pArbre n = malloc(sizeof(Arbre));
    if(n == NULL){
        exit(1);
    }
    n->yearId = (vic.annee * 100000000) + vic.idCollision;
    n->vehicules = creerVehicule(vic);
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

int hauteur(pArbre a){
    if(a == NULL){
        return 0;
    }
    int hg = hauteur(a->fg);
    int hg = hauteur(a->fd);
    if(hg > hd){
        return 1 + hg;
    }
    else{
        return 1 + hd;
    }
}

int calcul_equilibre(pArbre a){
    if(a == NULL){
        return 0;
    }
    return hauteur(a->fd) - hauteur(a->fg);
}

void maj_equilibre(pArbre a){
    if(a != NULL){
        a->equilibre = calcul_equilibre(a);
}
