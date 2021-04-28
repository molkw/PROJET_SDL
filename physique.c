#include "physique.h"
#include <SDL/SDL.h>

int collision(const SDL_Rect *posPerso, const SDL_Rect *posEnmie)
{
    if (((posPerso->x + posPerso->w)< posEnmie->x) || (posPerso->x > posEnmie->x + posEnmie->w) ||
        (posPerso->y + posPerso->h < posEnmie->y) || (posPerso->y > posEnmie->y + posEnmie->h))
    {
        return 0;
    }
    return 1;
}
