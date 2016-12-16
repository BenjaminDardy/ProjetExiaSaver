#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "Fonctions.h"
#include <string.h>
#include <time.h>
#include "entree.h"
#include <ctype.h>

/*-----------------------------------------------Historique----------------------------------------------------------*/

void affichageStats(Input input[]);

void ecritureHistorique(int type, int tab) {
    FILE *fichier = NULL;
    fichier = fopen("historique.txt", "a");// ouvre le fichier texte ou l'on va stocker l'historique
    if (fichier != NULL) {
        time_t temps; //permet de recuperer l'heure
        struct tm date;
        char format[22];
        time(&temps);
        date = *localtime(&temps);
	type = type -48;
        strftime(format, 22, "%Y/%m/%d %X", &date); //affichage AAAA/MM/JJ/HH:MM:SS
        fprintf(fichier, "%s  type %d  %d\n", format, type, tab); // Pour ecrire dans le fichier de la façon Date heure type et nom fichier
        fclose(fichier); // ferme le fichier texte ouvert
    } else {
        printf("Un probleme est survenu avec le fonction stat");
    }

}

/*--------------------------------------------Statistique-------------------------------------*/

void lectureHistorique(Input input[]) {
    FILE *fichier = NULL;
    fichier = fopen("historique.txt", "r"); // ouvre le fichier historique
    if (fichier != NULL) {
        char log[50] = "";
        int i = 0;
        while (fgets(log, 50, fichier) != NULL) { //recupere chaque ligne de l'historique
            strcpy(input[i].date, strtok(log, " ")); //lit la date
            strcpy(input[i].heure, strtok(NULL, "  ")); //lit l'heure
            strtok(NULL, "  "); //permet d eviter le "typy" qui est ecrit dans le .txt
            strcpy(input[i].type, strtok(NULL, "  ")); //lit le type
            strcpy(input[i].parametre, strtok(NULL, "  ")); //lit le nom du fichier ouvert pour le statique
            i++;
        }
    }
    fclose(fichier); //ferme le fichier historique
}

void triDate(Input input[]) {
    int i = 0, tri = 0;
    while (tri == 0) { //Permet de trier tant qu'il faut trier et s arrete une fois que tout est trie
        tri = 1;
        for (i = 0; i < 100; i++) {
            if (strcmp(input[i].date, input[i + 1].date) > 0) { //Compare les dates de 2 lignes et si elles sont differentes on inverse les informations
                char echangeDate[11]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeDate, input[i].date); //Variable tampon qui va permettre l echange des donnes
                strcpy(input[i].date, input[i + 1].date); //Met la variable a echanger dans le tampon
                strcpy(input[i + 1].date, echangeDate); //Met la variable du tampon a sa place

                char echangeHeure[11]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeHeure, input[i].heure); //Variable tampon qui va permettre l echange des donnes
                strcpy(input[i].heure, input[i + 1].heure); //Met la variable a echanger dans le tampon
                strcpy(input[i + 1].heure, echangeHeure); //Met la variable du tampon a sa place

                char echangeType[6]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeType, input[i].type); //Variable tampon qui va permettre l echange des donnes
                strcpy(input[i].type, input[i + 1].type); //Met la variable a echanger dans le tampon
                strcpy(input[i + 1].type, echangeType); //Met la variable du tampon a sa place

                char echangeParametre[10]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeParametre, input[i].parametre); //Variable tampon qui va permettre l echange des donnes
                strcpy(input[i].parametre, input[i + 1].parametre); //Met la variable a echanger dans le tampon
                strcpy(input[i + 1].parametre, echangeParametre); //Met la variable du tampon a sa place
                tri = 0;
            }
        }
    }
    affichageStats(input); //Affiche le tri une fois qu il est fini
}

void triHeure(Input input[]) {
    int k = 0, trie = 0;
    while (trie == 0) { //Permet de trier tant qu'il faut trier et s arrete une fois que tout est trie
        trie = 1;
        for (k = 0; k < 100; k++) {
            if (strcmp(input[k].heure, input[k + 1].heure) > 0) { //Compare les heures de 2 lignes et si elles sont differentes on inverse les informations
                char echangeDate[11]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeDate, input[k].date); //Met la variable a echanger dans le tampon
                strcpy(input[k].date, input[k + 1].date); //Met la variable la plus petite dans la variable la plus grande
                strcpy(input[k + 1].date, echangeDate); //Met la variable du tampon a sa place

                char echangeHeure[11]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeHeure, input[k].heure); //Variable tampon qui va permettre l echange des donnes
                strcpy(input[k].heure, input[k + 1].heure); //Met la variable a echanger dans le tampon
                strcpy(input[k + 1].heure, echangeHeure); //Met la variable du tampon a sa placev

                char echangeType[6]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeType, input[k].type); //Variable tampon qui va permettre l echange des donnes
                strcpy(input[k].type, input[k + 1].type); //Met la variable a echanger dans le tampon
                strcpy(input[k + 1].type, echangeType); //Met la variable du tampon a sa place

                char echangeParametre[10]; //Variable tampon qui va permettre l echange des donnes
                strcpy(echangeParametre, input[k].parametre); //Variable tampon qui va permettre l echange des donnes
                strcpy(input[k].parametre, input[k + 1].parametre); //Met la variable a echanger dans le tampon
                strcpy(input[k + 1].parametre, echangeParametre); //Met la variable du tampon a sa place
                trie = 0;
            }
        }
    }
    affichageStats(input); //Affiche le tri une fois qu il est fini
}

