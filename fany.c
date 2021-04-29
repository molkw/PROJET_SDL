#include"main.h"

void draw(SDL_Rect rectFond,Uint32 colorR,SDL_Rect rectangle0,SDL_Rect rectangle1, SDL_Rect rectangle2, SDL_Rect rectangle3, SDL_Rect rectangle4, SDL_Rect rectangle5, SDL_Rect rectangle6,Uint32 color, SDL_Surface *ecran)
{
        if (SDL_FillRect(ecran,&rectFond,colorR)!=0)
        printf("error\n");

        if (SDL_FillRect(ecran,&rectangle0,color)!=0)
        printf("error\n");
        
        if(SDL_FillRect(ecran,&rectangle1,color)!=0)
        printf("error\n");

        if(SDL_FillRect(ecran,&rectangle2,color)!=0)
        printf("error\n");
       
        if(SDL_FillRect(ecran,&rectangle3,color)!=0)
        printf("error\n");
     
        if(SDL_FillRect(ecran,&rectangle4,color)!=0)
        printf("error\n");
        
        
        if(SDL_FillRect(ecran,&rectangle5,color)!=0)
        printf("error\n");

        if (SDL_FillRect(ecran,&rectangle6,color)!=0)
        printf("error\n");
}

void init_map(SDL_Rect *rectFond,SDL_Rect *rectangle0,SDL_Rect *rectangle1,SDL_Rect  *rectangle2,SDL_Rect  *rectangle3,SDL_Rect  *rectangle4,SDL_Rect  *rectangle5, SDL_Rect *rectangle6 )
{

    rectFond->x=0;
    rectFond->y=0;
    rectFond->h=577;
    rectFond->w=1058;

    rectangle0->x=506;
    rectangle0->y=350;
    rectangle0->h=30;
    rectangle0->w=120;


    rectangle1->x=0;
    rectangle1->y=200;
    rectangle1->h=400;
    rectangle1->w=120;

    rectangle2->x=195;
    rectangle2->y=160;
    rectangle2->h=30;
    rectangle2->w=181;

    rectangle3->x=422;
    rectangle3->y=193;
    rectangle3->h=30;
    rectangle3->w=251;

    rectangle4->x=755;
    rectangle4->y=272;
    rectangle4->h=30;
    rectangle4->w=181;

    rectangle5->x=955;
    rectangle5->y=200;
    rectangle5->h=400;
    rectangle5->w=120;

    rectangle6->x=0;
    rectangle6->y=500;
    rectangle6->h=178;
    rectangle6->w=1058;
    
}

