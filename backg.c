 /** 
* @file backg.c 
* @brief  Program. 
* @version 0.1 
* @date Apr 21, 2021
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"
/** 
* @brief To initialize the background b . 
* @param b the background   
* @return Nothing 
*/ 


void initialiser_background(background *b)
{
SDL_Surface *img_b=NULL;


b->img_b=IMG_Load("bg_image.jpg");
b->position_b.x=0;
b->position_b.y=0;
b->scroll.x=0;
b->scroll.y=CAMERA_H;
b->scroll.w=b->img_b->w;
b->scroll.h=b->img_b->h;

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

b->music=Mix_LoadMUS("music.mp3");

Mix_PlayMusic(b->music, -1);






}


/** 
* @brief To show the background b . 
* @param ecran the screen 
* @param b the background 
* @return Nothing 
*/ 


void afficher_background(background b, SDL_Surface *ecran)
{
SDL_BlitSurface(b.img_b,&(b.scroll),ecran,&(b.position_b));

}
/** 
* @brief To scroll the background 
* @param b the background 
* @param dire the direction of the perso 
* @param pasavancement the speed of the perso 
* @return Nothing 
*/ 

void scrolling(background *b, int dire , int pasavancement)
{
	
	if(dire==1)//gauche
	{
		b->scroll.x-=pasavancement;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=b->scroll.w-CAMERA_W)
			b->scroll.x=(b->scroll.w-CAMERA_W)/2;
			
	}
	else if(dire==2)//droite
	{
		
		b->scroll.x+=pasavancement;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=b->scroll.w-CAMERA_W)
			b->scroll.x=(b->scroll.w-CAMERA_W)/2;

	}
	else if(dire==5)//run gauche
	{
		b->scroll.x-=pasavancement+2;
		
		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=b->scroll.w-CAMERA_W)
			b->scroll.x=(b->scroll.w-CAMERA_W)/2;
			

	}
	else if(dire==6)//run droite
	{
		
		b->scroll.x+=pasavancement+2;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=b->scroll.w-CAMERA_W)
			b->scroll.x=(b->scroll.w-CAMERA_W)/2;
			

	}
         else if(dire==4)//slide
	{
		
		b->scroll.x+=pasavancement;

		if(b->scroll.x<=0)
			b->scroll.x=0;
		if(b->scroll.x>=b->scroll.w-CAMERA_W)
			b->scroll.x=(b->scroll.w-CAMERA_W)/2;
			

	}

	
	else if(dire==3)//saut
	{
		
		b->scroll.y-=pasavancement;

		if(b->scroll.y<=b->position_b.y)
			b->scroll.y=(CAMERA_H-b->position_b.y);
                 /*if(b->scroll.y>=b->scroll.h-b->position_b.y)
			b->scroll.y=(b->scroll.h-b->position_b.y)/2;*/
	}
	else if (dire == 0)
	{
		b->scroll.y+=pasavancement;
                /*if(b->scroll.y<=b->position_b.y)
			b->scroll.y=(CAMERA_H-b->position_b.y);
                 if(b->scroll.y>=b->scroll.h-b->position_b.y)
			b->scroll.y=(b->scroll.h-b->position_b.y)/2;*/
	}
	
}

void initialiser_background2(background *b)
{
SDL_Surface *img_b=NULL;


b->img_b=IMG_Load("bg_image2.jpg");
b->position_b.x=0;
b->position_b.y=0;
b->scroll.x=0;
b->scroll.y=CAMERA_H;
b->scroll.w=b->img_b->w;
b->scroll.h=CAMERA_H/2;








}





