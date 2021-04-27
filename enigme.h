#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

typedef struct 
{
 char question[200];
 char rep1[50];
 char rep2[50];
 char solution[50];

SDL_Surface *q;
SDL_Surface *repp1;
SDL_Surface *repp2;
SDL_Surface *s;

SDL_Rect pos_q;
SDL_Rect pos_repp1;
SDL_Rect pos_repp2;
SDL_Rect pos_s;
 

}enigme;

void afficherEnigme(enigme e, SDL_Surface * screen);
void genererEnigme(enigme * e, char *nomfichier);
void sauvegarder (personne p, background b, char * nomfichier);
int aleatoire(int n);
int compter_nombre_de_ligne_fichier(char* nom_fich);

#endif//ENIGME_H_INCLUDED
