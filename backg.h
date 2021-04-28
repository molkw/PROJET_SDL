#ifndef BACKG_H_INCLUDED
#define BACKG_H_INCLUDED
#define CAMERA_W 600   ///// la largeur/hauteur du screen dans setvideomod
#define CAMERA_H 400
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
/** 
* @struct Background 
* @brief struct for backround 
*/ 

typedef struct
{
SDL_Surface *img_b;/*!< Surface. */
SDL_Rect position_b; /*!< Rectangle*/ 
SDL_Rect scroll; /*!< Rectangle*/ 
Mix_Music *music;



}background;


void initialiser_background(background *b);
void initialiser_background2(background *b);
void afficher_background(background b, SDL_Surface *ecran);
void scrolling(background *b, int dire,int pasavancement);

#endif // BACKG_H_INCLUDED

