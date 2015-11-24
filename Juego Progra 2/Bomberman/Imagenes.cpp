#include "WinForm.h"

namespace Bomberman
{
	Imagenes::Imagenes()
	{
		//Personajes Bomberman
		Imagenes::BombermanSprite = Image::FromFile("Bomberman.png");
		Imagenes::BomberdogSprite = Image::FromFile("Bomberdog.png");

		//Profesores Malignos
		Imagenes::NinjaBombermanSprite = Image::FromFile("NinjaBomberman.png");

		//Objetos
		Imagenes::BombasSprite = Image::FromFile("Bombas.png");

		//Interfaces
		Imagenes::Introducion = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
		Imagenes::Inicio = Image::FromFile("Imagenes\\Interfaces\\Inicio.png");
		Imagenes::Instrucciones = Image::FromFile("Imagenes\\Interfaces\\Instrucciones.png");
		Imagenes::Pausa = Image::FromFile("Imagenes\\Interfaces\\Pausa.png");
		Imagenes::YouWin = Image::FromFile("Imagenes\\Interfaces\\YouWin.png");
		Imagenes::Congratulations = Image::FromFile("Imagenes\\Interfaces\\Congratulations.png");
		Imagenes::GameOver = Image::FromFile("Imagenes\\Interfaces\\GameOver.png");
		Imagenes::Creditos = Image::FromFile("Imagenes\\Interfaces\\Creditos.png");
		//Antiguas interfaces
		Imagenes::oldRanking = Image::FromFile("Imagenes\\Interfaces\\oldRanking.jpg");
		Imagenes::oldInstrucciones = Image::FromFile("Imagenes\\Interfaces\\oldInstrucciones.png");

	}

}