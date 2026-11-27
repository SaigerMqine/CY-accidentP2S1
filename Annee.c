#include "annee.h"
void creationTableau(DonneesAnnees tab[], int TAILLE){
  
  for(int i = 0; i<TAILLE; i++){
      tab[i].accidents = 0;
      tab[i].indemnes = 0;
      tab[i].tues = 0;
      tab[i].graves = 0;
      tab[i].legers = 0;
  }
}


void afficherMenuAnnee(DonneesAnnee tab[]){
  int annee = 0;
  do{
    printf("Saisir une annee a consulter (2005-2024) ou 0 pour quitter :\n");
    if( scanf(" %d", &annee) != 1){
      printf("Erreur : veuillez saisir un nombre.\n");
      annee = -1;
      while (getchar() != '\n');
    }
    else{
    if(annee>=2005 && annee<=2024){
      int indice = annee - 2005;
      printf("%d accidents\n", tab[indice].accidents);
      printf("%d indemnes\n", tab[indice].indemnes);
      printf("%d tues\n", tab[indice].tues);
      printf("%d blesses graves\n", tab[indice].graves);
      printf("%d blesses legers\n", tab[indice].legers);
  }
    else if(annee!=0){
      printf("Erreur : Saisir une annee entre (2005-2024).\n");
  }
  }
  }
  while(annee!=0);
}

void executerModeAnnee(const char* nomFichier){
DonneesAnnee tab[TAILLE];
creationTableau(tab);
if( chargerDonnees(nomFichier, tab) != -1){
afficherMenuAnnee(tab);
}
}



