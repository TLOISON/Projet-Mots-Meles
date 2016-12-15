#include "Outil.h"
#define N 20

void clrscr()
{
    system("clear");
}
//Initialise la grille avec des espaces//
void init_grille(char grille[N][N], int max_i,int max_j ,char c ){
	int i, j;
	for(i=0; i<max_i; i++){
		for(j=0; j<max_j ; j++){
			char lettre = c;
			grille[i][j] = lettre;
		}
	}
}

//Complet les trous de la grilles par des lettres alÃ©atoires//
void completer_grille(char grille[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N ; j++){
			if(grille[i][j] == '.'){
				int lettre = '@'+uHasard(26);
				grille[i][j] = lettre;
			}
		}
	}
}

//Affiche la grille de Mots-MÃ©lÃ©s//
void afficher(char grille[N][N]){
	int i, j;
	printf("\n");
	for(i=-1; i<N; i++){
            if (i==-1){
                printf("X  ");
            }
            else if(i<10){
                printf("%i  ",i);
            }
            else{
                printf("%i ",i);
            }
		for(j=0; j<N; j++){
		    if(i==-1){
                    if(j<10){
                        printf("%i  ",j);
                    }
                    else{

                        printf("%i ",j);
                    }

		    }
		    else{
                printf("%c  ", grille[i][j]);
		    }

		}

        printf("\n");
	}
	printf("\n \n");


}

//Permet d'insÃ©rer un mot Ã  l'horizontale vers la droite; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void horizontaleD(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0; i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		y++;
	}
}

//Permet d'insÃ©rer un mot Ã  l'horizontale vers la gauche; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void horizontaleG(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0; i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		y--;
	}
}

//Permet d'insÃ©rer un mot Ã  la verticale vers le bas; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void verticaleB(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x++;
	}
}

//Permet d'insÃ©rer un mot Ã  la verticale vers le haut; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void verticaleH(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x--;
	}
}
//Permet d'insÃ©rer un mot en diagonale vers le bas Ã  droite; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void diagonaleBD(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x++;
		y++;
	}
}

//Permet d'insÃ©rer un mot en diagonale vers le bas Ã  gauche; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void diagonaleBG(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x++;
		y--;
	}
}

//Permet d'insÃ©rer un mot en diagonale vers le bas Ã  gauche; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void diagonaleHD(char grille[N][N], char mot[N], int x, int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x--;
		y++;
	}
}

//Permet d'insÃ©rer un mot en diagonale vers le haut Ã  gauche; nÃ©cessite le nom de la grille, le mot Ã  insÃ©rer, et les coordonnÃ©es de la premiere lettre//
void diagonaleHG(char grille[N][N],char mot[N],int x,int y){
	int i;
	for(i=0;i<nChaineLg(mot); i++){
		grille[x][y] = mot[i];
		x--;
		y--;
	}
}

//Place les mots dans la grille celon les indications de la fonction <verifier>//
void placer(char mot[N], char grille[N][N], int x, int y, int direct){

	switch(direct)
		{	case 1: horizontaleD(grille,mot, x,y); break;
			case 2: verticaleB(grille, mot, x, y); break;
			case 3: diagonaleBD(grille, mot, x, y); break;
			case 4: horizontaleG(grille,mot, x, y); break;
			case 5: diagonaleHG(grille, mot, x, y); break;
			case 6: verticaleH(grille, mot,  x,  y); break;
			case 7: diagonaleHD(grille, mot, x, y); break;
			case 8:	diagonaleBG(grille, mot, x, y);break;
			default: ;//Ne rien faire//
		}
}

