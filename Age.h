typedef struct {
  int femme;
  int homme;
  int autre;
}Genre;


typedef struct Chainon{
  int age;
  Genre conducteur;
  Genre passager;
  Genre pieton;
  struct Chainon * suivant;
}Chainon;



Chainon *creerChainonAge(int age) {
  Chainon *nouveau = malloc(sizeof(Chainon));
  if (nouveau == NULL) {
      printf("Erreur : allocation mémoire impossible (création chainon age)\n");
      exit(1);
  }

  nouveau->age = age;
  nouveau->suivant = NULL;

  nouveau->conducteur->homme = 0;
  nouveau->conducteur->femme = 0;
  nouveau->conducteur->autre = 0;

  nouveau->passager->homme = 0;
  nouveau->passager->femme = 0;
  nouveau->passager->autre = 0;

  nouveau->pieton->homme = 0;
  nouveau->pieton->femme = 0;
  nouveau->pieton->autre = 0;
  
  return nouveau;
}




    
