#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED
#include<SDL/SDL_image.h>
#include<SDL/SDL.h>
#include <time.h>
#include"constante.h"

#define timebetween2frames 20;
typedef struct enemie
{

    SDL_Surface *enemie;
    SDL_Rect PosEnemie;
    SDL_Rect *rects;
    int direction;
    int curentFrame, frametimer;
}Enemie;


void initEnnemi (Enemie *E);
void deplacer(Enemie *E);
void afficher_ennemie (Enemie *E,SDL_Surface *ecran);
void set_rects_ennemi(SDL_Rect *clip);
void annimerEnnemi(Enemie *e,int direction);




 #endif // ENEMIE_H_INCLUDED