void creationTableau(DonneesAnnees tab[], int TAILLE){
  
  for(int i = 0; i<TAILLE; i++){
      tab[i].accidents = 0;
      tab[i].indemnes = 0;
      tab[i].tues = 0;
      tab[i].graves = 0;
      tab[i].legers = 0;
  }
}


void afficherMenu(){
  do{
    printf("Saisir une annee a consulter (2005-2024) :\n");
    scanf(" %d", &
  while(
}
