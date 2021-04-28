#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<math.h>


//void deplacerEN(SDL_Rect *ennemi, int directionE);
int gravity(SDL_Rect rectangle, SDL_Rect OBJET);
int collisionBB(SDL_Rect rectangle,SDL_Rect OBJET);
void delay(unsigned int frameLimit);
void init_map(SDL_Rect *rectFond,SDL_Rect *rectangle0,SDL_Rect *rectangle1,SDL_Rect *rectangle2,SDL_Rect *rectangle3,SDL_Rect *rectangle4,SDL_Rect *rectangle5, SDL_Rect *rectangle6);
void draw(SDL_Rect rectFond,Uint32 colorR,SDL_Rect rectangle0,SDL_Rect rectangle1,SDL_Rect rectangle2,SDL_Rect ectangle3,SDL_Rect rectangle4,SDL_Rect rectangle5,SDL_Rect rectangle6,Uint32 color, SDL_Surface *ecran);
void deplacer(SDL_Rect rectangle0,SDL_Rect rectangle1,SDL_Rect rectangle2,SDL_Rect rectangle3,SDL_Rect rectangle4,SDL_Rect rectangle5,SDL_Rect rectangle6, SDL_Rect *OBJET,int direction);
void JUMP(SDL_Rect *OBJET,int direction);