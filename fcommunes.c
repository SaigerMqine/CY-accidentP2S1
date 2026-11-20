int lire_ligne(File *f, victime *victime){
    FILE *f = fopen(f, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier");
        exit(1);
    }
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
