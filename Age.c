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




int ajouterAgeVictime(ChainonAge * debut, Victime victime){
//Verifier si age est un entier?
  
  if(victime->age < 0 || victime->age > 116){
    printf("L'âge n'est pas valide);    
    return 0;
  }else if(*debut==NULL){
      

    










