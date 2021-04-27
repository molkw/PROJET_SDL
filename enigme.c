#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

void afficherEnigme(enigme *e, SDL_Surface * screen)
{
	int alea;	
	TTF_Font *police1 =NULL;
	TTF_Font *police2 =NULL;
	SDL_Surface *fonds=NULL;
	SDL_Color coulerNoir= {255,0,0};

	TTF_Init();
  	police1 = TTF_OpenFont("police1.ttf",45);
	police2 = TTF_OpenFont("police2.ttf",65);

	

	e->q=TTF_RenderText_Blended(police1,e->question,coulerNoir);
	e->pos_q.x=110;
	e->pos_q.y=200;
	
	//alea=aleatoire(2);

	//switch(alea){
	//case 1:

	 	
	 e->pos_repp1.x=200;
	 e->pos_repp1.y=350;	 
	 e->pos_repp2.x=200;
	 e->pos_repp2.y=450;
	 //break;
	//case 2:
	 e->pos_repp1.x=200;
	 e->pos_repp1.y=450;	 
	 e->pos_repp2.x=200;
	 e->pos_repp2.y=350;
	// break;

	//}
 	
	
	e->repp1 =TTF_RenderText_Blended(police2,e->rep1,coulerNoir);
	e->repp2 =TTF_RenderText_Blended(police2,e->rep2,coulerNoir);
	//printf("\n%s\n",e->rep1);
	//printf("\n%s\n",e->rep2);

	SDL_BlitSurface(e->q,NULL,screen,&e->pos_q);
	SDL_BlitSurface(e->repp1,NULL,screen,&e->pos_repp1);
	SDL_BlitSurface(e->repp2,NULL,screen,&e->pos_repp2);

	SDL_Flip(screen);

	TTF_CloseFont(police1);
	TTF_CloseFont(police2);
	TTF_Quit();
}


int aleatoire(int n)
{
int alea;
do{
    srand(time(NULL));	
     alea=1+rand()%n;
}while(alea==0||alea>n);
    return alea;
}

int compter_nombre_de_ligne_fichier(char* nom_fich)
{
int i=0;
  FILE* f=NULL;
char chaine[265]="";
f=fopen(nom_fich,"r");
if(f!=NULL)
{
   while(fgets(chaine,256,f)!=NULL)
    {
        i++;  
    }
printf("%d",i);
fclose(f);
}
return i;
}
void genererEnigme(enigme * e, char *nomfichier)
{
	char chaine[256]="";
	char caractere;	
	int num_ligne=1,ligne,k,nb_ligne,c;
	FILE* f=NULL;	
	nb_ligne=compter_nombre_de_ligne_fichier( nomfichier); //nombre de lignes de fichiers
	ligne=aleatoire(nb_ligne);  //le ligne a afficher
	
	
	f=fopen(nomfichier,"r");
	if(f!=NULL)
	{
	while (fgets(chaine,256,f)!=NULL && ligne!=num_ligne)

	   { num_ligne ++;
	
	}
	printf("%s",chaine);
	if(ligne==num_ligne)
	{
	k=0;
	c=0;

	do {

	     caractere=chaine[k];
	     e->question[c]=caractere;
	     k++;
	     c++;		
	   }while(caractere!='?');
	
	
	c=0;
	
	do {
	     caractere=chaine[k];
	     e->rep1[c]=caractere;
	     k++;
	     c++;
	   }while(caractere!='.');

	c=0;
	do {
	     caractere=chaine[k];
	     e->rep2[c]=caractere;
	     k++;
	     c++;
	   }while(caractere!='.');

	c=0;
	do {
	     caractere=chaine[k];
	     e->solution[c]=caractere;
	     k++;
	     c++;
	   }while(caractere!='.');

		printf("\n%s\n",e->solution);
		printf("\n%s\n",e->rep1);
		printf("\n%s\n",e->rep2);

	}

	fclose(f);
	}
	
	
}

void sauvegarder (personne p, background b, char * nomfichier)
{
	FILE *fich=NULL;
	fich=fopen(nomfichier,"w");
	if(fich!=NULL)
	{
	
	}
}
