typedef struct {
  int femme;
  int homme;
  int autre;
}Genre;


typedef struct ChainonAge{
  int age;
  Genre conducteur;
  Genre passager;
  Genre pieton;
  struct ChainonAge * suivant;
}ChainonAge;



ChainonAge *creerVictimeAge(int age);




    