//Verifie si le mot peut etre placer dans la gril#include <conio.h>le//
int verifier(char grille[N][N],char mot[N],int *x_start,int *y_start,int *x_end,int *y_end){
	int leng = nChaineLg(mot);
	int i, j, k, l	;
	int direct, possible;

	direct=rand()%3 + 1;

	if(direct == 1){	//Cas por horizontale vers la droite//
		for(i=0; i<N+1 ; i++){
			for(j=0; j<N+1; j++){
				possible = 1;
				if(leng + j <= N){
					for(k=0; k<=leng && possible==1; k++){
						if(grille[i][j+k] != '.' && grille[i][j+k] != mot[k]){
							possible = 0;
						}
					}
					if(possible == 1){
                            				*x_start=j;
							*y_start=i;
							*x_end=j+(leng-1);
							*y_end=i;
							placer(mot, grille, i, j, direct);
							return 1;
					}
				}
			}
		}
	}

		/*else if(direct == 4){	//Cas pour horizontale vers la gauche//
		for(i=0; i<N+1 ; i++){
			for(j=0; j<N+1; j++){
				possible = 1;
				if(0<=(j+1)-leng<=N){
					for(k=0; k<=leng && possible ==1; k++){
						if(grille[i][j-k] != '.' && grille[i][j-k] != mot[k]){
							possible = 0;
						}
					}
					if(possible == 1){
						placer(mot, grille, i, j, direct);
						return 1;
					}
				}
			}
		}
	}*/

	else if(direct == 2){	//Cas pour verticale vers le bas//
		for(i=0; i<N+1 ; i++){
			for(j=0; j<N+1; j++){
				possible = 1;
				if(leng + j <= N){
					for(k=0; k<=leng && possible==1; k++){
						if(grille[i+k][j] != '.' && grille[i+k][j] != mot[k]){
							possible = 0;
						}
					}
					if(possible == 1){
                        			*x_start=j;
                        			*y_start=i;
                        			*x_end=j;
                        			*y_end=i+(leng-1);
						placer(mot, grille, i, j, direct);
						return 1;
					}
				}
			}
		}
	}
		/*else if(direct == 6){	//Cas pour verticale vers le haut//
		for(i=0; i<N+1 ; i++){
			for(j=0; j<N+1; j++){
				possible = 1;
				if(N > i - leng >= 0){
					for(k=0; k<=leng && possible ==1; k++){
						if(grille[i-k][j] != '.' && grille[i+k][j+k] != mot[k]){
							possible = 0;
						}
					}
					if(possible == 1){
						placer(mot, grille, i, j, direct);
						return 1;
					}
				}
			}
		}
	}*/
	else if(direct == 3){	//Cas pour diagonale vers le bas a droite//
		for(i=0; i<N+1 ; i++){
			for(j=0; j<N+1; j++){
				possible = 1;
				if(leng + j <= N){
					for(k=0; k<=leng && possible ==1; k++){
						if(grille[i+k][j+k] != '.' && grille[i+k][j+k] != mot[k]){
							possible = 0;
						}
					}
					if(possible == 1){
						*x_start=j;
                        			*y_start=i;
                        			*x_end=j+(leng-1);
                        			*y_end=i+(leng-1);
						placer(mot, grille, i, j, direct);
						return 1;
					}
				}
			}
		}
	}
}

