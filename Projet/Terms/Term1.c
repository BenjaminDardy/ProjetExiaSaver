#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#define TAILLE_MAX 1000     //Taille maximum du fichier
#define LARGEUR_CONSOLE 80
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

int module()
    {
        FILE* fichier1 = NULL;      //Pointeur initialisé à NULL
        char chaine[TAILLE_MAX];
        int chaine2[2];
        int i=0, j=0, k=0, l=0;
        int a,b,c,d;

        /*int len = strlen(getenv("MONPBM"));
        char* p = NULL;
        p = malloc(len * sizeof(char));*/


	chdir(getenv("EXIASAVER1_PBM"));
	fichier1 = fopen(getenv("MONPBM"), "r"); //Ouvre le fichier pbm choisi par le lanceur

        if (fichier1 != NULL) //On peut lire le fichier
            {

                fseek(fichier1, 3, SEEK_SET);
                fscanf(fichier1, "%d %d", &chaine2[0], &chaine2[1]); //Lecture de la ligne où sont stocké la largeur et longueur de l'image
                a = chaine2[0];
                b = chaine2[1];
		c = (80-2*a)/2;
		d = (24-b)/2;
                a = (a*2)-1;
		fseek(fichier1, 9, SEEK_SET);

	for(l=0;l<d;l++)
	{
		printf("\n");
	}

                    for(i=0; i<b; i++)                   //Boucle qui va parcourir les lignes
                    {
                        fgets(chaine, TAILLE_MAX, fichier1);//récupération de la ligne
                        for(j=0; j<a; j++)               //boucle qui parcours la ligne
                            {
                            if (chaine[j] == '0')
                                    chaine[j] = ' ';        //Affiche les caractères correspondants en ' '
        		else if (chaine[j] == '1')
                                    chaine[j] = 'X';
			      }

		for(k=0;k<c;k++)
{
		printf(" ");
}
			printf("%s", chaine);                    //On affiche la ligne
                    }

                fclose(fichier1);                       // On ferme le fichier ouvert
            }
        else //On lit le fichier, tant qu'on ne recoit pas d'erreur
            {
                
                //On affiche un message d'erreur
                printf("Impossible d'ouvrir le fichier, alors arrête de SPAM!\n");
            }
        //free(p);
        return 0;
    }

int main()
{
    system("clear");
    pid_t child_pid;
    int status;
    int local = 0;
    /* now create new process */
    child_pid = fork();


    if (child_pid >= 0) /* fork succeeded */
    {
        if (child_pid == 0) /* fork() returns 0 for the child process */
        {


	module();
	if(status!=0)
{
	exit(2);
}
         }
         else /* parent process */
         {
             wait(&status); // attend que le fils ai fini et stocke la valeur de sortie du fils
	 }
    }
    else /* failure */
    {
        perror("fork");
        exit(0);
    }

  char c;
  initscr(); // On initialise Ncurses dans ce terminal
  cbreak(); // Pas besoin d'appuyer sur entrée pour envoyer un caractère
  noecho();// On masque les entrées clavier à l'écran
  c = getchar(); // Détecte une interaction de l'utilisateur
  if (c != '\0') // Si le caractère est différent de "vide" (Ici /0 = vide), donc si une touche a été appuyée, alors
  {
    system("clear");
    echo();      // On affiche de nouveau les entrées clavier
    nocbreak(); // On redemande à ce que l'entrée d'un caractère soit validée par "Entrée"
    endwin(); // On quitte la fenêtre Ncurses dans ce terminal
    return 0;
  }

}
