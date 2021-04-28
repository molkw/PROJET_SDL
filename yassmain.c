#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>

#include"main.h"


#define VITESSE 4
int main(int argc, char **argv)
{
    int direction =0;
    unsigned int frameLimit=SDL_GetTicks() + 16;
    int FPS=60;
    int yI;
    int input=2;
    SDL_Surface *ecran=NULL;
   unsigned int timeer,timer;
  float timeDIFF;
   unsigned int time=SDL_GetTicks();
    SDL_Rect RectFond;
    SDL_Rect ennemi;
    SDL_Rect portaille;
    SDL_Event event;  
    SDL_Rect rectangle0,rectangle1,rectangle2,rectangle3,rectangle4,rectangle5,rectangle6,OBJET,rectFond;
    int continuer = 1;
    int directionE;
    int directionQM=0;
    SDL_Init(SDL_INIT_VIDEO);
    ecran=SDL_SetVideoMode(1058,577,32, SDL_HWSURFACE|SDL_GL_DOUBLEBUFFER);
    SDL_WM_SetIcon(IMG_Load("../photo/iconG.png"),NULL);
    SDL_WM_SetCaption("titre",NULL);
    Uint32 color = SDL_MapRGB(ecran->format, 225,0,0);
    Uint32 colorR = SDL_MapRGB(ecran->format, 0,0,50);
    Uint32 colorO = SDL_MapRGB(ecran->format, 225,225,225);
    Uint32 colorE = SDL_MapRGB(ecran->format, 100,150,50);
    Uint32 colorPort = SDL_MapRGB(ecran->format, 0,230,100);
    int i;

    
    init_map(&rectFond,&rectangle0,&rectangle1,&rectangle2,&rectangle3,&rectangle4,&rectangle5,&rectangle6);

    OBJET.x=50;
    OBJET.y=50;
    OBJET.w=32;
    OBJET.h=32;
    portaille.x=590;
    portaille.y=450;
    portaille.w=portaille.h=40;
    ennemi.x=100;
    ennemi.y=21;
    ennemi.w=50;
    ennemi.h=50;

        directionE=rand()%2;

    
    while (continuer)
    {   
        directionQM=direction;
        printf("dirctionQM=%d\n",directionQM);
            if(directionE==1)
            {
               ennemi.x+=5; 
               ennemi.y+=5;
            } 
            if(directionE==2)
               {
                    ennemi.x-=5;
                    ennemi.y-=5;
               }
            if(ennemi.x<2||ennemi.y<10&&directionE==2)
            {
                directionE=1;
                ennemi.x+=5;
                ennemi.y+=5;
            }
            else if(ennemi.x+ennemi.w>1000||ennemi.y+ennemi.h>500&&directionE==1)
            {
                directionE=2;
                ennemi.x-=5;
                ennemi.y-=5;
            }
       
        if(gravity(rectangle6,OBJET)==0&&gravity(rectangle1,OBJET)==0&&gravity(rectangle2,OBJET)==0&&gravity(rectangle3,OBJET)==0&&gravity(rectangle4,OBJET)==0&&gravity(rectangle5,OBJET)==0&&gravity(rectangle0,OBJET)==0&&direction!=1)
        {
            OBJET.y+=4;
            printf("oh SIIT\n");
            if(collisionBB(rectangle6,OBJET)==1||collisionBB(rectangle1,OBJET)==1||collisionBB(rectangle2,OBJET)==1||collisionBB(rectangle3,OBJET)==1||collisionBB(rectangle4,OBJET)==1||collisionBB(rectangle5,OBJET)==1||collisionBB(rectangle0,OBJET)==1)
            {
                OBJET.y-=4;
                printf("wselt\n");
            }
        }
        
        if(collisionBB(ennemi,OBJET)==1)
        {
            OBJET.x=50;
            OBJET.y=50;
        }

        if(collisionBB(portaille,OBJET)==1)
        {
            OBJET.x=818;
            OBJET.y=232;
        }
    
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break; 
        /*case SDL_MOUSEMOTION:
            printf("x=%d/y=%d\n",event.motion.x,event.motion.y);
        break;*/
          case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          {
            
              case SDLK_z:
              direction=1;
              yI=OBJET.y+OBJET.h;
              deplacer(rectangle0,rectangle1,rectangle2,rectangle3,rectangle4,rectangle5,rectangle6,&OBJET,direction);
                printf("yi-y=%d\n",yI-OBJET.y);
              if(yI-OBJET.y<=42)
                direction=0;
                printf("%d\n\n",input);
                direction=directionQM;
                if(directionQM==2)
                {
                    OBJET.x+=5;
                    OBJET.y-=1;
                }
                else if(directionQM==4)
                {
                    OBJET.x-=5;
                    OBJET.y-=1;

                }
              break;
              case SDLK_d:
              direction=2;
              deplacer(rectangle0,rectangle1,rectangle2,rectangle3,rectangle4,rectangle5,rectangle6,&OBJET,direction);
              break;

              
              case SDLK_s:
              direction=3;
              deplacer(rectangle0,rectangle1,rectangle2,rectangle3,rectangle4,rectangle5,rectangle6,&OBJET,direction);
              break;


              case SDLK_q:
              direction=4;
              deplacer(rectangle0,rectangle1,rectangle2,rectangle3,rectangle4,rectangle5,rectangle6,&OBJET,direction);
              break;
          }
          break;
         /* case SDL_KEYUP:
          switch (event.key.keysym.sym)
          {
          case SDLK_z:
             input=0;
             S=0;
             printf("%0.2f",S);

             printf("%d\n",input);
              break;
          }  */
        }
        draw(rectFond,colorR,rectangle0,rectangle1,rectangle2,rectangle3,rectangle4,rectangle5,rectangle6,color,ecran);
        SDL_FillRect(ecran,&ennemi,colorE);
        SDL_FillRect(ecran,&portaille,colorPort);
        SDL_FillRect(ecran,&OBJET,colorO); 
        SDL_Flip(ecran);    
        SDL_Delay(1);
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;  
       
        float S=frameLimit/1000;
        printf("time=%0.2f \n",S);
    }
    SDL_FreeSurface(ecran);
    
    SDL_Quit();
    return 0;
}


