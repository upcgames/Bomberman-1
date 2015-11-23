#include "Directorio.h"

namespace Bomberman
{
	Maligno1::Maligno1(Posicion^ p, int pVida)
	{
		imagen = Image::FromFile("Maligno1.png");
		
		sentidoDeGiro = (Winform::aleatorio->Next(2)) == 0? true: false;
		EsAtacado += gcnew Action(this, &Maligno1::Muere);
		posicion = p;
		tipo = m1;
		vida = 0;
		contador = sentidoDeGiro? -1 : 1;
		indiceSprite = 0;
		ancho = 64;
		alto = 64;
		direccion = Abajo;
		visible = true;
		estado = Idle;
		velocidad = pVida;
	}
	void Maligno1::MostrarSprite(Graphics^ graphics)
	{
		if (direccion == Arriba)
			subIndice = 0;
		else if (direccion == Abajo)
			subIndice = 1;
		else if (direccion == Izquierda)
			subIndice = 2;
		else if (direccion == Derecha)
			subIndice = 3;

		if (estado == Idle)
			Avanzar();

		else if (estado == Muriendo)
		{
			indiceSprite++;
			subIndice = 5;

			if (indiceSprite == 8)//Termina animacion de muerte
			{
				visible = false;
				Winform::malignos->malignosRestantes--;

				if (Winform::malignos->malignosRestantes == 0)
					MessageBox::Show("Ganaste el Nivel");
				return;
			}
		}
		else if (estado == Inmortal)
		{
			tiempoInmortal -= 1;

			if (tiempoInmortal == 0)
				estado = Idle;
		}

		graphics->DrawImage(imagen, Rectangle(posicion->x, posicion->y, ancho, alto), Rectangle(indiceSprite * 24, subIndice * 24, 23, 23), GraphicsUnit::Pixel);
		if (estado == Inmortal)
			graphics->DrawString("III", gcnew Font("Arial", 16, FontStyle::Bold), gcnew SolidBrush(Color::White), Point(posicion->x + 20, posicion->y + 32));
	}
	void Maligno1::CuandoBombaLeCae(int damageBomba)
	{

	}
	void Maligno1::Muere()
	{
		estado = Muriendo;
		indiceSprite = -1;
	}
	void Maligno1::Avanzar()
	{
		if (sentidoDeGiro)
			contador++;
		else
			contador--;

		indiceSprite = Math::Abs(contador % 8);
		
		if (sentidoDeGiro)
		{
			if (contador == 0)
				direccion = Abajo;
			else if (contador == 8)
				direccion = Izquierda;
			else if (contador == 16)
				direccion = Arriba;
			else if (contador == 24)
				direccion = Derecha;
			else if (contador == 36)
			{
				direccion = Abajo;
				contador = 0;
			}
		}
		else
		{
			if (contador == 0)
				direccion = Abajo;
			else if (contador == -8)
				direccion = Derecha;
			else if (contador == -16)
				direccion = Arriba;
			else if (contador == -24)
				direccion = Izquierda;
			else if (contador == -36)
			{
				direccion = Abajo;
				contador = 0;
			}
		}

	}
}