#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Bomberman
{
	public enum Estados { Idle, Inmortal, Fantasma, Muriendo, Celebrando };
	public enum Direcciones { Arriba, Abajo, Izquierda, Derecha };
	public enum Malignos { Easy, Normal, Insane };
	public enum Objetos {oPiso, oBloque, oBomba, oCaja, oItem};
	public enum Items { Cura, Powerade };

	public ref class Posicion
	{
	public:
		int x;
		int y;
		Posicion(int pX, int pY);
		Posicion(int pX, int pY, int multiplo);
		bool EsIgualA(Posicion^ p);
		void Igualar(Posicion^ p);                                                                                                                                                                                                                                                                                                                                                                        
		void Aumentar(Direcciones direccion, int velocidad);
		Posicion^ getIncrementada(Direcciones direccion, int velocidad);
	};

	public ref class Figura
	{
	public:
		Image^ imagen;
		Posicion^ posicion;
		int alto;
		int ancho;
		int indiceSprite;
		int subIndice;
		Figura();
	};

	public ref class Vivo : public Figura
	{
	public:
		int vida;
		int tiempoInmortal;
		Estados estado;
		Direcciones direccion;
		int velocidad;
	};

	public ref class Upecino : Vivo
	{
	public:
		static String^ nombre;
		static int radioExplosion;
		static bool moviendose;
		Upecino(Posicion^ p, String^ pNombre);
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void CuandoMuere();
		void Avanzar(Direcciones direccion);
		void Detener();
	};

	public ref class Maligno : public Vivo
	{
	public:
		Malignos tipo;
	};

	public ref class Maligno1 : public Maligno
	{
	public:
		Maligno1(Posicion^ p, Malignos pTipo, int pVida);
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void CuandoMuere();
		void Avanzar();
	};

	public ref class Maligno2 : public Maligno
	{
	public:
		Maligno2(Posicion^ p, Malignos pTipo, int pVida);
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void CuandoMuere();
		void Avanzar();
	};

	public ref class Maligno3 : public Maligno
	{
	public:
		Maligno3(Posicion^ p, Malignos pTipo, int pVida);
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void CuandoMuere();
		void Avanzar();
	};

	public ref class Objeto : public Figura
	{
	public:
		Objetos tipo;
	};

	public ref class Piso : public Objeto
	{
	public:
		Piso(Posicion^ p);
		void MostrarSprite(Graphics^ graphics);
	};

	public ref class Caja : public Objeto
	{
	public:
		Caja(Posicion^ p);
		void cuandoBombaLeCae();
		void MostrarSprite(Graphics^ graphics);
	};

	public ref class Bloque : public Objeto
	{
	public:
		Bloque(Posicion^ p);
		void MostrarSprite(Graphics^ graphics);
	};

	public ref class Item : public Objeto
	{
	public:
		Items tipoItem;
		Item(Posicion^ p, Items pTipo);
		void MostrarSprite(Graphics^ graphics);
	};

	public ref class Bomba : public Objeto
	{
	public:
		int tiempo;
		bool visible;
		int radioExplosion;
		Bomba(Posicion^ p);
		void golpearUpecino();
		void Explotar(Graphics^ graphics);
		void MostrarSprite(Graphics^ graphics);
	};

	public ref class MatrizObjetos
	{
	public:
		array<Objeto^, 2>^ matriz;
	};

	public ref class ArrBombas
	{
	public:
		array<Bomba^>^ arreglo;
		int cantidad;
		ArrBombas();
		static array<Bomba^>^ CrearArreglo(int size);
		Bomba^ getBomba(int x, int y);
		void AgregarBomba(Bomba^ bomba);
		void MostrarBombas(Graphics^ graphics);
		void CorrerBombas();
		void LimpiarArreglo();
	};

	public ref class ArrMalignos
	{
	public:
		array<Maligno^>^ arreglo;
		ArrMalignos(int size);
		int cantidad;
		void EliminarMaligno(Maligno^ maligno);
		void MostrarMalignos(Graphics^ graphics);
	};

	public ref class Nivel
	{
	public:
		MatrizObjetos^ matrizObjetos;
		ArrMalignos^ arregloMalignos;
		static void MostrarNivel(Graphics^ graphics);
		static Objeto^ getObjetoColisionante(Direcciones direccion, int velocidad);
		static Objeto^ getContenidoCaja(Posicion^ p);
		static Objeto^ getObjeto(Posicion^ posicion);
	};

	public ref class Nivel1 : public Nivel{public: Nivel1();};
	public ref class Nivel2 : public Nivel{public: Nivel2();};
	public ref class Nivel3 : public Nivel{public: Nivel3();};
	public ref class Nivel4 : public Nivel{public: Nivel4();};
	public ref class Nivel5 : public Nivel{public: Nivel5();};

	public ref class Escena
	{
	public:
		BufferedGraphics^ buffer;
		int contador;
		bool activo;
		bool dibujado;
		Escena();
		KeyEventHandler^ onKeyDown;
		KeyEventHandler^ onKeyUp;
		EventHandler^ onTimerTick;
		static void ActivarEscena(Escena^ escena);
		static void DesactivarEscena(Escena^ escena);
	};

	public ref class Introduccion : public Escena
	{ 
	public:
		Introduccion();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Inicio : public Escena
	{
	public:
		Inicio();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class InGame : public Escena
	{
	public:
		InGame();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		void teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

}