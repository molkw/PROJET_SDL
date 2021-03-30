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
{	SDL_Surface *screen;
        SDL_Surface *background;
	SDL_Rect positionbackground;
	enigme e;
	TTF_Font *police =NULL;
	screen=SDL_SetVideoMode(738,766,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_FillRect (screen,NULL,SDL_MapRGB(screen->format,128,0,0));
	
	screen=SDL_SetVideoMode(738,766,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_FillRect (screen,NULL,SDL_MapRGB(screen->format,128,0,0));
	if(screen==NULL)
	{
	printf("erreur: %s ",SDL_GetError());
	return 1;
	}
	 
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

	positionbackground.x=0;
	positionbackground.y=0;

	SDL_BlitSurface(background,NULL,screen,&positionbackground);
	genererEnigme(&e, "enigmes.txt");
	afficherEnigme(e,&screen);
	


}
