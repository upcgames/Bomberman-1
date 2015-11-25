#include "WinForm.h"

namespace Bomberman
{
	Inicio::Inicio()
	{
		onTimerTick = gcnew EventHandler(this, &Inicio::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Inicio::teclaDown);
		opcion = "Iniciar Juego";
	}

	void Inicio::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			buffer->Graphics->DrawImage(Imagenes::Inicio, Rectangle(0, 0, 832, 577));
			
			if (opcion == "Iniciar Juego")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(256, 320, 64, 64));
			else if (opcion == "Instrucciones")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(128, 384, 64, 64));
			else if (opcion == "Creditos")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(192, 448, 64, 64));
			else if (opcion == "Salir")
				buffer->Graphics->DrawImage(Imagenes::Cursor, Rectangle(256, 512, 64, 64));
			
			buffer->Render(Winform::graphics);
			dibujado = true;
		}
	}

	void Inicio::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::Enter)
			{
				if (opcion == "Iniciar Juego")
				{
					DesactivarEscena(this);
					Winform::juego = gcnew Juego();
					ActivarEscena(Winform::juego);
					Nivel::PasarANivel(1);
				}
				else if (opcion == "Instrucciones")
				{
					DesactivarEscena(this);
					ActivarEscena(Winform::instrucciones);
				}
				else if (opcion == "Creditos")
				{
					DesactivarEscena(this);
					ActivarEscena(Winform::creditos);
				}
				else if (opcion == "Salir")
				{
					Winform::winform->Close();
				}
			}
			else if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)
			{
				if (opcion == "Instrucciones")
				{
					opcion = "Iniciar Juego";
				}
				else if (opcion == "Creditos")
				{
					opcion = "Instrucciones";
				}
				else if (opcion == "Salir")
				{
					opcion = "Creditos";
				}
			}
			else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)
			{
				if (opcion == "Iniciar Juego")
				{
					opcion = "Instrucciones";
				}
				else if (opcion == "Instrucciones")
				{
					opcion = "Creditos";
				}
				else if (opcion == "Creditos")
				{
					opcion = "Salir";
				}
			}

		}
	}
}