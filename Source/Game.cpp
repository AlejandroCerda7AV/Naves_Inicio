#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>


CGame::CGame(){	
	
	estado= Estado::ESTADO_INICIANDO;//ACT2: Mal, aqui debes de indicar tu estado inicial.
	atexit(SDL_Quit);
}

//ACT3: Mal, falto agregar este metodo
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen=SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	if (screen==NULL){
		printf("Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer juego", NULL);

	nave=new Nave(screen,"../Data/MiNave.bmp",(WIDTH_SCREEN/2),(HEIGHT_SCREEN-80);
	enemigo=new Nave(screen,"../Data/enemigo.bmp",0,0);

	enemigoArreglo=new Nave*[10];
	for(int i=0;i<10;i++)
		enemigoArreglo[0]=new Nave(screen,"../Data/enemigo.bmp",0,0);

	enemigo->SetStep(4);
	for(int i=0;i<10;i++)
		enemigoArreglo[i]->SetStep(4);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	int bandera=0;

	while (salirJuego == false){

		//Maquina de estados
		switch(estado){
		case  Estado::ESTADO_INICIANDO:
			printf("\n1. ESTADO_INICIANDO");
			Iniciando();
			estado=ESTADO_MENU;
			break;

		case Estado::ESTADO_MENU:
			SDL_FillRect(screen
			
			//screen=SDL_SetVideoMode
			nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/umi.jpg","rb"));

			SDL_BlitSurface(nave, NULL, screen, NULL);
			SDL_FreeSurface(nave);
			printf("\n2. ESTADO_MENU");
			if(bandera<=0)
			{
				estado=ESTADO_JUGANDO;
			printf("\n3. ESTADO_JUGANDO");
			
			}
			else
			{
				estado=ESTADO_FINALIZADO;
			printf("\n5. ESTADO_FINALIZADO");
			
			}

			nave->Pintar();
			enemigo->Pintar();
			for(int i=0;i<10;i++)
				enemigoArreglo[i]->Pintar();
			break;

		case Estado::ESTADO_JUGANDO:
			printf("\n3. ESTADO_JUGANDO");
			estado=ESTADO_TERMINADO;
			break;

		case Estado::ESTADO_TERMINADO:
			printf("\n4. ESTADO_TERMINADO");
			estado=ESTADO_FINALIZADO;
			bandera=1;
			break;

		case Estado::ESTADO_FINALIZADO:
			printf("\n5. ESTADO_FINALIZADO");
			salirJuego = true;
			break;
			
		};
	}
	return true;
}

void CGame::MoverEnemigo(){
	for(int i=0;i<10;i++)
	switch(enemigo->ObtenerStepActual()){
	case 0:
		if(!enemigoArreglo[i]->IsRunningAnimacion())
			enemigoArreglo[i]->Mover(2,WIDTH_SCREEN-enemigo->obtenerW());
		//enemigo->IncrementarStep();
		break;
	case 1:
		enemigoArreglo[i]->IncrementarStep();
		break;
	case 2:
		if(!enemigoArreglo[i]->IsRunningAnimacion())
			enemigoArreglo[i]->Mover(-2,WIDTH_SCREEN-enemigo->obtenerW());
		//enemigo->IncrementarStep();
		break;
	case 3:
		enemigo->IncrementarStep();
		break;
	}
