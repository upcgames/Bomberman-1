#pragma once

namespace Bomberman
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public enum Estados { Idle, Inmortal, Fantasma, Muriendo, Celebrando };
	public enum Direcciones { Arriba, Abajo, Izquierda, Derecha };
	public enum Malignos { m1, m2, m3, m4 };
	public enum Objetos { oPiso, oBloque, oBomba, oCaja, oItem };
	public enum Items { Cura, Powerade };

	ref class Winform;
	ref class Posicion;
	ref class Figura;
	ref class Vivo;
	ref class Upecino;
	ref class Maligno;
	ref class Maligno1;
	ref class Maligno2;
	ref class Maligno3;
	ref class Maligno4;
	ref class Objeto;
	ref class Piso;
	ref class Caja;
	ref class Bloque;
	ref class Item;
	ref class Bomba;
	ref class MatrizObjetos;
	ref class ArrBombas;
	ref class ArrMalignos;
	ref class Nivel;
	ref class Nivel1;
	ref class Nivel2;
	ref class Nivel3;
	ref class Nivel4;
	ref class Nivel5;
	ref class Escena;
	ref class Introduccion;
	ref class Inicio;
	ref class Juego;
}


