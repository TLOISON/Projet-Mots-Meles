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
