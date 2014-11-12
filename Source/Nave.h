#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave{

int x;
int y;
int w;
int h;
int posicionActual;
int posicionfinal;
int stepsActual;
int stepsFinal;
int moduleUsing;

Sprite * sprite;
public:
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int modulo);
	~Nave();
	void Pintar();
	void Mover(int posicion);
	void Mover(int brinco);
	int obtenerX();
	int obtenerY();
	int obtenerW();
	int obtenerH();

};

#endif