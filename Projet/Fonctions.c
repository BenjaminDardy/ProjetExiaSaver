#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int choix(int modulo){

 srand(time(NULL));
 int ran = 0;
 return ran = rand() %modulo;
 }


void execTerm1(int pbm){
switch (pbm){
  case 0:
    putenv("MONPBM=ex1.pbm");
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
    printf("probleme de choix de l'image");
    break;
  }

  chdir(getenv("EXIASAVER_HOME"));
  system("./T1");
}

void execTerm2()
{
	chdir(getenv("EXIASAVER_HOME"));
	system("./T2");
}
