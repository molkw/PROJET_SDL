#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


//#include "update_score.h"



#include "perso.h"


int main()
{ TTF_Init();

/*------partie declaration des variables-------*/
TTF_Font *police=NULL;
SDL_Surface *texte1=NULL;
SDL_Surface *number1=NULL;




SDL_Surface *screen;
TTF_Font *text=NULL;
SDL_Surface *texte=NULL;
TTF_Font *text2=NULL;
SDL_Surface *texte2=NULL;
SDL_Event event;
SDL_Surface *back;
SDL_Surface *coll;
perso p;
perso p2;

int continuer=1,droite=0,gauche=0,up=0,dir=2,droite2=0,gauche2=0,up2=0,dir2=2;
Uint32 dt, t_prev;




/*-------partie initialisation-------*/
screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
back=IMG_Load("background.png");
initPerso(&p);
 
p2.spritesheet=IMG_Load("perso2.jpg");
    
    p2.position.x=50;
    p2.position.y=300;

    p2.direction=2;

    p2.acceleration=0;
    p2.vitesse=0;
    p2.vitesseV=0;

    
    p2.pos_sprite.x= 0;
    p2.pos_sprite.y= 200;
    p2.pos_sprite.h= 100;
    p2.pos_sprite.w= 100;

   /////////////////////////


//sccccoreeeeee
  

police = TTF_OpenFont("outils/avocado.ttf", 35);

SDL_Color blanco={255,255,255}; 
texte1= TTF_RenderText_Blended(police,"score :",blanco);
p.position_textee.x=15;
p.position_textee.y=20;


////--------gestion de score-----//
 
p.number[20];
p.valeur_score=2000;
p.valeur_score=p.valeur_score+1;
sprintf(p.number, "%d",(p.valeur_score));

number1= TTF_RenderText_Blended(police,p.number,blanco);


p.position_number.x=170;
p.position_number.y=20;
TTF_CloseFont(police);



//testevie2
text=TTF_OpenFont("outils/avocado.ttf",35);
SDL_Color couleur={255,255,255};
texte= TTF_RenderText_Blended(text,"Vie2 :",couleur);
p.position_texte.x=700;
p.position_texte.y=57;
TTF_CloseFont(text);
  
//testevie1
text2=TTF_OpenFont("outils/avocado.ttf",35);
SDL_Color blanc={255,255,255};
 texte2= TTF_RenderText_Blended(text2,"Vie1 :",blanc);
 p2.position_texte.x=700;
 p2.position_texte.y=20;
TTF_CloseFont(text2);

//phtc1

p.image_vie[0]=IMG_Load("outils/hearts03.png") ;
p.image_vie[1]=IMG_Load("outils/hearts02.png") ;
p.image_vie[2]=IMG_Load("outils/hearts01.png") ;
p.image_vie[3]=IMG_Load("outils/hearts00.png") ;
// positions
 p.position_vie.x=800;
 p.position_vie.y=57;
 p.val=3;
 
//phtc2
p2.image_vie[0]=IMG_Load("outils/hearts03.png") ;
p2.image_vie[1]=IMG_Load("outils/hearts02.png") ;
p2.image_vie[2]=IMG_Load("outils/hearts01.png") ;
p2.image_vie[3]=IMG_Load("outils/hearts00.png") ;
// positions
 p2.position_vie.x=800;
 p2.position_vie.y=20;
 p2.val=3;


//------------gestion de vie--------//
int vies=3;
 
   p.val--;
vies--;
    if (vies==2)
    {
	SDL_FreeSurface(p.image_vie[0]);}
    else if (vies==1)
    {SDL_FreeSurface(p.image_vie[1]);}  
    else if (vies==0)
    {SDL_FreeSurface(p.image_vie[2]);}
	//printf("val vie :%d \n",p.val);

/*--------- debut dboucle de jeu -----------*/
while (continuer)
{
t_prev=SDL_GetTicks();

  /*-------- gestion de l'input--------*/  
while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                break;
            case SDLK_UP:
                up=1;
                break;  

         case SDLK_d:
                droite2=1;
                break;
            case SDLK_q:
                gauche2=1;
                break;
            case SDLK_z:
                up2=1;
                break; 

      
        }
    break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                dir=2;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
                gauche=0;
                p.vitesse=0;
                dir=3;
                break;
            case SDLK_UP:
                up=0;
                break;    

           case SDLK_d:
                droite2=0;
                dir2=2;
                p2.vitesse=0;
                break;
            case SDLK_q:
                gauche2=0;
                p2.vitesse=0;
                dir2=3;
                break;
            case SDLK_z:
                up2=0;
                break; 

    
        }
    break;
    
    }
}//fin de linput



/*-------------update----------*/

if (droite==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=0;


}
if (gauche==1)
{
    p.vitesse=10;
    p.acceleration+=0.5;
    p.direction=1;

}
if (up==1) 
saut(&p);

if (droite2==1)
{
    p2.vitesse=10;
    p2.acceleration+=0.5;
    p2.direction=0;
}
if (gauche2==1)
{
    p2.vitesse=10;
    p2.acceleration+=0.5;
    p2.direction=1;
}
if (up2==1) saut(&p2);




p.acceleration -=0.3;
p2.acceleration -=0.3;

if (p.acceleration<0 ) p.acceleration=0;
if (p.acceleration>4 ) p.acceleration=4;



if (p2.acceleration<0 ) p2.acceleration=0;
if (p2.acceleration>4 ) p2.acceleration=4;

SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;
deplacerPerso(&p,dt);
animerPerso(&p);
deplacerPerso(&p2,dt);
animerPerso(&p2);

if ((p.vitesse==0)&&(p.acceleration==0))
{
    p.direction=dir;
}

p.position.y += p.vitesseV;
p.vitesseV += 10; 
if (p.position.y >= 300)
{
    p.vitesseV=0;
    p.position.y=300;
}

if ((p2.vitesse==0)&&(p2.acceleration==0))
{
    p2.direction=dir2;
}

p2.position.y += p2.vitesseV;
p2.vitesseV += 10; 
if (p2.position.y >= 300)
{
    p2.vitesseV=0;
    p2.position.y=300;
}






/*---------------affichage------------
*/
SDL_BlitSurface(back,NULL,screen,NULL);
afficherPerso(p,screen);
afficherPerso(p2,screen);
   

      
SDL_BlitSurface(p.image_vie[p.val],NULL,screen,(&p.position_vie));
SDL_BlitSurface(p2.image_vie[p2.val],NULL,screen,(&p2.position_vie));

SDL_BlitSurface(texte,NULL,screen,&(p.position_texte));
SDL_BlitSurface(texte2,NULL,screen,&(p2.position_texte));


 SDL_BlitSurface(texte1, NULL, screen,&p.position_textee);
SDL_BlitSurface(number1, NULL, screen,&p.position_number);
	


   //free
/*SDL_FreeSurface(p.image_vie[0]);
SDL_FreeSurface(p.image_vie[1]);
SDL_FreeSurface(p.image_vie[2]);
SDL_FreeSurface(p.image_vie[3]);*/

SDL_Flip(screen);
SDL_Delay(50);


}
TTF_Quit();
}

