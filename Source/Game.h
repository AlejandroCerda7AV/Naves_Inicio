#include <SDL.h>
#include <SDL_image.h>
#include "Nave.h"

class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();
	
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO
	};

private:
	void Iniciando();
	bool esLimitePantalla(Nave *objeto, int bandera);
	Uint8 *keys;
	SDL_Event event;


	SDL_Surface *screen;
	SDL_Surface *nave;
	Estado estado;
	Nave*titulo;
	Nave*menu;
	Nave*fondo;

};