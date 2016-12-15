#include <stdlib.h>
#include <stdio.h>

int main(){

//putenv("VERANDOM=VALEUR"); //int putenv("NAME=VALEUR")
printf("ma ve est égale à: %s\n", getenv("VERANDOM"));
return 0;
}
