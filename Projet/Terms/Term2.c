#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define TAILLE_MAX 80

int affichageHorloge()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant=*localtime(&secondes);
	int TimeS1 = (instant.tm_sec)/10; //Calcule la dizaine des secondes
	int TimeS2 = (instant.tm_sec)-(TimeS1*10); //Calcule l unite des secondes
	int TimeM1 = (instant.tm_min)/10; //Calule la dizaine des minutes
	int TimeM2 = (instant.tm_min)-(TimeM1*10); //Calcule l unite des minutes
	int TimeH1 = (instant.tm_hour)/10; //Calcule la dizaine des heures
	int TimeH2 = (instant.tm_hour)-(TimeH1*10); //Calcule l unite des heures

	int Time[8];
	Time[0] = TimeH1; //Affecte la dizaine des heures a une case du tableau
	Time[1] = TimeH2; //Affecte l unite des heures a une case du tableau
	Time[2] = 10;
	Time[3] = TimeM1; //Affecte la dizaine des minutes a une case du tableau
	Time[4] = TimeM2;
	Time[5] = 10;
	Time[6] = TimeS1; //Affecte la dizaine des secondes a une case du tableau
	Time[7] = TimeS2;
	
	int z = 0;
	int TailleFich = 1;

	//printf("Horloge --> %u%u : %u%u : %u%u\n",TimeH1 ,TimeH2,TimeM1 ,TimeM2,TimeS1 ,TimeS2);

	//system("clear"); // fonction qui nettoie la console.

		int y=40-((4+TailleFich*2)*3+5), x=6;
	    	int i = 0, j = 0; // declaration de deux variable pour les boucles.
	    	FILE* fichier = NULL; //initialisation du pointeur a NULL
	    	char chaine[TAILLE_MAX];
	    	int chaine2[2];
	    	int a,b;

	for (z=0; z<8; z++)
	{
		switch(Time[z])
		{
			case 0:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/0.pbm", "r");
				break;
			case 1:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/1.pbm", "r");
				break;
			case 2:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/2.pbm", "r");
				break;
			case 3:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/3.pbm", "r");
				break;
			case 4:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/4.pbm", "r");
				break;
			case 5:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/5.pbm", "r");
				break;	
			case 6:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/6.pbm", "r");
				break;
			case 7:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/7.pbm", "r");
				break;
			case 8:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/8.pbm", "r");
				break;
			case 9:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/9.pbm", "r");
				break;
			case 10:
				fichier = fopen("/home/benjamin/Projet/Terms/Term2/:.pbm", "r");
				break;
		}
		
	    	if (fichier != NULL) // vérification de l'ouverture du fichier
	    	{
			fseek(fichier, 3, SEEK_SET);
			fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]);
			a = chaine2[0];
			b = chaine2[1];
			a = (a*2)-1;
	 
			fseek(fichier, 1, SEEK_CUR);
			for(i=0; i<b; i++) // boucle qui va parcourir les lignes
			{	
				gotoxy(x,y);
		    		fgets(chaine, TAILLE_MAX, fichier); // recuperation de la ligne
		    		for(j=0;j<a;j++) // boucle qui parcourt la ligne
		    		{
					gotoxy(x,y);
		        		if (chaine[j] == '0')
		            			chaine[j] = ' '; // changement des 0 en espace
		        		else if (chaine[j] == '1')
		            			chaine[j] = 'X'; // changement des 1 en X

					//x=x+1;
		   		}
				x=x+1;
		    		printf("%s", chaine); // affichage de la ligne modifié

			}
			fclose(fichier); // fermeture du fichier
			fichier = NULL;
	    	}
		x=x-5;
		y = y+7;
		
	}
}

int main()
{

	int RefreshT = atoi(getenv("EXIASAVER2_SLEEP");
	int ctrlc = 0;
	int i;
	int a = 20,b = 15,c = 3,d = 25;
	system("clear");

	while (ctrlc != 1)
	{
		int x = 20;
		int y = 62;
		gotoxy(c,d);
		affichageHorloge();
		gotoxy(a,b);
		if (RefreshT == 1)
		{
			gotoxy(a,b+10);
			printf("Cet écran est actualisé toutes les secondes \n");
		}
		else
		
			printf("Cet écran sera actualisé dans quelques secondes \n");
		
		for (i=0; i<RefreshT; i++)
		{
			sleep(1);
			gotoxy(x,y);
			printf(".\n");
			y++;
		}
		y=y-RefreshT;
		gotoxy(x,y);
		printf("                            ");
		
	}

	return 0;
}



    


