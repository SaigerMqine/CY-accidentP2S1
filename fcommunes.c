Victime recup_ligne(char* nom_fichier){
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier");
        exit(1);
    }
	
	Victime victime = creer_victime();

	char ligne[512];
	if(fgets(ligne sizeof(ligne), ) == NULL){
		printf("Erreur: fichier vide\n);
		fclose(f);
		exit(10);
	}

	while(fgets(ligne, sizeof(ligne), f) != NULL){

		if(scanf(ligne, "%d;%d;%d;%d;%d;%d;%d;%d;%d", &victime.annee, &victime.idCollision, &victime.idVehicule, &victime.localisation, &victime.typeUtilisateur, &victime.gravite, &victime.genre, &victime.naissance, &victime.typeTrajet) == 9){
			victime.age = victime.annee - victime.naissance;
			fclose(f);
			printf("Victime chargée avec succès");
			return victime;
		}
	}	
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
