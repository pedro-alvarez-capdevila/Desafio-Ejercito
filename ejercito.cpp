#include "ejercito.h"

using namespace std;

Ejercito::Ejercito(string civilizacion){
	// doy la posibilidad de que pongan la civilización en mayuscula como en minuscula.
	if(civilizacion == "chinos" || civilizacion == "Chinos"){
		//agrego piqueros a la lista.
		asignarUnidades("piquero", 2);
		asignarUnidades("arquero", 25);
		asignarUnidades("caballero", 2);

		this->_historial;
		this->_monedas = 1000;
		this->_civilizacion = "Chinos";
	} else if(civilizacion == "ingleses" || civilizacion == "Ingleses"){
		asignarUnidades("piquero", 10);
		asignarUnidades("arquero", 10);
		asignarUnidades("caballero", 10);
		this->_historial;
		this->_monedas = 1000;
		this->_civilizacion = "Ingleses";
	} else{
		// para evitar problemas, asumo que si pone mal la civilización, seran bizantinos
		asignarUnidades("piquero", 5);
		asignarUnidades("arquero", 8);
		asignarUnidades("caballero", 15);
		this->_historial;
		this->_monedas = 1000;
		this->_civilizacion = "Bizantinos";
	}
}

void Ejercito::asignarUnidades(string unidad, int cantidad){
		if(unidad == "piquero"){
			for (int i = 0; i < cantidad; i++)
			{
				Piquero piquero;
				this->_piqueros.push_back(piquero);
			}	
		} else if(unidad == "arquero"){
			for (int i = 0; i < cantidad; i++)
			{
				Arquero arquero;
				this->_arqueros.push_back(arquero);
			}
		} else {
			for (int i = 0; i < cantidad; i++)
			{
				Caballero caballero;
				this->_caballeros.push_back(caballero);
			}
		}
}


void Ejercito::entrenar(string unidad, int fuerza){
	if(unidad == "Piquero" || unidad == "piquero"){
		for (auto elem : this->_piqueros)
		{
			if(elem.getFuerza() == fuerza){
				elem.entrenar();
			}
		}
	} else if(unidad == "Arquero" || unidad == "arquero"){
		for (auto elem : this->_arqueros)
		{
			if(elem.getFuerza() == fuerza){
				elem.entrenar();
			}
		}
	} else if(unidad == "Caballero" || unidad == "caballero"){
		for (auto elem : this->_caballeros)
		{
			if(elem.getFuerza() == fuerza){
				elem.entrenar();
				this->_caballeros
			}
		}
	}
	
}

void transformar(string unidad){

}


// función para getArquero,piquero y caballero.
bool perteneceAListaDeInt(list<int> list, int a){
	
	for(auto elem : list){
		if(elem == a){
			return true;
		}
	}
	return false;

	
}

list<tuple<cantidad, nivelDeFuerza>> Ejercito::getPiqueros(){
	// primero guardo en una lista la cantidad de fuerzas distintas que hay.
	list<int> fuerzas;
	list<Piquero> listaPiqueros = this->_piqueros;
	int max = 0;

	for(auto piquero : listaPiqueros){
		if(!perteneceAListaDeInt(fuerzas, piquero.getFuerza())){ // si no pertence, lo agrego a fuerzas.
			fuerzas.push_back(piquero.getFuerza());
		}
		if(max < piquero.getFuerza()){ // obtengo el piquero que tiene la mayor fuerza.
			max = piquero.getFuerza();
		}
	}

	// ahora en "fuerzas" tengo los distintas fuerzas que hay y 
	int contadorDeUnidadadesPorFuerza[max];

	for(auto piquero : listaPiqueros){
		contadorDeUnidadadesPorFuerza[piquero.getFuerza()]++;
	}

	// creo la salida
	list<tuple<cantidad, nivelDeFuerza>> rta;
	for(auto fuerza : fuerzas){
		tuple<cantidad, nivelDeFuerza> elem = make_tuple(contadorDeUnidadadesPorFuerza[fuerza], fuerza);
		cout << "fuerza: " << fuerza << "  cantidad de unidades: " << contadorDeUnidadadesPorFuerza[fuerza] << '\n';
		rta.push_back(elem);
	}

	return rta;

	
}



list<tuple<cantidad, nivelDeFuerza>> Ejercito::getArqueros(){
	// primero guardo en una lista la cantidad de fuerzas distintas que hay.
	list<int> fuerzas;
	list<Arquero> listaArqueros = this->_arqueros;
	int max = 0;

	for(auto arquero : listaArqueros){
		if(!perteneceAListaDeInt(fuerzas, arquero.getFuerza())){ // si no pertence, lo agrego a fuerzas.
			fuerzas.push_back(arquero.getFuerza());
		}
		if(max < arquero.getFuerza()){ // obtengo el arquero que tiene la mayor fuerza.
			max = arquero.getFuerza();
		}
	}

	// ahora en "fuerzas" tengo los distintas fuerzas que hay y 
	int contadorDeUnidadadesPorFuerza[max];

	for(auto arquero : listaArqueros){
		contadorDeUnidadadesPorFuerza[arquero.getFuerza()]++;
	}

	// creo la salida
	list<tuple<cantidad, nivelDeFuerza>> rta;
	for(auto fuerza : fuerzas){
		tuple<cantidad, nivelDeFuerza> elem = make_tuple(contadorDeUnidadadesPorFuerza[fuerza], fuerza);
		cout << "fuerza: " << fuerza << "  cantidad de unidades: " << contadorDeUnidadadesPorFuerza[fuerza] << '\n';
		rta.push_back(elem);
	}

	return rta;

}

list<tuple<cantidad, nivelDeFuerza>> Ejercito::getArqueros(){
	// primero guardo en una lista la cantidad de fuerzas distintas que hay.
	list<int> fuerzas;
	list<Caballero> listaCaballeros = this->_caballeros;
	int max = 0;

	for(auto caballero : listaCaballeros){
		if(!perteneceAListaDeInt(fuerzas, caballero.getFuerza())){ // si no pertence, lo agrego a fuerzas.
			fuerzas.push_back(caballero.getFuerza());
		}
		if(max < caballero.getFuerza()){ // obtengo el caballero que tiene la mayor fuerza.
			max = caballero.getFuerza();
		}
	}

	// ahora en "fuerzas" tengo los distintas fuerzas que hay y 
	int contadorDeUnidadadesPorFuerza[max]; // aca voy a tener en la posicion 7 por ejemplo, la cantidad de unidades con fuerza 7.

	for(auto caballero : listaCaballeros){
		contadorDeUnidadadesPorFuerza[caballero.getFuerza()]++;
	}

	// creo la salida
	list<tuple<cantidad, nivelDeFuerza>> rta;
	for(auto fuerza : fuerzas){
		tuple<cantidad, nivelDeFuerza> elem = make_tuple(contadorDeUnidadadesPorFuerza[fuerza], fuerza);
		cout << "fuerza: " << fuerza << "  cantidad de unidades: " << contadorDeUnidadadesPorFuerza[fuerza] << '\n';
		rta.push_back(elem);
	}

	return rta;

}




