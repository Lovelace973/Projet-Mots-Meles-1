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
//Fonction qui prend la valeur retourner la fonction verifier afin de definir de quelle façon le mot peut être placé dans la grille//
void placer(char mot[N], char grille[N][N]){
	int x,y,direct;
	verifier(grille,mot,&direct,&x,&y);
	switch(direct)
		{	case 1: horizontaleD(grille,mot, x,y); break; //placement en horizontal droit
			case 2: horizontaleG(grille,mot, x, y); break; //placement en horizontal gauche
			case 3: verticaleH(grille, mot,  x,  y); break; //placement en vertical haut
			case 4: verticaleB(grille, mot, x, y); break; //placement en vertical bas
			case 5: diagonaleHG(grille, mot, x, y); break; //placement en diagonale haut gauche
			case 6: diagonaleBD(grille, mot, x, y); break; //placement en diagonal bas droit
			case 7: diagonaleHD(grille, mot, x, y); break; //placement en diagonal haut droit
			case 8:	diagonaleBG(grille, mot, x, y);break; //placement en diagonal bas gauche
			default: printf("Erreur: votre choix doit �tre compris entre 1 et 8\n");
		}
}
