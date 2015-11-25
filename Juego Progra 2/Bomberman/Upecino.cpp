#include "Winform.h"

namespace Bomberman
{
	Upecino::Upecino(Posicion^ p)
	{
		imagen = Imagenes::BombermanSprite;
		indiceSprite = 0;
		radioExplosion = 1;
		contadorBombas = 2;
		direccion = Direcciones::Abajo;
		estado = Estados::Idle;
		EsAtacado += gcnew Action(this, &Upecino::PierdeUnaVida);
		velocidad = 8;
		posicion = p;
		ancho = 64;
		alto = 64;
		moviendose = false;
		vida = 5;
	}
	void Upecino::MostrarUpecino(Graphics^ graphics)
	{
		if (direccion == Arriba)
			subIndice = 0;
		else if (direccion == Abajo)
			subIndice = 1;
		else if (direccion == Izquierda)
			subIndice = 2;
		else if (direccion == Derecha)
			subIndice = 3;

		if (moviendose && (estado == Idle || estado == Fantasma || estado == Inmortal))
			Avanzar(direccion);

		if (estado == Muriendo)
		{
			indiceSprite++;
			subIndice = 5;

			if (indiceSprite == 16)//termina animacion de muerte
			{
				Escena::DesactivarEscena(Winform::juego);
				Escena::ActivarEscena(Winform::gameOver);
				return;
			}
		}
		else if(estado == Celebrando)
		{
			indiceSprite++;
			subIndice = 4;

			if (indiceSprite == 16)//termina animacion de celebracón
			{
				if (Winform::malignos->malignosRestantes == 0)
				{
					Portal::visible = true;
				}
					estado = Idle;
					indiceSprite = 0;
					return;
			}
		}
		else if (estado == Inmortal)
		{
			tiempoInmortal -= 1;

			if (tiempoInmortal == 0)
				estado = Idle;
		}

		graphics->DrawImage(imagen, Rectangle(posicion->x, posicion->y, ancho, alto), Rectangle(indiceSprite / 2 * 24, subIndice * 24, 23, 23), GraphicsUnit::Pixel);
		if (this->estado == Inmortal)
			graphics->DrawString("III", gcnew Font("Arial", 16, FontStyle::Bold), gcnew SolidBrush(Color::White), Point(posicion->x + 20, posicion->y + 32));
		if (this->estado == Fantasma)
			graphics->DrawString(" F ", gcnew Font("Arial", 16, FontStyle::Bold), gcnew SolidBrush(Color::White), Point(posicion->x + 20, posicion->y + 32));
	}
	void Upecino::PierdeUnaVida()
	{
		if (estado == Idle || estado == Fantasma || estado == Celebrando)
		{
			if (vida == 1)
				this->AnimacionMuerte();
			else
			{
				this->tiempoInmortal = 50;
				this->estado = Inmortal;
			}
			this->vida -= 1;
		}
	}
	void Upecino::AnimacionMuerte()
	{
		this->moviendose = false;
		this->estado = Muriendo;
		this->indiceSprite = -1;//la animacion de muerte salga desde el principio
	}
	void Upecino::Avanzar(Direcciones pDireccion)
	{
		if (pDireccion == Derecha || pDireccion == Izquierda)
		{
			if (posicion->y % 64 == 56)
				posicion->y += 8;
			else if (posicion->y % 64 == 8)
				posicion->y -= 8;
		}
		else if (pDireccion == Arriba || pDireccion == Abajo)
		{
			if (posicion->x % 64 == 56)
				posicion->x += 8;
			else if (posicion->x % 64 == 8)
				posicion->x -= 8;
		}
			
		direccion = pDireccion;

		indiceSprite ++;

		if (indiceSprite == 8)
			indiceSprite = 10;

		else if (indiceSprite == 16)
			indiceSprite = 0;

		if (estado == Fantasma)
		{
			Objeto^ objeto = Objeto::getObjetoColisionante(direccion, velocidad, this->posicion);

			if (objeto->tipo == oBloque)
				return;
			if (objeto->tipo == oBomba)//Traspasa Bombas
			{
				posicion->Aumentar(direccion, velocidad);
				return;
			}
			if (objeto->tipo == oCaja)//Traspasa cajas
			{
				posicion->Aumentar(direccion, velocidad);
				return;
			}
			if (objeto->tipo == oItem)//Toca items
			{
				if (dynamic_cast<Item^>(objeto)->tipoItem == Powerade)
					Winform::upecino->radioExplosion = Winform::upecino->radioExplosion + 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == Cura)
					Winform::upecino->vida += 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == BombaPlus)
					Upecino::contadorBombas += 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == Pasamuros)
					estado = Fantasma;

				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
				posicion->Aumentar(direccion, velocidad);
				return;
			}
			if (objeto->tipo == oPortal)//Toca portal
			{
				if (dynamic_cast<Portal^>(objeto)->visible)
					Upecino::TocaElPortal();
				else
					posicion->Aumentar(direccion, velocidad);
				return;
			}
			if (objeto->tipo == oPiso)//Toca piso
			{
				posicion->Aumentar(direccion, velocidad);
				return;
			}
		}

		if (estado == Inmortal)
		{
			//Filtro de Bloques, Cajas, Items
			Objeto^ objeto = Objeto::getObjetoColisionante(direccion, velocidad, this->posicion);

			if (objeto->tipo == oBloque)//Toca bloque
				return;
			if (objeto->tipo == oCaja)//Toca caja
				return;
			if (objeto->tipo == oItem)//Toca item
			{
				if (dynamic_cast<Item^>(objeto)->tipoItem == Powerade)
					Winform::upecino->radioExplosion = Winform::upecino->radioExplosion + 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == Cura)
					Winform::upecino->vida += 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == BombaPlus)
					Upecino::contadorBombas += 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == Pasamuros)
					estado = Fantasma;

				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
				posicion->Aumentar(direccion, velocidad);
				return;
			}

			posicion->Aumentar(direccion, velocidad);

			return;
		}

		if (estado == Idle)
		{
			//Filtro de Bloques, Bombas, Malignos, Cajas, Items
			Objeto^ objeto = Objeto::getObjetoColisionante(direccion, velocidad, this->posicion);

			if (objeto->tipo == oBomba)
				return;
			if (objeto->tipo == oBloque)
				return;
			if (objeto->tipo == oCaja)
				return;
			if (objeto->tipo == oItem)
			{
				if (dynamic_cast<Item^>(objeto)->tipoItem == Powerade)
					Winform::upecino->radioExplosion = Winform::upecino->radioExplosion + 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == Cura)
					Winform::upecino->vida += 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == BombaPlus)
					Upecino::contadorBombas += 1;
				else if (dynamic_cast<Item^>(objeto)->tipoItem == Pasamuros)
					estado = Fantasma;

				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
				posicion->Aumentar(direccion, velocidad);
				return;
			}
			if (objeto->tipo == oPortal)
			{
				if (dynamic_cast<Portal^>(objeto)->visible)
					Upecino::TocaElPortal();
				else
					posicion->Aumentar(direccion, velocidad);
				return;
			}
			if (objeto->tipo == oPiso)
			{
				posicion->Aumentar(direccion, velocidad);
				return;
			}
		}
	}

	void Upecino::Detener()
	{
		indiceSprite = 0;
		moviendose = false;
	}

	void Upecino::TocaElPortal()
	{
		if (Winform::juego->nivel == 5)
		{
			Juego::GanarJuego();
		}
		else
		{
			Escena::DesactivarEscena(Winform::juego);
			Escena::ActivarEscena(Winform::youWin);	
		}

	}
}

