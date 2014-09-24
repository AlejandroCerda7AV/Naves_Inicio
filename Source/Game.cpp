#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>


CGame::CGame(){
	estado;
	SDL_Surface*screen;
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
		screen=SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	if (screen==NULL){
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip(screen);
	SDL_WM_SetCaption("Mi primer juego", NULL);
	atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case  Estado::ESTADO_INICIANDO:
			void Iniciando();
			{
				//screen=SDL_SetVideoMode
				nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/umi.jpg","rb"));

				SDL_BlitSurface(nave, NULL, screen, NULL);
				SDL_FreeSurface(nave);
			}
			break;
		case 	Estado::ESTADO_MENU:
			break;
		case Estado::ESTADO_JUGANDO:
			break;
		case Estado::ESTADO_TERMINADO:
			break;
		case Estado::ESTADO_FINALIZADO:
			break;

			salirJuego = true;
			break;
		};
    }
	return true;
}
