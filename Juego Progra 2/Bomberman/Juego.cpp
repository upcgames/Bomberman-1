#include "Directorio.h"

namespace Bomberman
{
	Juego::Juego()
	{
		onTimerTick = gcnew EventHandler(this, &Juego::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Juego::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &Juego::teclaUp);

		Winform::upecino = gcnew Upecino(gcnew Posicion(0, 0), "Diego");
		Winform::nivel1 = gcnew Nivel1();
		Winform::objetos = Winform::nivel1->matrizObjetos;
		Winform::bombas = gcnew ArrBombas();
		Winform::malignos = Winform::nivel1->arregloMalignos;
	}

	void Juego::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (activo)
		{
			Winform::winform->Text = Winform::upecino->vida.ToString();

			Nivel::MostrarNivel(buffer->Graphics);
			Winform::bombas->MostrarBombas(buffer->Graphics);
			Winform::upecino->MostrarUpecino(buffer->Graphics);
			Winform::malignos->MostrarMalignos(buffer->Graphics);
			buffer->Render(Winform::graphics);
			dibujado = true;
		}
	}
	
	void Juego::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (activo && dibujado)
		{
			if (e->KeyCode == Keys::W)
			{
				Winform::upecino->moviendose = true;
				Winform::upecino->direccion = Arriba;
			}
			else if (e->KeyCode == Keys::S)
			{
				Winform::upecino->moviendose = true;
				Winform::upecino->direccion = Abajo;
			}
			else if (e->KeyCode == Keys::A)
			{
				Winform::upecino->moviendose = true;
				Winform::upecino->direccion = Izquierda;
			}
			else if (e->KeyCode == Keys::D)
			{
				Winform::upecino->moviendose = true;
				Winform::upecino->direccion = Derecha;
			}
			else if (e->KeyCode == Keys::Space)
			{
				Winform::bombas->AgregarBomba(gcnew Bomba(Winform::upecino->posicion));
			}
			else if (e->KeyCode == Keys::Enter)
			{
				DesactivarEscena(this);
				ActivarEscena(Winform::inicio);
			}
		}
	}

	void Juego::teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::W && Winform::upecino->direccion == Arriba)
			Winform::upecino->Detener();
		else if (e->KeyCode == Keys::S && Winform::upecino->direccion == Abajo)
			Winform::upecino->Detener();
		else if (e->KeyCode == Keys::A && Winform::upecino->direccion == Izquierda)
			Winform::upecino->Detener();
		else if (e->KeyCode == Keys::D && Winform::upecino->direccion == Derecha)
			Winform::upecino->Detener();
	}
}