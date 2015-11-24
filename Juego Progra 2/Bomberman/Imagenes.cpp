#include "WinForm.h"

namespace Bomberman
{
	Imagenes::Imagenes()
	{
		Imagenes::spriteBomberman = Image::FromFile("Bomberman.png");
		Imagenes::spriteBomberdog = Image::FromFile("Bomberdog.png");
		Imagenes::spriteNinjaBomberman = Image::FromFile("NinjaBomberman.png");
		Imagenes::spriteBomba = Image::FromFile("Bombas.png");
	}

}