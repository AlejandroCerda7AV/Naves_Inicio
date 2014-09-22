#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	estado;//ACT2: Mal, aqui debes de indicar tu estado inicial.
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case  Estado::ESTADO_INICIANDO:
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
