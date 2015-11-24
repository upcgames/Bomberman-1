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
				buffer->Graphics->Clear(Color::SlateBlue);
				buffer->Graphics->DrawString(opcion, gcnew Font("Arial", 16), gcnew SolidBrush(Color::White), Point(350, 300));
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
			else if (e->KeyCode == Keys::Up)
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
			else if (e->KeyCode == Keys::Down)
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