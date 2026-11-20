#include "AVL.h"
#include "Age.h"
#include "Annee.h"

int main(int argc, char *argv[]{

    if(strcmp(argv[1], "YEAR_DATA") == 0){
        Annee(argv[2]);
    }
    else if(strcmp(argv[1], "AGE_DATA") == 0){
        Age(argv[2]);
    }
    else if(strcmp(argv[1], "CRASH_DATA") == 0){
        AVL(argv[2]);
    }
    else{
        printf("Mode inconnu.    Réssayez avec "YEAR_DATA"; "AGE_DATA" ou "CRASH_DATA"\n");
    }

}
