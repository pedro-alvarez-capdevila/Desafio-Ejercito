#ifndef _EJERCITO_H_
#define _EJERCITO_H_

#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <list>
#include <tuple>

#include "piquero.h"
#include "arquero.h"
#include "caballero.h"


using namespace std;
typedef int nivelDeFuerza;
typedef int cantidad;

class Ejercito {
	public:
		friend class juego;
		Ejercito(string civilizacion);
		~Ejercito();

		// entrenara la unidad indicada por "unidad", y que tenga el nivel de fuerza indicado por "fuerza".
		// si la unidad no está bien escrita o no hay una unidad con esa fuerza,  no hará nada.
		//unidades: "piquero", "arquero", "caballero"
		void entrenar(string unidad, int fuerza); 

		// considero que cuando transformas a una unidad, esta pasara a tener el valor de fuerza inicial.
		// por lo que cuando transformas a una unidad, se transformará a la que tenga menor nivel de fuerza ya que es lo mas conveniente.
		void transformar(string unidad);


		void getPiqueros();
		void getArqueros();
		void getCaballeros();

		int getPuntosTotales();
		int getMonedas();
		string getCivilizacion();


		// estas deberian ser funciones privadas, pero no logré hacer que cuando le pongo friend, me deje usarlas en juego.
		void actualizarHistorial(string ejercitoEnemigo);
		void aumentar100MonedasPorGanar();
		void borrarUnidadesMasFuertes(int cantidad);

	private:
		int _monedas;
		int _puntosTotales; // decido guardar los puntos totales por una cuestion de eficiencia:
												//	es sencillo actualizarlo y me evito recorrer las 3 listas cada vez que quiero obtener los puntos totales.
		list<Piquero> _piqueros;
		list<Arquero> _arqueros;
		list<Caballero> _caballeros;
		string _civilizacion;
		list<string> _historial; // cada string será el ejercito enemigo contra el que batalló.
		// funciones privadas:
		void asignarUnidades(string unidad, int cantidad);
		
};

#endif