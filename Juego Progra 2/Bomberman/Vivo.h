#pragma once
#include "Directorio.h"

namespace Bomberman
{
ref class Vivo : public Figura
{
public:
	int vida;
	int tiempoInmortal;
	Action^ EsAtacado;
	Estados estado;
	Direcciones direccion;
	int velocidad;
};

}