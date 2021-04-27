#include "perso.h"


void initPerso(perso *p)
  
{ p->spritesheet=IMG_Load("perso.png");
    
    p->position.x=50;
    p->position.y=300;

    p->direction=2;

    p->acceleration=0;
    p->vitesse=0;
    p->vitesseV=0;

    
    p->pos_sprite.x= 0;
    p->pos_sprite.y= 200;
    p->pos_sprite.h= 100;
    p->pos_sprite.w= 100;
}




void afficherPerso(perso p, SDL_Surface * screen){
    SDL_BlitSurface(p.spritesheet,&p.pos_sprite,screen,&p.position);
}


void animerPerso (perso* p){
    p->pos_sprite.x += 100;
    if (p->pos_sprite.x >= 1500) p->pos_sprite.x = 0;

    p->pos_sprite.y = p->direction * 100 ;
}


void deplacerPerso (perso *p,int dt){
    double dx;
    dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; 
    if ((p->direction==0))// || (p->direction==2))
    {
        p->position.x += dx ;
    }
    else if ((p->direction==1))
    p->position.x -= dx ;
   
}


void saut (perso* p) {
    if (p->position.y==300)
    {
        p->vitesseV=-50;
    }
    
}