void delay(unsigned int frameLimit)
{

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
   int collisionBB(SDL_Rect rectangle,SDL_Rect OBJET)
  {
      if((rectangle.x<OBJET.x+OBJET.w)&&(rectangle.x+rectangle.w>OBJET.x)&&(rectangle.y<OBJET.y+OBJET.h)&&(rectangle.y+rectangle.h>OBJET.y))
        return 1;
      else
        return 0;
  }

  int gravity(SDL_Rect rectangle, SDL_Rect OBJET)
  {
      if(collisionBB(rectangle,OBJET)==0)
        return 0;
      else
        return 1;

  }

  void deplacer(SDL_Rect rectangle0,SDL_Rect rectangle1,SDL_Rect rectangle2,SDL_Rect rectangle3,SDL_Rect rectangle4,SDL_Rect rectangle5,SDL_Rect rectangle6, SDL_Rect *OBJET,int direction)
  {
        if(direction==1)
       {
            if(OBJET->y==0)
            { 
             OBJET->y=+8;
            }
               if(collisionBB(rectangle1,*OBJET)==1)
                {
                    OBJET->y+=14;
                    printf("eb3edni\n");
                }
                 else if(collisionBB(rectangle0,*OBJET)==1)
                {
                    OBJET->y+=14;
                    printf("eb3edni\n");
                } 
               else if(collisionBB(rectangle2,*OBJET)==1)
                {
                    OBJET->y+=14;
                    
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle3,*OBJET)==1)
                {
                    OBJET->y+=14;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle4,*OBJET)==1)
                {
                    OBJET->y+=14;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle5,*OBJET)==1)
                {
                    OBJET->y+=14;
                    printf("eb3edni\n");
                } 
                else if(collisionBB(rectangle6,*OBJET)==1)
                {
                    OBJET->y+=14;
                    printf("eb3edni\n");
                } 
                else   
                    printf("jawek nice\n"); 
                    OBJET->y-=10;
        }

       if(direction==2)
      {
          if(OBJET->x+OBJET->w==1058)
               { 
                   OBJET->x-=2;
               }
               if(collisionBB(rectangle1,*OBJET)==1)
                {
                    OBJET->x-=7;
                    printf("eb3edni\n");
                }
                 else if(collisionBB(rectangle0,*OBJET)==1)
                {
                    OBJET->x-=7;
                    printf("eb3edni\n");
                } 
               else if(collisionBB(rectangle2,*OBJET)==1)
                {
                    OBJET->x-=7;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle3,*OBJET)==1)
                {
                    OBJET->x-=7;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle4,*OBJET)==1)
                {
                    OBJET->x-=7;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle5,*OBJET)==1)
                {
                    OBJET->x-=7;
                    printf("eb3edni\n");
                } 
                else if(collisionBB(rectangle6,*OBJET)==1)
                {
                    OBJET->x-=7;
                    printf("eb3edni\n");
                } 
                else   
                printf("jawek nice\n");
              OBJET->x+=2;
    }

    if(direction==3)
    {
        if(OBJET->y+OBJET->h==500)
               { 
                   OBJET->y-=2;
                  
               }
               if(collisionBB(rectangle1,*OBJET)==1)
                OBJET->y-=7;
                else if(collisionBB(rectangle0,*OBJET)==1)
                    OBJET->y-=10; 
               else if(collisionBB(rectangle2,*OBJET)==1)
                    OBJET->y-=10;
                else if(collisionBB(rectangle3,*OBJET)==1)
                    OBJET->y-=10; 
                else if(collisionBB(rectangle4,*OBJET)==1)
                    OBJET->y-=10;
                else if(collisionBB(rectangle5,*OBJET)==1)
                    OBJET->y-=10; 
                else if(collisionBB(rectangle6,*OBJET)==1)
                    OBJET->y-=10;
                else   
                    printf("jawek nice\n");
              OBJET->y++;
    }

    if(direction==4)
    {
        if(OBJET->x==0)
               { 
                   OBJET->x=+2;
               }
               if(collisionBB(rectangle1,*OBJET)==1)
                {
                    OBJET->x+=7;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle0,*OBJET)==1)
                {
                    OBJET->x+=7;
                    printf("eb3edni\n");
                }
               else if(collisionBB(rectangle2,*OBJET)==1)
                {
                    OBJET->x+=7;
                    printf("eb3edni\n");
                } 
                else if(collisionBB(rectangle3,*OBJET)==1)
                {
                    OBJET->x+=7;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle4,*OBJET)==1)
                {
                    OBJET->x+=7;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle5,*OBJET)==1)
                {
                    OBJET->x+=7;
                    printf("eb3edni\n");
                }
                else if(collisionBB(rectangle6,*OBJET)==1)
                {
                    OBJET->x+=7;
                    printf("eb3edni\n");
                }
                else   
                    printf("jawek nice\n");
              OBJET->x-=2;
    }

  }

  void JUMP(SDL_Rect *OBJET,int direction)
  {
      if(direction==2)
      {
          OBJET->y-=7;
          OBJET->x+=2;
      }
      if(direction==4)
      {
          OBJET->y-=7;
          OBJET->x-=2;
      }
  }
