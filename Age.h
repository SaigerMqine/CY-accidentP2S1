typedef struct {
  int femme;
  int homme;
  int autre;
}Genre;


typedef struct Victime{
  int age;
  Genre conducteur;
  Genre passager;
  Genre pieton;
  struct Victime * suivant;
}Victime;



Victime *creerVictimeAge(int age);




    