void affichageStats(Input input[]) { //Fonction permettant d afficher les differents lignes
    int i;
    for (i = 0; i < 100; i++) {
        printf("%s  ", input[i].date);
        printf("%s  ", input[i].heure);
        printf("%s  ", input[i].type);
        printf("%s  ", input[i].parametre);
        printf("\n  ");
    }
}

void compteur(Input input[], int choice) {
    int i, type1 = 0, type2 = 0, type3 = 0, total=0;
    for (i = 0; i < 100; i++) {
        switch ((int) input[i].type[0]) {
            case 49: //code ASCII pour 1
                type1++;
                break;
            case 50:
                type2++;
                break;
            case 51:
                type3++;
                break;
        }
    }
    switch (choice) {
        case 1:
            printf("type 1: %d , type 2 : %d , type 3 : %d \n", type1, type2, type3);
            break;
        case 2:
            total = type1 + type2 + type3;
            printf("Sur un total de %d execution, il y a eu %d pourcent de type statique, %d pourcent de type dynamique et %d pourcent de type interactif\n",total, ((type1*100)/total),((type2*100)/total),((type3*100)/total));
            break;

    }
}

/*-----------------------------------------------------VE-----------------------------------------------*/

void declarationVE(){

  setenv("EXIASAVER_HOME","/home/max/Documents/Projet/Terms", 0);
  setenv("EXIASAVER1_PBM","/home/max/Documents/Projet/Terms/Term1", 0);
  setenv("EXIASAVER2_SLEEP","10", 0);
  setenv("EXIASAVER2_PBM","/home/benjamin/Projet/Terms/Term2", 0);
}

 


int main(int argc, char *argv[]){

	system("clear"); //Nettoyage de la console
	declarationVE();
	int randpbm = 0;
	int randTerm = choix(2); //appel de la fonction choisissant quel terminal sera exécuté
	int choice=0;
	int typeEcrit;
	int parametreEcrit;
	char stat_verif[] = "-stats";
	int valeur_verif = 0;
	Input newInput[100] = {0};
//ecritureHistorique(typeEcrit, parametreEcrit); //Ecriture des differents parametres dans l historique

/*------------------------------------------------MenuStats------------------------------------------------*/
if(argv[1] != NULL)
	{
	valeur_verif = strcmp(argv[1], stat_verif);
		if(valeur_verif == 0)
		{
	lectureHistorique(newInput); //Lecture des parametres ecrits dans l historique
	printf("Veuillez saisir l'option desiree:\n 1 pour afficher l historique trie par date\n 2 pour afficher l historique trie par heure\n 3 pour afficher les nombres d'executions de chaque type\n 4 pour afficher les statistiques d'executions de chaque type\n"); //Affiche un menu pour que l utilisateur sache quels sont les statistiques qu il souhaite afficher
    scanf("%d",&choice); //Demande a l utilisateur quelle statistique il veut afficher
    switch(choice){ //Permet de faire la difference entre les choix de l ulisateur
        case 1: //Va lancer la fonction qui tri en fct de la date et affiche ce tri
            triDate(newInput);
            break;
        case 2: //Va lancer la fonction qui tri en fct de l heure et affiche ce tri
            triHeure(newInput);
            break;
        case 3: //Va lancer la fonction qui compte combien de fois a ete lance chaque type
            compteur(newInput,1);
            break;
        case 4: //Va lancer la fonction qui compte combien de fois a ete lance chaque type et en tire des pourcentages
            compteur(newInput,2);
            break;
    		  }
	    return 0;
	       }
 	}
else 
{
switch (randTerm){
  case 0:  //Term1 choisi
    randpbm = choix(5);// CHOIX DE L'IMAGE
    break;
  /*case 2:   //Term3 choisi
    randpbm = choix(4);
    break;*/
  default:
    break;
 }

 switch(randTerm){
  case 0:
    typeEcrit = '1';
    parametreEcrit = randpbm+1;
    ecritureHistorique(typeEcrit, parametreEcrit); //Ecriture des differents parametres dans l historique
    execTerm1(randpbm);
    break;
  case 1:
    typeEcrit = '2';
    ecritureHistorique(typeEcrit, parametreEcrit); //Ecriture des differents parametres dans l historique
    execTerm2(); //enlever printf
    break;
  case 2:
    printf("execTerm3()\n"); //pareil
    break;
  default:
    printf("Erreur: Valeur de randTerm non valide");
    break;
}
}
return 0;
}
