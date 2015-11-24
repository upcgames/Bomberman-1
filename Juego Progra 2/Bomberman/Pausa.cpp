#include "WinForm.h"

namespace Bomberman
{
	Pausa::Pausa()
	{
		onTimerTick = gcnew EventHandler(this, &Pausa::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Pausa::teclaDown);
		opcion = "Continuar";
	}

	void Pausa::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			buffer->Graphics->DrawImage(Imagenes::Pausa, Rectangle(0, 0, 832, 577));
			buffer->Render(Winform::graphics);
			dibujado = true;
		}
	}

	void Pausa::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				if (opcion == "Continuar")
				{
					DesactivarEscena(this);
					ActivarEscena(Winform::juego);
				}
				else if (opcion == "Reiniciar")
				{
					opcion = "Continuar";
					DesactivarEscena(this);
					ActivarEscena(Winform::juego);
					Nivel::PasarANivel(Winform::juego->nivel);
				}
				else if (opcion == "Instrucciones")
				{
					DesactivarEscena(this);
					ActivarEscena(Winform::instrucciones);
				}
				else if (opcion == "Salir")
				{
					opcion = "Continuar";
					DesactivarEscena(this);
					ActivarEscena(Winform::inicio);
				}
				else if (opcion == "Bomberman")
				{
					Winform::upecino->imagen = Imagenes::BombermanSprite;
					DesactivarEscena(this);
					ActivarEscena(Winform::juego);
				}
				else if (opcion == "Bomberdog")
				{
					Winform::upecino->imagen = Imagenes::BomberdogSprite;
					DesactivarEscena(this);
					ActivarEscena(Winform::juego);
				}
				else if (opcion == "PirateBomberman")
				{

				}
			}
			else if (e->KeyCode == Keys::Up)
			{
				if (opcion == "Reiniciar")
				{
					opcion = "Continuar";
				}
				else if (opcion == "Instrucciones")
				{
					opcion = "Reiniciar";
				}
				else if (opcion == "Salir")
				{
					opcion = "Instrucciones";
				}
				else if (opcion == "Bomberman" || opcion == "Bomberdog" || opcion == "PirateBomberman")
				{
					opcion = "Salir";
				}
			}
			else if (e->KeyCode == Keys::Down)
			{
				if (opcion == "Continuar")
				{
					opcion = "Reiniciar";
				}
				else if (opcion == "Reiniciar")
				{
					opcion = "Instrucciones";
				}
				else if (opcion == "Instrucciones")
				{
					opcion = "Salir";
				}
				else if (opcion == "Salir")
				{
					opcion = "Bomberdog";
				}
			}
			else if (e->KeyCode == Keys::Left)
			{
				if (opcion == "Bomberdog")
				{
					opcion = "Bomberman";
				}
				else if (opcion == "PirateBomberman")
				{
					opcion = "Bomberdog";
				}
			}
			else if (e->KeyCode == Keys::Right)
			{
				if (opcion == "Bomberman")
				{
					opcion = "Bomberdog";
				}
				else if (opcion == "Bomberdog")
				{
					opcion = "PirateBomberman";
				}
			}
		}
	}
}