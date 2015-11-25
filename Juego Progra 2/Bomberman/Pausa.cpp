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

			if (opcion == "Continuar")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(128, 128, 64, 64));
			else if (opcion == "Reiniciar")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(128, 192, 64, 64));
			else if (opcion == "Instrucciones")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(54, 256, 64, 64));
			else if (opcion == "Salir")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(256, 320, 64, 64));
			else if (opcion == "Bomberman")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(0, 448, 64, 64));
			else if (opcion == "Bomberdog")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(256, 448, 64, 64));
			else if (opcion == "PirateBomberman")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(512, 448, 64, 64));

			buffer->Render(Winform::graphics);
			dibujado = true;
		}
	}

	void Pausa::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter || e->KeyCode == Keys::Space)
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
					Winform::upecino->imagen = Imagenes::PirateBombermanSprite;
					DesactivarEscena(this);
					ActivarEscena(Winform::juego);
				}
			}
			else if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)
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
			else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)
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
			else if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)
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
			else if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D)
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