typedef struct victime{
  int annee;  
  int idCollision;
  int idVehicule;
  int localisation;
  int typeUtilisateur;
  int gravite;
  int genre;
  int naissance;
  int typeTrajet;
  int age;
}



int lire_ligne(File *file, victime *victime);
void messageErreur();

//Affichage commun//


  

