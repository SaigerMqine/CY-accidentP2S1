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
    maj_equilibre(a);
    maj_equilibre(temp);
    return temp;
}

pArbre RotationDroite(pArbre a){
    if(a == NULL || a->fg == NULL){
        return a;
    }
    pArbre temp = a->fg;
    a->fg = temp->fd;
    temp->fd = a;
    maj_equilibre(a);
    maj_equilibre(temp);
    return temp;
}

void insererVictime(pVehicule v, Victime vic) {        //ajoute une victime a un vehicule
    pVic nouv = creerVictime(vic);
    nouv->suivant = v->victimes;
    v->victimes = nouv;
}

void insererVehicule(pArbre a, Victime vic) {        //ajoute une un vehicule a un noeud
    pVehicule nouv = creerVehicule(vic);
    nouv->suivant = a->vehicules;
    a->vehicules = nouv;
}

pArbre insererAVL(pArbre a, Victime vic){
    if(a == NULL){
        return creerArbre(vic);
    }
    pArbre temp = a;
    if(temp->yearId == (vic.annee * 100000000) + vic.idCollision){
        pVehicule vtmp = temp->vehicules;
        while(vtmp != NULL){
            if(vtmp->ID == vic.idVehicule){
                vtmp->victimes = insererVictime(vtmp->victimes, vic);
                return a;
            }
            vtmp = vtmp->suivant;
        }
        a->vehicules = insererVehicule(a, vic);
        return a;
    }
    if(temp->yearId > (vic.annee * 100000000) + vic.idCollision){
            temp->fg = insererAVL(temp->fg, vic);
    }
    if(temp->yearId < (vic.annee * 100000000) + vic.idCollision){
        temp->fd = insererAVL(temp->fd, vic);
    }
    return reequilibrer(temp);
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
    int hd = hauteur(a->fd);
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

pArbre reequilibrer(pArbre a){
    if(a == NULL){
        return a;
    }
    maj_equilibre(a);
    if(a->equilibre == -2){
        if(calcul_equilibre(a->fg) > 0){
            return DoubleRotationDroite(a);
        }
        else{
            return RotationDroite(a);
        }
    }
    if(a->equilibre == 2){
        if(calcul_equilibre(a->fd) < 0){
            return DoubleRotationGauche(a);
        }
        else{
            return RotationGauche(a);
        }
    }
    return a;
}
