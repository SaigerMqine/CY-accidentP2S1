#include "AVL.h"
#include "Age.h"
#include "Annee.h"

int main(int argc, char *argv[]{

    if(strcmp(argv[1], "YEAR_DATA") == 0){
        FILE *f = fopen ("cy_crash_tech_small_shuffled.csv", "r");
        if (f==NULL) {
            printf("Erreur ouverture fichier\n");
            exit(1);
        }
        Annee(argv[2]);
    }
    else if(strcmp(argv[1], "AGE_DATA") == 0){
        FILE *f = fopen ("cy_crash_tech_small_shuffled.csv", "r");
        if (f==NULL) {
            printf("Erreur ouverture fichier\n");
            exit(1);
        }
        Age(argv[2]);
    }
    else if(strcmp(argv[1], "CRASH_DATA") == 0){
        FILE *f = fopen ("cy_crash_tech_small_shuffled.csv", "r");
        if (f==NULL) {
            printf("Erreur ouverture fichier\n");
            exit(1);
        }
        AVL(argv[2]);
    }
    else{
        printf("Mode inconnu.    Réssayez avec "YEAR_DATA"; "AGE_DATA" ou "CRASH_DATA"\n");
    }

}
