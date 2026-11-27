ChainonAge *creerChainonAge(int age) {
  ChainonAge *nouveau = malloc(sizeof(ChainonAge));
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


int categorieAge(int age){    //Bonus par tranche d'age
  //Si age pas valide?
  if(age<13){
    return 1;     //Catégorie 1 = Enfance (0-12ans)
  }else if(age<18){
    return 2;      //Catégorie 2 = Adolescence(13-17ans)
  }else if(age<26){
    return 3;     //Catégorie 3 = Jeune adulte (18-25ans)
  }else if(age<41){
    return 4;     //Catégorie 4 = Adulte 1 (26-40)
  }else if(age<61){
    return 5;    //Catégorie 5 = Adulte 2 (41-60)
  }else if(age<81){
    return 6;     //Catégorie 6 = Sénior 1 (61-80)
  }else {
    return 7;    //Catégorie 7 = Senior 2 (81 et plus)
  }
}

void compterVictime(ChainonAge *statAge, int genre, int typeUtilisateur){    //mets la victme dans la bonne cas (ex : femme piétonne)
  if( typeUtilisateur = 1){
    if(genre = 1){
      ++statAge->conducteur->homme;
    }else if(genre = 2){
      ++statAge->conducteur->femme;
    }else{
      ++statAge->conducteur->autre;
    }
  }else if( typeUtilisateur = 2){
    if(genre = 1){
      ++statAge->passager->homme;
    }else if(genre = 2){
      ++statAge->passager->femme;
    }else{
      ++statAge->passager->autre;
    }
  }else{
    if(genre = 1){
      ++statAge->pieton->homme;
    }else if(genre = 2){
      ++statAge->pieton->femme;
    }else{
      ++statAge->pieton->autre;
    }
  }
}




void ajouterAgeVictime(ChainonAge ** debut, Victime victime){    //Double pointeur car la tête de liste peut changer (ex : l'age de la victime est inférieur à celui des victimes précedentes)
     //Verifier si age est un entier?//
  ChainonAge * courant = NULL;
  ChainonAge * nouveau = NULL;
  if(victime.age < 0 || victime.age > 130){  //Copie donc pas victime->age
    printf("L'âge n'est pas valide\n");    
    return;
  }else if(*debut == NULL|| victime.age < (*debut)->age) {
    nouveau = creerChainonAge(victime.age);
    nouveau->suivant = *debut;    
    *debut = nouveau;               
    compterVictime(nouveau, victime.typeUtilisateur, victime.genre);
    return;
  }else{
    courant = *debut;
    while (courant->suivant != NULL && courant->suivant->age <= victime.age) {
        courant = courant->suivant;
    }
    if (courant->age == victime.age) {
        compterVictime(courant, victime.typeUtilisateur, victime.genre);
    }else{
      nouveau = creerChainonAge(victime.age);
      nouveau->suivant = courant->suivant; 
      courant->suivant = nouveau;            
      compterVictime(nouveau, victime.typeUtilisateur, victime.genre);
    }
  }
}
    
      

    










