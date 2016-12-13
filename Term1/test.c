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

int module()
    {
        //system("clear");      //Fonction qui nettoie la console    
        FILE* fichier1 = NULL;      //Pointeur initialisé à NULL          
        char chaine[TAILLE_MAX];        
        int chaine2[2];
        int i=0, j=0, k=0, l=0;
        int a,b,c,d;
	fichier1 = fopen("chateau.pbm", "r");
 //Ouverture du fichier "château.pbm" en lecture simple Le pointeur fichier devient le pointeur sur"château.pbm"    
        
        if (fichier1 != NULL) //On peut lire le fichier
            {

                fseek(fichier1, 3, SEEK_SET);                   
                fscanf(fichier1, "%d %d", &chaine2[0], &chaine2[1]);
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
/*		for(k=0;k<c;k++)
{
		printf(" ");
}*/
			printf("%s", chaine);                    //On affiche la ligne
                    }
                
                fclose(fichier1);                       // On ferme le fichier ouvert
            }
        else //On lit le fichier, tant qu'on ne recoit pas d'erreur
            {
                //On affiche un message d'erreur
                printf("Impossible d'ouvrir le fichier, alors arrête de SPAM!\n");
            }
        return 0;
    }

int global; /* In BSS segement, will automatically be assigned '0'*/

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
            /*printf("child process!\n");
            // Increment the local and global variables
            local++;
            global++;
            printf("child PID =  %d, parent pid = %d\n", getpid(), getppid());
            printf("\n child's local = %d, child's global = %d\n",local,global);
            char *cmd[] = {"whoami",(char*)0};
            return execv("/usr/bin/",cmd); // call whoami command*/
	module();
//printf_center();
	if(status!=0)
{
	exit(2);
}
         }
         else /* parent process */
         {
             /*printf("parent process!\n");
             printf("parent PID =  %d, child pid = %d\n", getpid(), child_pid);*/
             wait(&status); // wait for child to exit, and store child's exit status 
             //printf("Child exit code: %d\n", WEXITSTATUS(status));	
             /*//The change in local and global variable in child process should not reflect here in parent process.
             printf("\n Parent'z local = %d, parent's  global = %d\n",local,global);
             printf("Parent says bye!\n");
             exit(0);  // parent exits */


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
