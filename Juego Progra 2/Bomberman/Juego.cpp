#include "WinForm.h"

namespace Bomberman
{
	Juego::Juego()
	{
		onTimerTick = gcnew EventHandler(this, &Juego::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &Juego::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &Juego::teclaUp);
		onMouseClick = gcnew MouseEventHandler(this, &Juego::mouseClick);

		cheatKey = 'z';

		Winform::upecino = gcnew Upecino(gcnew Posicion(0, 0), "Diego");
		Winform::bombas = gcnew ArrBombas();		
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
			if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up)
			{
				Winform::upecino->moviendose = true;
				Winform::upecino->direccion = Arriba;
			}
			else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down)
			{
				Winform::upecino->moviendose = true;
				Winform::upecino->direccion = Abajo;
			}
			else if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left)
			{
				Winform::upecino->moviendose = true;
				Winform::upecino->direccion = Izquierda;
			}
			else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right)
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
				ActivarEscena(Winform::pausa);
			}
			else if (e->KeyCode == Keys::N)
			{
				cheatKey = 'n';
			}
			else if (e->KeyCode == Keys::B)
			{
				cheatKey = 'b';
			}
			else if (e->KeyCode == Keys::T)
			{
				cheatKey = 't';
			}
			else if (e->KeyCode == Keys::C)
			{
				Winform::upecino->estado = Celebrando;
				Winform::upecino->indiceSprite = -1;
			}
			else if (e->KeyCode == Keys::D1)
			{
				if (cheatKey == 'n')
				{
					Nivel::PasarANivel(1);
				}
			}
			else if (e->KeyCode == Keys::D2)
			{
				if (cheatKey == 'n')
				{
					Nivel::PasarANivel(2);
				}
			}
			else if (e->KeyCode == Keys::D3)
			{
				if (cheatKey == 'n')
				{
					Nivel::PasarANivel(3);
				}
			}
			else if (e->KeyCode == Keys::D4)
			{
				if (cheatKey == 'n')
				{
					Nivel::PasarANivel(4);
				}
			}
			else if (e->KeyCode == Keys::D5)
			{
				if (cheatKey == 'n')
				{
					Nivel::PasarANivel(5);
				}
			}
			else if (e->KeyCode == Keys::P)
			{
				DesactivarEscena(this);
				ActivarEscena(Winform::pausa);
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
		if (e->KeyCode == Keys::N && cheatKey == 'n')
			cheatKey = 'z';
		else if (e->KeyCode == Keys::B && cheatKey == 'b')
			cheatKey = 'z';
		else if (e->KeyCode == Keys::T && cheatKey == 't')
			cheatKey = 'z';
	}

	void Juego::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (cheatKey == 'b')
			Winform::bombas->AgregarBomba(gcnew Bomba(gcnew Posicion(e->X - 32, e->Y - 32)));
		else if (cheatKey == 't')
			Winform::upecino->posicion->Igualar(e->X - 32, e->Y - 32, 64);
	}


	void Juego::GanarJuego()
	{
		Escena::DesactivarEscena(Winform::juego);
		Escena::ActivarEscena(Winform::congratulations);
	}

	void Juego::PerderJuego()
	{
		Escena::DesactivarEscena(Winform::juego);
		Escena::ActivarEscena(Winform::gameOver);
	}
}

