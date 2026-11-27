#ifndef annee_h
#define annee_h
#define TAILLE 20

typedef struct{
  int indemnes;
  int accidents;
  int tues;
  int graves;
  int legers;
}DonneesAnnee;

void creationTableau(DonneesAnnee tab[]);

void executerModeAnnee(const char* nomFichier);

int chargerDonnees(const char* nomFichier, DonneesAnnee tab[]);

void afficherMenuAnnee(DonneesAnnee tab[]);

#endif
