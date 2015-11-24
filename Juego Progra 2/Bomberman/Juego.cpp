#include "WinForm.h"

namespace Bomberman
{
	Juego::Juego()
	{
		onTimerTick = gcnew EventHandler(this, &Juego::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Juego::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &Juego::teclaUp);
		onMouseClick = gcnew MouseEventHandler(this, &Juego::mouseClick);

		cheatNpress = false;

		Winform::upecino = gcnew Upecino(gcnew Posicion(0, 0), "Diego");
		Winform::bombas = gcnew ArrBombas();
		PrepararNivel(1);		
	}

	void Juego::PrepararNivel(int pNivel)
	{
		if (pNivel == 1)
		{
			Winform::nivel1 = gcnew Nivel1();
			Winform::objetos = Winform::nivel1->matrizObjetos;
			Winform::malignos = Winform::nivel1->arregloMalignos;
		}
		else if (pNivel == 2)
		{
			Winform::nivel2 = gcnew Nivel2();
			Winform::objetos = Winform::nivel2->matrizObjetos;
			Winform::malignos = Winform::nivel2->arregloMalignos;
		}

		Winform::bombas->LimpiarArreglo();
		Winform::winform->upecino->indiceSprite = 0;
		Winform::winform->upecino->radioExplosion = 1;
		Winform::winform->upecino->direccion = Direcciones::Abajo;
		Winform::winform->upecino->estado = Estados::Idle;
		Winform::winform->upecino->moviendose = false;
		Winform::winform->upecino->posicion->ToZero();
		Portal::visible = false;
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
			else if (e->KeyCode == Keys::N)
			{
				cheatNpress = true;
			}
			else if (e->KeyCode == Keys::C)
			{
				if (cheatNpress)
				{
					Winform::upecino->estado = Celebrando;
					Winform::upecino->indiceSprite = -1;
				}
			}
			else if (e->KeyCode == Keys::D1)
			{
				if (cheatNpress)
				{
					PrepararNivel(1);
				}
			}
			else if (e->KeyCode == Keys::D2)
			{
				if (cheatNpress)
				{
					PrepararNivel(2);
				}
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
		if (e->KeyCode == Keys::N && cheatNpress)
			cheatNpress = false;
	}

	void Juego::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		Winform::bombas->AgregarBomba(gcnew Bomba(gcnew Posicion(e->X - 32, e->Y - 32)));
	}
}