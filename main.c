/**
 * @file main.c
 * @author salim

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"


int main()
{	
	int continuer=1,a,b;
	SDL_Surface *screen;
        SDL_Surface *background;
	SDL_Surface *success;
	SDL_Surface *fail;
	SDL_Rect positionbackground;
	SDL_Rect positionResult;
	SDL_Event event;
	enigme e;
	TTF_Font *police2 =NULL;

	SDL_Color couleur= {255,255,0};
	
	TTF_Init();
	police2 = TTF_OpenFont("police2.ttf",65);
	 
      if(SDL_Init(SDL_INIT_VIDEO)!=0)
     {
	printf("erreur %s \n",SDL_GetError());
     return 1;
    }
	background=IMG_Load("back.jpg");
         if (background==NULL)
        {
           printf("erreur :%s \n",SDL_GetError());
          return 1;
        }
	success=IMG_Load("success.png");
         if (background==NULL)
        {
           printf("erreur :%s \n",SDL_GetError());
          return 1;
        }
	fail=IMG_Load("fail.png");
         if (background==NULL)
        {
           printf("erreur :%s \n",SDL_GetError());
          return 1;
        }
	background->w=2400;
	background->h=700;
	screen=SDL_SetVideoMode(background->w,background->h,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
	printf("erreur: %s ",SDL_GetError());
	return 1;
	}
	/*(e.repp2)->h=200;
	printf("done");
	e.repp2->w=120;
	e.repp1->h=200;
	e.repp1->w=120;*/
	
	positionbackground.x=0;
	positionbackground.y=0;
	positionResult.x=800;
	positionResult.y=200;
	SDL_BlitSurface(background,NULL,screen,&positionbackground);
	e.q=NULL;
	e.repp1=NULL;
	e.repp2=NULL;
	char vide[50]="";
	strcpy(e.question,vide);
	strcpy(e.rep1,vide);
	strcpy(e.rep2,vide);
	strcpy(e.solution,vide);
	genererEnigme(&e, "enigmes.txt");


	afficherEnigme(&e,screen);
	//printf("ll:%d",e.repp2->h);
	SDL_Flip(screen); 
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{ 
			case SDL_QUIT:
			continuer=0;
			break;
			case SDL_MOUSEBUTTONDOWN:
				a=event.button.x;
				b=event.button.y ;
				if ((a > e.pos_repp1.x && a < e.pos_repp1.x + e.pos_repp1.w) && (b > e.pos_repp1.y && b < e.pos_repp1.y+e.pos_repp1.h))
  				 {
					printf("\nsss");
					e.repp1 =TTF_RenderText_Blended(police2,e.rep1,couleur);
					
					SDL_BlitSurface(e.repp1,NULL,screen,&e.pos_repp1);
					SDL_Flip(screen);
   					 if(strcmp(e.rep1,e.solution)==0)
     						{
							
     							 SDL_BlitSurface(success,NULL,screen,&positionResult);
							SDL_Flip(screen);
     							 }
    						else
    							 {
								

							SDL_BlitSurface(fail,NULL,screen,&positionResult);
							SDL_Flip(screen);
    							}
				}
				else if((a > e.pos_repp2.x && a< e.pos_repp2.x + e.pos_repp2.w) && (b >e.pos_repp1.y && b < e.pos_repp2.y+e.pos_repp2.h))
				{
							printf("\nsss");
							e.repp2 =TTF_RenderText_Blended(police2,e.rep2,couleur);
							SDL_BlitSurface(e.repp2,NULL,screen,&e.pos_repp2);
							SDL_Flip(screen);
					if(strcmp(e.rep2,e.solution)==0)
					{

     							 SDL_BlitSurface(success,NULL,screen,&positionResult);
							SDL_Flip(screen);
     							 }
    						else
    							 {
								

							SDL_BlitSurface(fail,NULL,screen,&positionResult);
							SDL_Flip(screen);
    							}
						}
			SDL_Flip(screen);
					break;
			    case SDL_KEYDOWN:
        			switch (event.key.keysym.sym)
        			{
        			case SDLK_a:
            			e.repp1 =TTF_RenderText_Blended(police2,e.rep1,couleur);	
				SDL_BlitSurface(e.repp1,NULL,screen,&e.pos_repp1);
				SDL_Flip(screen);
   					 if(strcmp(e.rep1,e.solution)==0)
     						{
							
     							 SDL_BlitSurface(success,NULL,screen,&positionResult);
							SDL_Flip(screen);
     							 }
    						else
    							 {
								

							SDL_BlitSurface(fail,NULL,screen,&positionResult);
							SDL_Flip(screen);
    							}
            			break;
        			case SDLK_b:
            			e.repp2 =TTF_RenderText_Blended(police2,e.rep2,couleur);
				SDL_BlitSurface(e.repp2,NULL,screen,&e.pos_repp2);
				SDL_Flip(screen);
					if(strcmp(e.rep2,e.solution)==0)
					{

     							 SDL_BlitSurface(success,NULL,screen,&positionResult);
							SDL_Flip(screen);
     							 }
    						else
    							 {
								

							SDL_BlitSurface(fail,NULL,screen,&positionResult);
							SDL_Flip(screen);
    							}
            			break;
  
       				 }
        break;
			
					
		}
	}
	SDL_FreeSurface(screen);
	SDL_FreeSurface(background);
	SDL_Quit();

	return 0;
	


}

	/*e->repp1 =TTF_RenderText_Blended(police2,e->rep1,coulerNoir);
	e->repp2 =TTF_RenderText_Blended(police2,e->rep2,coulerNoir);*/
