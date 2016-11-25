#include "Outil.h"
#define N 15

//Initialise la grille avec des espaces//
void init_grille(char grille[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N ; j++){
			char lettre = ' ';
			grille[i][j] = lettre;	
		}
	}
}

//Complet les trous de la grilles par des lettres aléatoires//
void completer_grille(char grille[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N ; j++){
			if(grille[i][j] == ' '){
				int lettre = '@'+uHasard(26);
				grille[i][j] = lettre;	
			}
		}
	}
}

//Affiche la grille de Mots-Mélés//
void afficher(char grille[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%c ", grille[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Permet d'insérer un mot à l'horizontale vers la droite; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void horizontaleD(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0; i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		y++;
	}
}

//Permet d'insérer un mot à l'horizontale vers la gauche; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void horizontaleG(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0; i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		y--;
	}
}

//Permet d'insérer un mot à la verticale vers le bas; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void verticaleB(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x++;
	}
}

//Permet d'insérer un mot à la verticale vers le haut; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void verticaleH(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x--;
	}
}
//Permet d'insérer un mot en diagonale vers le bas à droite; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void diagonaleBD(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x++;
		y++;
	}
}

//Permet d'insérer un mot en diagonale vers le bas à gauche; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void diagonaleBG(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x++;
		y--;
	}
}

//Permet d'insérer un mot en diagonale vers le bas à gauche; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void diagonaleHD(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x--;
		y++;
	}
}

//Permet d'insérer un mot en diagonale vers le bas à gauche; nécessite le nom de la grille, le mot à insérer, et les coordonnées de la premiere lettre//
void diagonaleHG(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x--;
		y--;
	}
}

//Permet de jouer au jeu//
void jouer(int theme){
	char grille[N][N];
	char mot1[N];
	char mot2[N];
	char mot3[N];
	char mot4[N];
	char mot5[N];
	char mot6[N];
	char a[4];
	char adresse[50];
	int i = 0;

	strcpy(mot1,"MERCI");
	strcpy(mot2,"CHIEN");
	strcpy(mot3,"HIMALAYA");
	strcpy(mot4,"CARAPACE");
	strcpy(mot5,"CHOUX");
	strcpy(mot6,"PURGE");
	
	init_grille(grille);
	
	diagonaleBD(grille, mot1, 0, 0);
	horizontaleD(grille, mot2, 3, 3);
	verticaleB(grille, mot3, 3, 4);
	horizontaleD(grille, mot4, 6, 3);
	verticaleB(grille, mot5, 6, 9);
	verticaleB(grille, mot6, 2, 10);
	
	completer_grille(grille);
	while(strcmp(a, "fini") != 0){
		printf("\nVoici les mots à trouver: \n");
		printf("-------------------------\n");
		switch(theme){
			case 1: strcpy(adresse, "ELECTIONS.txt"); break;
			case 2: strcpy(adresse, "EAU.txt"); break;
			case 3: strcpy(adresse, "CAPITALES.txt"); break;
			case 4: strcpy(adresse, "POTTER.txt"); break;
		}

		FILE * fichier;
     
		// récupération de l'adresse du fichier texte à traiter
		
		char mot[N];
	 	// ouverture du fichier en mode lecture
		fichier=fopen(adresse,"r");
			 
			// traitement
			do{ // lecture du mot 
				for(i=0; i<10; i++){
					if(feof(fichier) == 0){
						fscanf(fichier, "%s", mot);
						printf("%s  ", mot);
					}
				}
				printf("\n");	
			}while(!feof(fichier));
		fclose (fichier);
		printf("\n");	
		afficher(grille);
		printf("Entrez <fini> une fois la partie terminée => ");
		scanf("%s", a);
	}
}

//Permet à l'utilisateur de selectionner le theme de la grille//
void select_theme(){
	int choix = 0;
	printf("\n Selectinnez un theme parmi ceux proposés: \n");
	
	while(choix<=0 || choix>4){
		printf("1 - Elections \n");
		printf("2 - L'eau dans tout ses états \n");
		printf("3 - Capitales du monde \n");
		printf("4 - Harry Potter \n");
		printf("Votre choix : ");
		scanf("%i", &choix);
		
		switch(choix){
			case 1: choix = 1; break;
			case 2: choix = 2; break;
			case 3: choix =  3; break;
			case 4: choix =  4; break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
	jouer(choix);
}

//Main du programme//		
int main(){
	int choix;

/* Affichage du menu et saisie du choix */
	do
	{	printf("\nMenu :\n");
		printf(" 1 - Selection du thème\n");
		printf(" 2 - Jouer\n");
		printf(" 3 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: select_theme();	break;
			case 2: printf("pour jouer, merci de selectionner un theme. \n"); break;
			case 3: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}
	while(choix!=3);
	printf("Au revoir, et merci d'avoir joué !\n");
	printf("\n");
	return EXIT_SUCCESS;
}
