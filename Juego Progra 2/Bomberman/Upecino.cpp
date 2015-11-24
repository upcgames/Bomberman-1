#include "Winform.h"

namespace Bomberman
{
	Upecino::Upecino(Posicion^ p, String^ pNombre)
	{
		imagen = Image::FromFile("Bomberman1.png");
		indiceSprite = 0;
		radioExplosion = 1;
		direccion = Direcciones::Abajo;
		estado = Estados::Idle;
		EsAtacado += gcnew Action(this, &Upecino::PierdeUnaVida);
		velocidad = 8;
		posicion = p;
		ancho = 64;
		alto = 64;
		moviendose = false;
		vida = 5;
		nombre = pNombre;
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
				Threading::Thread::Sleep(2000);
				Escena::ActivarEscena(Winform::inicio);
				Escena::DesactivarEscena(Winform::juego);
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
		if (estado == Inmortal)
			graphics->DrawString("III", gcnew Font("Arial", 16, FontStyle::Bold), gcnew SolidBrush(Color::White), Point(posicion->x + 20, posicion->y + 32));
	}
	void Upecino::PierdeUnaVida()
	{
		if (estado == Idle || estado == Fantasma || estado == Celebrando)
		{
			if (vida == 0)
			{
				moviendose = false;
				estado = Muriendo;
				indiceSprite = -1;
			}
			else
			{
				tiempoInmortal = 50;
				estado = Inmortal;
			}

			vida -= 1;
		}
	}
	void Upecino::CuandoMuere()
	{

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

		indiceSprite += 1;

		if (indiceSprite == 8)
			indiceSprite = 10;

		else if (indiceSprite == 16)
			indiceSprite = 0;

		if (estado == Fantasma)
		{
			//Filtro de Bloques, Malignos, Items
			posicion->Aumentar(direccion, velocidad);
			return;
		}

		if (estado == Inmortal)
		{
			//Filtro de Bloques, Cajas, Items
			Objeto^ objeto = Nivel::getObjetoColisionante(direccion, velocidad);

			if (objeto->tipo == oBloque)
				return;
			if (objeto->tipo == oCaja)
				return;
			if (objeto->tipo == oItem)
			{
				if (dynamic_cast<Item^>(objeto)->tipoItem == Powerade)
					Winform::upecino->radioExplosion = Winform::upecino->radioExplosion + 1;

				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
			}

			posicion->Aumentar(direccion, velocidad);

			return;
		}

		if (estado == Idle)
		{
			//Filtro de Bloques, Bombas, Malignos, Cajas, Items
			Objeto^ objeto = Nivel::getObjetoColisionante(direccion, velocidad);

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

				Winform::objetos->matriz[objeto->posicion->x / 64, objeto->posicion->y / 64] = gcnew Piso(objeto->posicion);
				posicion->Aumentar(direccion, velocidad);
				return;
			}
			if (objeto->tipo == oPortal && dynamic_cast<Portal^>(objeto)->visible)
			{
				Upecino::TocaElPortal();
			}
			if (objeto->tipo == oPortal && !(dynamic_cast<Portal^>(objeto)->visible))
			{
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
			Nivel::PasarANivel(Winform::juego->nivel + 1);
		}

	}
}

