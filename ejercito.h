#ifndef _EJERCITO_H_
#define _EJERCITO_H_

#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <list>
#include "piquero.h"
#include "tuple"


#include "arquero.h"
#include "caballero.h"

using namespace std;
typedef int nivelDeFuerza;
typedef int cantidad;

class Ejercito {
	public:
		Ejercito(string civilizacion);

		// entrenara la unidad indicada por "unidad", y que tenga el nivel de fuerza indicado por "fuerza".
		// si la unidad no está bien escrita (se acepta que empiece tanto con como sin mayuscula) o no hay una unidad con esa fuerza, no hará nada.
		void entrenar(string unidad, int fuerza); 

		// considero que cuando transformas a una unidad, esta pasara a tener el valor de fuerza inicial.
		// por lo que cuando transformas a una unidad, se transformará a la que tenga menor nivel de fuerza ya que es lo mas conveniente.
		void transformar(string unidad);

		list<tuple<cantidad, nivelDeFuerza>> getPiqueros();
		list<tuple<cantidad, nivelDeFuerza>> getArqueros();
		list<tuple<cantidad, nivelDeFuerza>> getCaballeros();


	private:
		int _monedas;
		list<Piquero> _piqueros;
		list<Arquero> _arqueros;
		list<Caballero> _caballeros;
		string _civilizacion;
		list<string> _historial; 
		// funciones privadas:
		void asignarUnidades(string unidad, int cantidad);
};

#endif