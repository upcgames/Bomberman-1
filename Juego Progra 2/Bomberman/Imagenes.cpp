#include "WinForm.h"

namespace Bomberman
{
	Imagenes::Imagenes()
	{
		//Personajes Bomberman
		Imagenes::BombermanSprite = Image::FromFile("Imagenes\\Personajes\\Bomberman.png");
		Imagenes::BomberdogSprite = Image::FromFile("Imagenes\\Personajes\\Bomberdog.png");
		Imagenes::PirateBombermanSprite = Image::FromFile("Imagenes\\Personajes\\PirateBomberman.png");

		//Profesores Malignos
		Imagenes::NinjaBombermanSprite = Image::FromFile("Imagenes\\Personajes\\NinjaBomberman.png");

		//Objetos
		Imagenes::BombasSprite = Image::FromFile("Imagenes\\Objetos\\Bombas.png");
		Imagenes::Cursor = Image::FromFile("Imagenes\\Objetos\\Cursor.png");
		Imagenes::Portal = Image::FromFile("Imagenes\\Objetos\\Portal.png");

		Imagenes::BombaPlus = Image::FromFile("Imagenes\\Objetos\\BombaPlus.png");
		Imagenes::Cura      = Image::FromFile("Imagenes\\Objetos\\Cura.png");
		Imagenes::PasaMuros = Image::FromFile("Imagenes\\Objetos\\PasaMuros.png");
		Imagenes::Powerade = Image::FromFile("Imagenes\\Objetos\\Powerade.png");
	
		Imagenes::Bloque1   = Image::FromFile("Imagenes\\Objetos\\Bloque1.png");
		Imagenes::Bloque2   = Image::FromFile("Imagenes\\Objetos\\Bloque2.png");
		Imagenes::Bloque3   = Image::FromFile("Imagenes\\Objetos\\Bloque3.png");
		Imagenes::Bloque4   = Image::FromFile("Imagenes\\Objetos\\Bloque4.png");
		Imagenes::Bloque5   = Image::FromFile("Imagenes\\Objetos\\Bloque5.png");
		Imagenes::Caja1     = Image::FromFile("Imagenes\\Objetos\\Caja1.png");
		Imagenes::Caja2     = Image::FromFile("Imagenes\\Objetos\\Caja2.png");
		Imagenes::Caja3     = Image::FromFile("Imagenes\\Objetos\\Caja3.png");
		Imagenes::Caja4     = Image::FromFile("Imagenes\\Objetos\\Caja4.png");
		Imagenes::Caja5     = Image::FromFile("Imagenes\\Objetos\\Caja5.png");
		Imagenes::Piso1     = Image::FromFile("Imagenes\\Objetos\\Piso1.png");
		Imagenes::Piso2     = Image::FromFile("Imagenes\\Objetos\\Piso2.png");
		Imagenes::Piso3     = Image::FromFile("Imagenes\\Objetos\\Piso3.png");
		Imagenes::Piso4     = Image::FromFile("Imagenes\\Objetos\\Piso4.png");
		Imagenes::Piso5     = Image::FromFile("Imagenes\\Objetos\\Piso5.png");

		//Interfaces
		Imagenes::Introducion = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
		Imagenes::Inicio = Image::FromFile("Imagenes\\Interfaces\\Inicio.png");
		Imagenes::Instrucciones = Image::FromFile("Imagenes\\Interfaces\\Instrucciones.png");
		Imagenes::Pausa = Image::FromFile("Imagenes\\Interfaces\\Pausa.png");
		Imagenes::YouWin = Image::FromFile("Imagenes\\Interfaces\\YouWin.png");
		Imagenes::Congratulations = Image::FromFile("Imagenes\\Interfaces\\Congratulations.png");
		Imagenes::GameOver = Image::FromFile("Imagenes\\Interfaces\\GameOver.png");
		Imagenes::Creditos = Image::FromFile("Imagenes\\Interfaces\\Creditos.png");
	}

}