#include "Winform.h"

namespace Bomberman
{
	Posicion::Posicion(int pX, int pY)
	{
		x = pX;
		y = pY;
	}

	Posicion::Posicion(int pX, int pY, int multiplo)
	{
		float xx = pX * 1.0f / multiplo;
		float yy = pY * 1.0f / multiplo;

		xx += 0.5;
		yy += 0.5;

		x = int(xx) * multiplo;
		y = int(yy) * multiplo;
	}

	bool Posicion::EsIgualA(Posicion^ p)
	{
		if (p->x == this->x && p->y == this->y)
			return true;
		else
			return false;
	}

	void Posicion::Igualar(Posicion^ p)
	{
		x = p->x;
		y = p->y;
	}

	void Posicion::Igualar(int pX, int pY, int multiplo)
	{
		float xx = pX * 1.0f / multiplo;
		float yy = pY * 1.0f / multiplo;

		xx += 0.5;
		yy += 0.5;

		x = int(xx) * multiplo;
		y = int(yy) * multiplo;
	}

	void Posicion::Aumentar(Direcciones direccion, int velocidad)
	{
		if (direccion == Direcciones::Arriba)
			y -= velocidad;
		else if (direccion == Direcciones::Abajo)
			y += velocidad;
		if (direccion == Direcciones::Izquierda)
			x -= velocidad;
		else if (direccion == Direcciones::Derecha)
			x += velocidad;
	}

	Posicion^ Posicion::getIncrementada(Direcciones direccion, int velocidad)
	{
		int xx = x;
		int yy = y;

		if (direccion == Direcciones::Arriba)
			yy -= velocidad;
		else if (direccion == Direcciones::Abajo)
			yy += velocidad;
		if (direccion == Direcciones::Izquierda)
			xx -= velocidad;
		else if (direccion == Direcciones::Derecha)
			xx += velocidad;

		return gcnew Posicion(xx, yy);
	}
	
	void Posicion::ToZero()
	{
		x = 0;
		y = 0;
	}

	Rectangle Posicion::getBody(int pAncho, int pAlto)
	{
		return Rectangle(x, y, pAncho, pAlto);
	}
}