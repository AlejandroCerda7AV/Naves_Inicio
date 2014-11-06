#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave{

int x;
int y;
int w;
int h;

Sprite * sprite;
public:
	Nave(SDL_Surface * screen, char * rutaImagen);
	~Nave();
	void Pintar();
	void MoverDerecha(int posicion);
	int obtenerX();
	int obtenerY();
	int obtenerW();
	int obtenerH();

};

#endif