#include "Winform.h"

namespace Bomberman
{
	void Nivel::MostrarNivel(Graphics^ graphics)
	{
		for (int x = 0; x < 13; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				if (Winform::objetos->matriz[x, y]->tipo == oPiso)
					dynamic_cast<Piso^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
				else if (Winform::objetos->matriz[x, y]->tipo == oBloque)
					dynamic_cast<Bloque^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
				else if (Winform::objetos->matriz[x, y]->tipo == oCaja)
					dynamic_cast<Caja^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
				else if (Winform::objetos->matriz[x, y]->tipo == oItem)
					dynamic_cast<Item^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
				else if (Winform::objetos->matriz[x, y]->tipo == oPortal)
					dynamic_cast<Portal^>(Winform::objetos->matriz[x, y])->MostrarSprite(graphics);
			}
		}
	}

	Objeto^ Caja::getContenidoCaja(Posicion^ p)
	{
		int random = Winform::aleatorio->Next(100);

		if (random < 40)
		{
			if (random < 5)
				return gcnew Item(gcnew Posicion(p->x, p->y), Cura);
			else if (random < 20)
				return gcnew Item(gcnew Posicion(p->x, p->y), BombaPlus);
			else if (random < 30)
				return gcnew Item(gcnew Posicion(p->x, p->y), Powerade);
			else
				return gcnew Item(gcnew Posicion(p->x, p->y), Pasamuros);
		}
		else
			return gcnew Piso(gcnew Posicion(p->x, p->y));
	}

	Objeto^ Objeto::getObjeto(Posicion^ posicion)
	{
		if (posicion->x < 0 || posicion->x > 768 || posicion->y < 0 || posicion->y > 512)
			return gcnew Bloque(gcnew Posicion(0, 0));

		return Winform::objetos->matriz[posicion->x / 64, posicion->y / 64];
		
	}

	void Nivel::generarMatrizObjetos(Objetos matriz[9][13])
	{
		matrizObjetos = gcnew MatrizObjetos();
		matrizObjetos->matriz = gcnew array<Objeto^, 2>(13, 9);	

		for (int y = 0; y < 9; y++)
		{
			for (int  x = 0; x < 13; x++)
			{
				if (matriz[y][x] == oPiso)
					matrizObjetos->matriz[x, y] = gcnew Piso(gcnew Posicion(x * 64, y * 64));
				else if (matriz[y][x] == oBloque)
					matrizObjetos->matriz[x, y] = gcnew Bloque(gcnew Posicion(x * 64, y * 64));
				else if (matriz[y][x] == oCaja)
					matrizObjetos->matriz[x, y] = gcnew Caja(gcnew Posicion(x * 64, y * 64));
				else if (matriz[y][x] == oPortal)
					matrizObjetos->matriz[x, y] = gcnew Portal(gcnew Posicion(x * 64, y * 64));
			}
		}
	}

	void Nivel::PasarANivel(int pNivel)
	{
		Winform::juego->nivel = pNivel;

		if (pNivel == 1)
		{
			Winform::nivel1 = gcnew Nivel1();
			Winform::objetos = Winform::nivel1->matrizObjetos;
			Winform::malignos = Winform::nivel1->arregloMalignos;
		}
		else if (pNivel == 2)
		{
			Winform::nivel2 = gcnew Nivel2();
			Winform::objetos = Winform::nivel2->matrizObjetos;
			Winform::malignos = Winform::nivel2->arregloMalignos;
		}
		else if (pNivel == 3)
		{
			Winform::nivel3 = gcnew Nivel3();
			Winform::objetos = Winform::nivel3->matrizObjetos;
			Winform::malignos = Winform::nivel3->arregloMalignos;
		}
		else if (pNivel == 4)
		{
			Winform::nivel4 = gcnew Nivel4();
			Winform::objetos = Winform::nivel4->matrizObjetos;
			Winform::malignos = Winform::nivel4->arregloMalignos;
		}
		else if (pNivel == 5)
		{
			Winform::nivel5 = gcnew Nivel5();
			Winform::objetos = Winform::nivel5->matrizObjetos;
			Winform::malignos = Winform::nivel5->arregloMalignos;
		}

		Winform::bombas->LimpiarArreglo();
		Winform::winform->upecino->indiceSprite = 0;
		Winform::winform->upecino->radioExplosion = 1;
		Winform::winform->upecino->direccion = Direcciones::Abajo;
		Winform::winform->upecino->estado = Estados::Idle;
		Winform::winform->upecino->moviendose = false;
		Winform::winform->upecino->posicion->ToZero();
		Portal::visible = false;
	}

}