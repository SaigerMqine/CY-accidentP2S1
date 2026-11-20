Victime recup_ligne(char* nom_fichier, int annee){
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier");
        exit(1);
    }
	
	Victime victime = creer_victime();
	
	if (fscanf(f, "year;%d\n\n", &victime.annee) != 1){
        printf("Erreur de format : année introuvable\n");
        fclose(f);
        exit(2);
    }

	if (fscanf(f, "collision id;%d\n\n", &victime.idCollision) != 1){
        printf("Erreur de format : collision id introuvable\n");
        fclose(f);
        exit(3);
    }

	if (fscanf(f, "vehicule id;%d\n\n", &victime.idVehicule) != 1){
        printf("Erreur de format : vehicule id introuvable\n");
        fclose(f);
        exit(4);
    }
	
	if (fscanf(f, "location;%d\n\n", &victime.localisation) != 1){
        printf("Erreur de format : localisation introuvable\n");
        fclose(f);
        exit(4);
    }

	if (fscanf(f, "user type;%d\n\n", &victime.typeUtilisateur) != 1){
        printf("Erreur de format : type d'utilisateur introuvable\n");
        fclose(f);
        exit(4);
    }

	if (fscanf(f, "severity;%d\n\n", &victime.gravite) != 1){
        printf("Erreur de format : gravite introuvable\n");
        fclose(f);
        exit(4);
    }

	if (fscanf(f, "gender;%d\n\n", &victime.genre) != 1){
        printf("Erreur de format : genre introuvable\n");
        fclose(f);
        exit(4);
    }

	if (fscanf(f, "birth year;%d\n\n", &victime.naissance) != 1){
        printf("Erreur de format : naissance introuvable\n");
        fclose(f);
        exit(4);
    }

	if (fscanf(f, "purpose;%d\n\n", &victime.typeTrajet) != 1){
        printf("Erreur de format : type de trajet introuvable\n");
        fclose(f);
        exit(4);
    }

	victime.age = victime.annee - victime.naissance;
	fclose(f);
	printf("Victime chargée avec succès");
	return victime;
	
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
