int recup_ligne(FILE* f, Victime* victime){
	char ligne[512];
	if(fgets(ligne, sizeof(ligne), f) == NULL){
		printf("Erreur: fichier vide\n");
		return 0;
	}
	if(sscanf(ligne, "%d;%d;%d;%d;%d;%d;%d;%d;%d", &victime.annee, &victime.idCollision, &victime.idVehicule, &victime.localisation, &victime.typeUtilisateur, &victime.gravite, &victime.genre, &victime.naissance, &victime.typeTrajet) != 9){
			return -1
	}
	victime.age = victime.annee - victime.naissance;
	printf("Victime chargée avec succès");
	return 1;
}

Victime creer_victime(){
	Victime nouv;
	nouv.annee = 0;
	nouv.idCollision = 0;
	nouv.idVehicule = 0;
	nouv.localisation = 0;
	nouv.typeUtilisateur = 0;
	nouv.gravite = 0;
	nouv.genre = 0;
	nouv.naissance = 0;
	nouv.typeTrajet = 0;
	nouv.age = 0;
	return nouv;
}

int verifint(){            
	//verifie les int
    int d=0;
    char c;
    while(1){
        if(scanf("%d%c", &d, &c) == 2 && c ==  '\n' ){ 
            return d;
        }
        else{
            printf("L entree n est pas valide, tape un entier :'\n'");
            while ((c = getchar()) !=  '\n'  && c != EOF);
        }
    }
}
