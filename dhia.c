

/** 
* @file main.c 
* @brief  Program. 
* @version 0.1 
* @date Apr 21, 2021
* 
* program for background scrollilng * 
*/


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"

int main (int argc, char *argv[])
{

    background b,b2;
    SDL_Event event;
    SDL_Surface *ecran;
    int direction=0;
    int direction2=0;
    int vitesse_perso=0;
    int vitesse_perso2=0;
    int posperso=300;
    Mix_Music *music;


    if (SDL_Init (SDL_INIT_VIDEO) == -1)
    {
        printf ("Can't init SDL: %s\n", SDL_GetError ());
        return EXIT_FAILURE;
    }
    ecran = SDL_SetVideoMode (CAMERA_W, CAMERA_H, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);


    
    initialiser_background(&b);
    
    afficher_background(b, ecran);
    SDL_Flip (ecran);
    

    int continuer = 0;
    SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,
                         SDL_DEFAULT_REPEAT_INTERVAL);
    while (!continuer)
    {

        while (SDL_PollEvent (&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:

                    vitesse_perso+=3;
                    direction=1;
                    break;
                case SDLK_RIGHT:

                    direction=2;
                    vitesse_perso+=3;

                    break;
                case SDLK_UP:

                    direction=3;
                    vitesse_perso+=3;


                    break;
                case SDLK_DOWN:
                    direction=0;
                    vitesse_perso+=3;
                    break;
                case SDLK_p :
                initialiser_background2(&b,&b2);
 		afficher_background(b, ecran);
                afficher_background(b2, ecran);
                SDL_Flip (ecran);
                   break;
                
               
      
                case SDLK_s:

                    vitesse_perso2+=3;
                    direction2=1;
                    break;
                case SDLK_f:

                    direction2=2;
                    vitesse_perso2+=3;

                    break;
                case SDLK_e:

                    direction2=3;
                    vitesse_perso2+=3;


                    break;
                case SDLK_d:
                    direction2=0;
                    vitesse_perso2+=3;


                    break;
                 
                }
               
                break;
                  case SDL_KEYUP:
                    vitesse_perso2=0;
                    vitesse_perso=0;
                    break;
            }


        }
        if (posperso>=CAMERA_W/2)
        {
           scrolling(&b,direction,vitesse_perso);
           scrolling(&b2,direction2,vitesse_perso2); 
        }
        afficher_background(b, ecran);
        afficher_background(b2, ecran);
        SDL_Flip (ecran);
        SDL_Delay(100);
    }
    SDL_FreeSurface(ecran);

}

