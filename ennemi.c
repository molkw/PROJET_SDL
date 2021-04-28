#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
#include "ennemi.h"
#include <stdio.h>
#include <stdlib.h>

void set_rects_ennemi(SDL_Rect *clip)
{    
    
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].h = 125;
    clip[0].w = 87.5;

    clip[1].x = 87.5;
    clip[1].y = 0;
    clip[1].h = 125;
    clip[1].w = 87.5;

    clip[2].x = 175;
    clip[2].y = 0;
    clip[2].h = 125;
    clip[2].w = 87.5;

    clip[3].x = 262.5;
    clip[3].y = 0;
    clip[3].h = 125;
    clip[3].w = 87.5;
    
    clip[4].x = 350;
    clip[4].y = 0;
    clip[4].h = 125;
    clip[4].w = 87.5;

    clip[5].x = 437.5;
    clip[5].y = 0;
    clip[5].h = 125;
    clip[5].w = 87.5;

    clip[6].x = 525;
    clip[6].y = 0;
    clip[6].h = 125;
    clip[6].w = 87.5;

    clip[7].x = 612.5;
    clip[7].y = 0;
    clip[7].h = 125;
    clip[7].w = 87.5;
    
    clip[8].x = 612.5;
    clip[8].y = 125;
    clip[8].h = 312;
    clip[8].w = 87.5;

    clip[9].x = 525;
    clip[9].y = 125;
    clip[9].h = 125;
    clip[9].w = 87.5;

    clip[10].x = 437.5;
    clip[10].y = 125;
    clip[10].h = 125;
    clip[10].w = 87.5;

    clip[11].x = 350;
    clip[11].y = 125;
    clip[11].h = 125;
    clip[11].w = 87.5;
    
    clip[12].x = 262.5;
    clip[12].y = 125;
    clip[12].h = 125;
    clip[12].w = 87.5;

    clip[13].x = 175;
    clip[13].y = 125;
    clip[13].h = 125;
    clip[13].w = 87.5;

    clip[14].x = 87.5;
    clip[14].y = 125;
    clip[14].h = 125;
    clip[14].w = 87.5;

    clip[15].x = 0;
    clip[15].y = 125;
    clip[15].h = 125;
    clip[15].w = 87.5;

    // clip[0][0].x = 0;
    // clip[0][0].y = 0;
    // clip[0][0].h = 125;
    // clip[0][0].w = 87.5;

    // clip[0][1].x = 87.5;
    // clip[0][1].y = 0;
    // clip[0][1].h = 125;
    // clip[0][1].w = 87.5;

    // clip[0][2].x = 175;
    // clip[0][2].y = 0;
    // clip[0][2].h = 125;
    // clip[0][2].w = 87.5;

    // clip[0][3].x = 262.5;
    // clip[0][3].y = 0;
    // clip[0][3].h = 125;
    // clip[0][3].w = 87.5;
    
    // clip[0][4].x = 350;
    // clip[0][4].y = 0;
    // clip[0][4].h = 125;
    // clip[0][4].w = 87.5;

    // clip[0][5].x = 437.5;
    // clip[0][5].y = 0;
    // clip[0][5].h = 125;
    // clip[0][5].w = 87.5;

    // clip[0][6].x = 525;
    // clip[0][6].y = 0;
    // clip[0][6].h = 125;
    // clip[0][6].w = 87.5;

    // clip[0][7].x = 612.5;
    // clip[0][7].y = 0;
    // clip[0][7].h = 125;
    // clip[0][7].w = 87.5;
    
    // clip[1][0].x = 612.5;
    // clip[1][0].y = 125;
    // clip[1][0].h = 312;
    // clip[1][0].w = 87.5;

    // clip[1][1].x = 525;
    // clip[1][1].y = 125;
    // clip[1][1].h = 125;
    // clip[1][1].w = 87.5;

    // clip[1][2].x = 437.5;
    // clip[1][2].y = 125;
    // clip[1][2].h = 125;
    // clip[1][2].w = 87.5;

    // clip[1][3].x = 350;
    // clip[1][3].y = 125;
    // clip[1][3].h = 125;
    // clip[1][3].w = 87.5;
    
    // clip[1][4].x = 262.5;
    // clip[1][4].y = 125;
    // clip[1][4].h = 125;
    // clip[1][4].w = 87.5;

    // clip[1][5].x = 175;
    // clip[1][5].y = 125;
    // clip[1][5].h = 125;
    // clip[1][5].w = 87.5;

    // clip[1][6].x = 87.5;
    // clip[1][6].y = 125;
    // clip[1][6].h = 125;
    // clip[1][6].w = 87.5;

    // clip[1][7].x = 0;
    // clip[1][7].y = 125;
    // clip[1][7].h = 125;
    // clip[1][7].w = 87.5;
}


void initEnnemi(Enemie *e)
{
    srand(time(NULL));
    SDL_Surface *ennemiSpriteSheet = NULL;
    if (ennemiSpriteSheet == NULL)
    {
        ennemiSpriteSheet = IMG_Load("../photo/spritesheet.png");
    }
    e->enemie = ennemiSpriteSheet;

    e->rects = (SDL_Rect *)malloc(16 * sizeof(SDL_Rect));
    set_rects_ennemi(e->rects);
    
    e->PosEnemie.x = 500;
    e->PosEnemie.y = 20;
    e->curentFrame = 8;
    e->direction = rand() % 2;
}

void afficher_ennemie(Enemie *e,SDL_Surface *ecran)
{
    SDL_BlitSurface(e->enemie, &e->rects[e->curentFrame],ecran,&e->PosEnemie);
}

void deplacer(Enemie *e)
{

    if(e->PosEnemie.x>997)
        e->direction=0;
    else if(e->PosEnemie.x<2)
        e->direction=1;

    if(e->PosEnemie.x<1000 && e->direction == 1)
    {
        e->PosEnemie.x+=5;
        annimerEnnemi(e,1);
    }
    else if(e->PosEnemie.x>0 && e->direction == 0){
        e->PosEnemie.x-=5;
        annimerEnnemi(e,0);
    }
}

void annimerEnnemi(Enemie *e,int direction)
{
    if(direction == 1)
    {
        
    
        e->curentFrame--;
        if (e->curentFrame <0)
        {
            e->curentFrame = 7;
        }
    }
    else if(direction == 0)
    {
        e->curentFrame--;
        if (e->curentFrame < 8)
        {
            e->curentFrame = 15;
        }
    }
}


