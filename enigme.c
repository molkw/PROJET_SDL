#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"

void afficherEnigme(enigme e, SDL_Surface * screen)
{
	TTF_Font *police1 =NULL;
	TTF_Font *police2 =NULL;
	SDL_Surface *fonds=NULL;

	TTF_Init();
  	police1 = TTF_OpenFont("police1.ttf",45);
	police2 = TTF_OpenFont("police2.ttf",65);

	SDL_Rect position_fonds;
	position_fonds.x=0;
	position_fonds.y=0;
	fonds=IMG_Load("font.png");

	e.q=TTF_RenderText_Blended(police1,e.question,coulerNoir);
	e.pos_q.x=110;
	e.pos_q.y=200;

	e.repp1 =TTF_RenderText_Blended(police2,e.rep1,coulerNoir);	
	 e.pos_repp1.x=200;
	 e.pos_repp1.y=300;
 
	e.repp2 =TTF_RenderText_Blended(police2,e.rep2,coulerNoir);
	 e.pos_repp2.x=200;
	 e.pos_repp2.y=450;
 	SDL_Color coulerNoir= {255,0,0};
	

	SDL_BlitSurface(fonds,NULL,screen,&position_fonds);
	SDL_BlitSurface(e.q,NULL,screen,&e.pos_q);
	SDL_BlitSurface(e.repp1,&position_fonds,screen,&pos_repp1);
	SDL_BlitSurface(e.repp2,&position_fonds,screen,&pos_repp2);

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
fclose(f);
}
void genererEnigme(enigme * e, char *nomfichier)
{
	char chaine[256]="";
	char caractere;	
	int num_ligne=0,ligne,k;
	FILE* f=NULL;
	ligne=compter_nombre_de_ligne_fichier( nomfichier);
	ligne=aleatoire(nb_ligne);
	f=fopen(nom_fich,"r");
	if(f!=NULL)
	{
	while (fgets(chaine,256,f)!=NULL && ligne!=num_ligne)

	   { num_ligne ++;}

	if(ligne==num_ligne)
	{
	k=0;

	do {
	     caractere=fgetc(f);
	     e.question[k]=caractere;
	     k++;
	   }while(caractere!='?');


	k=0;

	do {
	     caractere=fgetc(f);
	     e.rep1[k]=caractere;
	     k++;
	   }while(caractere!='.');

	k=0;
	
	do {
	     caractere=fgetc(f);
	     e.rep2[k]=caractere;
	     k++;
	   }while(caractere!='.');

	k=0;
	
	do {
	     caractere=fgetc(f);
	     e.s[k]=caractere;
	     k++;
	   }while(caractere!='.');

	}

	fclose(f);
	}
	
}
