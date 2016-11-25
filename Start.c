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

//Verifie si le mot peut etre placer à une position et retourne les coordonnées ainsi que la direction du mot dans la grille//
void verifier(char grille[N][N],char mot[N],int *Direct,int *xcoord,int *ycoord){
	int cpt = 0;
	int i,j;
	
	for(i=0; i<N ; i++){
		for(j=0; j<N; j++){
			for(cpt=0;cpt<nChaineLg(mot); cpt++){ // Vertical Bas 
				if(mot[cpt]==grille[i+cpt][j]||grille[i+cpt][j]==' '){
					*Direct =4;
					*xcoord =j;
					*ycoord =i;
				}
				else break;
			}
			for(cpt=0;cpt<nChaineLg(mot); cpt++){ // Vertical Haut
				if(mot[cpt]==grille[i-cpt][j]||mot[cpt]==' '){
					*Direct =3;
					*xcoord =j;
					*ycoord =i;
				}
				else break;
			}
			for(cpt=0;cpt<nChaineLg(mot); cpt++){ // Horizontale Droit
				if(mot[cpt]==grille[i][j+cpt]||mot[cpt]==' '){
					*Direct =1;
					*xcoord =j;
					*ycoord =i;
				}
				else break;
			}
			for(cpt=0;cpt<nChaineLg(mot); cpt++){//Horizontale gauche
				if(mot[cpt]==grille[i][j-cpt]||mot[cpt]==' '){
					*Direct=2;
					*xcoord =j;
					*ycoord =i;
				}
				else break;	
			}
			for(cpt=0;cpt<nChaineLg(mot); cpt++){// Diagonale HG
				if(mot[cpt]==grille[i-cpt][j-cpt]||mot[cpt]==' '){
					*Direct=5;
					*xcoord =j;
					*ycoord =i;
				}
				else break;	
			}
			for(cpt=0;cpt<nChaineLg(mot); cpt++){// Diangonale BD
				if(mot[cpt]==grille[i+cpt][j+cpt]||mot[cpt]==' '){
					*Direct=6;
					*xcoord =j;
					*ycoord =i;
				}	
				else break;
			}
			for(cpt=0;cpt<nChaineLg(mot); cpt++){// Diagonale HD
				if(mot[cpt]==grille[i-cpt][j+cpt]||mot[cpt]==' '){
					*Direct= 7;
					*xcoord =j;
					*ycoord =i;
				}
				else break;	
			}
			for(cpt=0;cpt<nChaineLg(mot); cpt++){// Diagonale BG
				if(mot[cpt]==grille[i+cpt][j-cpt]||mot[cpt]==' '){
					*Direct =8;
					*xcoord =j;
					*ycoord =i;
				}
				else break;	 
			}
		}
	}
}

//Place les mots dans la grille celon les indications de la fonction <verifier>//
void placer(char mot[N], char grille[N][N]){
	;
	int x,y,direct;
	verifier(grille,mot,&direct,&x,&y);
	switch(direct)
		{	case 1: horizontaleD(grille,mot, x,y); break;
			case 2: horizontaleG(grille,mot, x, y); break;
			case 3: verticaleH(grille, mot,  x,  y); break;
			case 4: verticaleB(grille, mot, x, y); break;
			case 5: diagonaleHG(grille, mot, x, y); break;
			case 6: diagonaleBD(grille, mot, x, y); break;
			case 7: diagonaleHD(grille, mot, x, y); break;
			case 8:	diagonaleBG(grille, mot, x, y);break;
			default: printf("Erreur: votre choix doit �tre compris entre 1 et 8\n");
		}
}

//Permet de jouer au jeu//
void jouer(int theme){
	char grille[N][N];	//Grille de mots-meles//
	char a[4];		//Mot pour la fin de partie//
	char adresse[50];	//Adresse du fichier contenant la liste de mot//
	char mot[N];		//Mot courant de la liste//
	int i = 0;		//Indice//

	init_grille(grille);	//Initialise la grille avec des espaces//
	
	
	while(strcmp(a, "fini") != 0){
		printf("\nVoici les mots à trouver: \n");
		printf("-------------------------\n");
		switch(theme){	//Permet de selectionner le fichier à ouvrir celon le choix du joueur//
			case 1: strcpy(adresse, "ELECTIONS.txt"); break;
			case 2: strcpy(adresse, "EAU.txt"); break;
			case 3: strcpy(adresse, "CAPITALES.txt"); break;
			case 4: strcpy(adresse, "POTTER.txt"); break;
		}

		FILE * fichier;
		
		
		fichier=fopen(adresse,"r");
			do{ //Parcours le fichier//
				for(i=0; i<10; i++){	//Permet de mettre dix mot par ligne pour la lisibilite//
					if(feof(fichier) == 0){
						fscanf(fichier, "%s", mot);	//Selectionne un mot dans la liste//
						printf("%s  ", mot);		//Affiche le mot dans la liste de mot a trouver pour le joueur//
						placer(mot, grille);		//Place le mot dans la grille//
					}
				}
				printf("\n");	
			}while(!feof(fichier));

		fclose (fichier);

		//completer_grille(grille);//

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
