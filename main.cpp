#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *Hero = NULL;
    SDL_Rect positionFond, positionHero;
    SDL_Event event;
    int continuer = 1;

    positionFond.x = 0;
    positionFond.y = 0;
    positionHero.x = 400;
    positionHero.y = 200;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(SDL_LoadBMP("Logo/sdl_icone.bmp"), NULL);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("ESGI Quest", NULL);

    imageDeFond = SDL_LoadBMP("img/map1.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    /* Chargement et blittage de Zozor sur la scène */
    Hero = SDL_LoadBMP("img/zozor.bmp");

    /* On rend le bleu derrière Zozor transparent : */
    SDL_SetColorKey(Hero, SDL_SRCCOLORKEY, SDL_MapRGB(Hero->format, 0, 0, 255));
    SDL_BlitSurface(Hero, NULL, ecran, &positionHero);
    SDL_EnableKeyRepeat(10, 1);
        while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;

                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: // Flèche haut
                        positionHero.y--;
                        break;
                    case SDLK_DOWN: // Flèche bas
                        positionHero.y++;
                        break;
                    case SDLK_RIGHT: // Flèche droite
                        positionHero.x++;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                        positionHero.x--;
                        break;
                }
                break;
        }

        /* On place Zozor à sa nouvelle position */
        SDL_BlitSurface(Hero, NULL, ecran, &positionHero);
        /* On met à jour l'affichage */
        SDL_Flip(ecran);
        imageDeFond = SDL_LoadBMP("img/map1.bmp");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_BlitSurface(Hero, NULL, ecran, &positionHero);

    }

    SDL_Flip(ecran);
    pause();

    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(Hero);
    SDL_Quit();

    return EXIT_SUCCESS;
}


void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