int selection(char grille[N][N],int coord[500],int *i){
	int x_start,y_start,x_end,y_end;
	*i=0;

    printf("Coordonnés de début de mot :\n");
    scanf("%i %i",&x_start,&y_start);
    printf("Coordonnées de fin de mot :\n");
    scanf("%i %i",&x_end,&y_end);
	while (*i<500){

		if(coord[*i+4] == -1){
			if(coord[*i]==x_start && coord[*i+1]==y_start && coord[*i+2]==x_end && coord[*i+3]==y_end){

					return 1;
			}else{
				*i=*i+5;
			}

		}
		 else{
            		*i++;
        	}
	}
}
void supprimer_mot(char liste[50][10],int rang){
int i=0;
int j=0;
for(j=0;j<10;j++){
    liste[rang][j]='\0';
}

}
//Permet de jouer au jeu//
void jouer(int theme){
	char grille[N][N];		//Grille de mots-meles//
	char a[4];				//Mot pour la fin de partie//
	char adresse[50];		//Adresse du fichier contenant la liste de mot//
	char mot[N];			//Mot courant de la liste//
	char liste[50][10];
	int leng = nChaineLg(mot);
	int i = 0;				//Indice//
	int tmp;
	int x_start,y_start,x_end,y_end;
	int coord[500];
	int cpt=0;
	int select;
	int cptr_j,cptr_i=0;
	int indice ,num_mot;
	int verif=0;
	int trouve=0;
	init_grille(grille,N,N,'.');	//Initialise la grille avec des points//
	init_grille(liste,50,10,'\0');


	while(strcmp(a, "fini") != 0){
		printf("\nVoici les mots a trouver: \n");
		printf("-------------------------\n");
		switch(theme){	//Permet de selectionner le fichier a ouvrir celon le choix du joueur//
			case 1: strcpy(adresse, "ELECTIONS.txt"); break;
			case 2: strcpy(adresse, "EAU.txt"); break;
			case 3: strcpy(adresse, "CAPITALES.txt"); break;
			case 4: strcpy(adresse, "POTTER.txt"); break;
		}

		FILE * fichier;


		fichier=fopen(adresse,"r");
			do{ //Parcours le fichier//
				for(i=0; i<10;i++){	//Permet de mettre dix mot par ligne pour la lisibilite//
					if(feof(fichier) == 0){
						fscanf(fichier, "%s", mot);			//Selectionne un mot dans la liste (fichier.txt)//
						tmp = verifier(grille, mot,&x_start,&y_start,&x_end,&y_end);		//Place le mot dans la grille//
						if(tmp == 1){
                           				coord[cpt]=x_start;
							cpt++;
							coord[cpt]=y_start;
							cpt++;
							coord[cpt]=x_end;
							cpt++;
							coord[cpt]=y_end;
							cpt++;
							coord[cpt]=-1;
							cpt++;

							    for(cptr_j=0;cptr_j<10;cptr_j++){

								liste[cptr_i][cptr_j]=mot[cptr_j];
								if (liste[cptr_i][cptr_j]== '\0'){
								    break;
								}
							    }
							    cptr_i++;
							printf("%s  ", mot);//Affiche le mot dans la liste de mot a trouver//



						}
						else{
							i--;
						}
					}
				}
				printf("\n");
			}while(!feof(fichier));

		fclose (fichier);

		//completer_grille(grille);	//Comble les trous de la grille par des lettres au hasard//

		printf("\n");
		afficher(grille);
		printf("\n");
		/*for(i=0;i<50;i++){
		    printf("\n");
		    for(cptr_j=0;cptr_j<10 && liste[i][cptr_j]!='\0' ;cptr_j++){
		        printf("%c",liste[i][cptr_j]);
		            }
		}*/
		while(trouve!= 1){
		    clrscr();
		     for(i=0;i<50;i++){
		            printf("\n");
		            for(cptr_j=0;cptr_j<10 && liste[i][cptr_j]!='\0';cptr_j++){
				if (liste[i][cptr_j] == '\n'){
					printf(" ");
				}
		                else {
					printf("%c",liste[i][cptr_j]);
				}
		            }
		    }
		    afficher(grille);
		    select=selection(grille,coord,&indice);
		    num_mot=indice/5;
		    if (select == 1){
		        supprimer_mot(liste,num_mot);
		      
		    }
		    verif=0;
		    for(i=0;i<50;i++){
		            for(cptr_j=0;cptr_j<10;cptr_j++){
		                if(liste[i][cptr_j]=='\0'){
		                    verif++;
		                }
		                if(verif==500){
		                    printf("vous avez gagné");
		                    trouve=1;
		                }
		            }
		    }
		}


            //printf("%i",num_mot);
			//printf("gg vous avez trouvé un mot");



		printf("Entrez <fini> une fois la partie terminee => ");
		scanf("%s", a);
	}
}

//Permet a  l'utilisateur de selectionner le theme de la grille//
void select_theme(){
	int choix = 0;
	printf("\nSelectionnez un theme parmi ceux proposes: \n");
	printf("-----------------------------------------\n");

	while(choix<=0 || choix>4){
		printf("1 - Elections \n");
		printf("2 - L eau dans tout ses etats \n");
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
	srand(time(NULL));
	int choix;

// Affichage du menu et saisie du choix //
	do
	{	printf("\nMenu :\n");
		printf(" 1 - Selection du theme\n");
		printf(" 2 - Jouer\n");
		printf(" 3 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

// Traitement du choix de l'utilisateur //
		switch(choix)
		{	case 1: select_theme();	break;
			case 2: printf("pour jouer, merci de selectionner un theme. \n"); break;
			case 3: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}
	while(choix!=3);
	printf("Au revoir, et merci d'avoir joue !\n");
	printf("\n");
	return EXIT_SUCCESS;
}