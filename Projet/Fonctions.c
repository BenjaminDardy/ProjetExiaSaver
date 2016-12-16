#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int choix(int modulo){	//fonction de génération aléatoire

 srand(time(NULL));       
 int ran = 0;
 return ran = rand() %modulo;	//renvoie un int désignant l'élement choisi
 }


void execTerm1(int pbm){	//Fonction d'execution du TermSaver statique selon l'image choisi par fonction "choix"
switch (pbm){
  case 0:
    putenv("MONPBM=ex1.pbm");	//MONPBM est une variable d'environempent désignant le fichier de l'image
    break;
  case 1:
    putenv("MONPBM=ex2.pbm");
    break;
  case 2:
    putenv("MONPBM=ex3.pbm");
    break;
  case 3:
    putenv("MONPBM=ex4.pbm");
    break;
  case 4:
    putenv("MONPBM=ex5.pbm");
    break;
  default:
    printf("probleme de choix de l'image");	//Si aucune image n'a été choisi (improbable)
    break;
  }

  chdir(getenv("EXIASAVER_HOME"));	//On se place dans le répertoire où se trouvent les executable
  system("./T1");			//Lancement de l'executable T1 lançant le TermSaver1
}

void execTerm2()			//Fonction d'execution du TermSaver dynamique
{
	chdir(getenv("EXIASAVER_HOME"));
	system("./T2");	
}
