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


int categorieAge(int age){    //Bonus par tranche d'age
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




