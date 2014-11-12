#include "Nave.h"
#include "Config.h"
#include "Sprite.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen){
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w=sprite->WidthModule(0);
	h=sprite->HeightModule(0);

	x=(WIDTH_SCREEN / 2)-(w/2);
	y=(HEIGHT_SCREEN-80)-(h);
}
Nave::~Nave(){
	delete sprite;
}
void Nave::Pintar(){
	sprite->PintarModulo(moduleUsing,x,y);
}
void Nave::MoverDerecha(int posicion){
	x += posicion;
}
int Nave::obtenerX(){
	return x;
}
int Nave::obtenerY(){
	return y;
}
int Nave::obtenerW(){
	return w;
}
int Nave::obtenerH(){
	return h;
}