Victime* recup_ligne(char* nom_fichier, int annee, victime *victime){
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier");
        exit(1);
    }
	
	Victime victime = creer_victime();
	
	if (fscanf(f, "year;%d\n\n", &victime.annee) != 1) {
        printf("Erreur de format : année introuvable\n");
        fclose(f);
        exit(2);
    }
	fclose(f);
	return victime;
	
}

Victime creer_victime(){
	Victime nouv;
	nouv.annee = 0;
	nouv.idCollision = 0;
	nouv.localisation = 0;
	nouv.idVehicule = 0;
	nouv.typeUtilisateur = 0;
	nouv.gravite = 0;
	nouv.naissance = 0;
	nouv.typeTrajet = 0;
	nouv.age = 0;
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
