#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef struct perso
{
int num;

SDL_Surface *spritesheet;
SDL_Rect position;//position du perso dans le background
int direction;
SDL_Rect pos_sprite; 
double vitesse,   acceleration;
int vitesseV;
//vie
SDL_Surface *image_vie[5]; 
SDL_Rect position_vie ;
int val;
SDL_Rect position_texte;
//score
char number[20]; 
SDL_Rect position_textee;
SDL_Rect position_number;  
int valeur_score ;
}perso;



void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void deplacerPerso (perso *p,int dt);
void animerPerso (perso* p);
void saut (perso* p) ;





 #endif
