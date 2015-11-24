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
	public enum Malignos { m1, m2, m3, m4 };
	public enum Objetos {oPiso, oBloque, oBomba, oCaja, oItem, oPortal};
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
		void ToZero();
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
		Rectangle getBody();
		static Rectangle getBody(int xx, int yy, int pAncho, int pAlto);
	};

	public ref class Vivo : public Figura
	{
	public:
		int vida;
		int tiempoInmortal;
		Action^ EsAtacado;
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
		static void TocaElPortal();
		Upecino(Posicion^ p, String^ pNombre);
		void MostrarUpecino(Graphics^ graphics);
		void PierdeUnaVida();
		void CuandoMuere();
		void Avanzar(Direcciones direccion);
		void Detener();
	};

	public ref class Maligno : public Vivo
	{
	public:
		Malignos tipo;
		bool visible;
		static void ColisionMaligno_Fuego(int xFuego, int yFuego);
	};

	public ref class Maligno1 : public Maligno
	{
	public:
		Maligno1(Posicion^ p, int pVida);
		int contador;
		bool sentidoDeGiro;
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void Muere();
		void Avanzar();
	};

	public ref class Maligno2 : public Maligno
	{
	public:
		Maligno2(Posicion^ p, int pVida);
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void Muere();
		void Avanzar();
	};

	public ref class Maligno3 : public Maligno
	{
	public:
		Maligno3(Posicion^ p, int pVida);
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void Muere();
		void Avanzar();
	};

	public ref class Maligno4 : public Maligno
	{
	public:
		Maligno4(Posicion^ p, int pVida);
		void MostrarSprite(Graphics^ graphics);
		void CuandoBombaLeCae(int damageBomba);
		void Muere();
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
		void Explotar(Graphics^ graphics);
		void MostrarSprite(Graphics^ graphics);
	};

	public ref class Portal : public Objeto
	{
	public:
		static bool visible;
		Portal(Posicion^ p);
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
		int malignosRestantes;
		void EliminarMaligno(Maligno^ maligno);
		void MostrarMalignos(Graphics^ graphics);
	};

	public ref class Nivel
	{
	public:
		MatrizObjetos^ matrizObjetos;
		ArrMalignos^ arregloMalignos;
		void generarMatrizObjetos(Objetos matriz[9][13]);
		static void PasarANivel(int pNivel);
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
		int contador;
		bool activo;
		bool dibujado;
		BufferedGraphics^ buffer;
		KeyEventHandler^ onKeyDown;
		KeyEventHandler^ onKeyUp;
		MouseEventHandler^ onMouseClick;
		EventHandler^ onTimerTick;
		Escena();
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
		String^ opcion;
		Inicio();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Instrucciones : public Escena
	{
	public:
		Instrucciones();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Pausa : public Escena
	{
	public:
		String^ opcion;
		Pausa();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class YouWin : public Escena
	{
	public:
		YouWin();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class GameOver : public Escena
	{
	public:
		GameOver();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Congratulations : public Escena
	{
	public:
		Congratulations();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Creditos : public Escena
	{
	public:
		Creditos();
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Juego : public Escena
	{
	public:
		Juego();
		bool cheatNpress;
		int nivel;
		static void GanarJuego();
		static void PerderJuego();
		void mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		void timerTick(System::Object^  sender, System::EventArgs^  e);
		void teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
		void teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};

	public ref class Imagenes
	{
	public:
		Imagenes();
		static Image^ BombermanSprite;
		static Image^ BomberdogSprite;
		static Image^ spritePirateBomberman;

		static Image^ NinjaBombermanSprite;
		static Image^ PlunderBombermanSprite;
		static Image^ TerroinSprite;
		static Image^ CapedBombermanSprite;

		static Image^ BombasSprite;

		static Image^ Introducion;
		static Image^ Inicio;
		static Image^ Instrucciones;
		static Image^ Juego;
		static Image^ Pausa;
		static Image^ YouWin;
		static Image^ Congratulations;
		static Image^ GameOver;
		static Image^ Creditos;
		static Image^ oldRanking;
		static Image^ oldInstrucciones;

	};
}