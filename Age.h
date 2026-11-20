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
