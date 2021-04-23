#include "ejercito.h"

using namespace std;

Ejercito::Ejercito(string civilizacion){
	// doy la posibilidad de que pongan la civilización en mayuscula como en minuscula.
	if(civilizacion == "chinos" || civilizacion == "Chinos"){
		//agrego piqueros a la lista.
		asignarUnidades("piquero", 2);
		asignarUnidades("arquero", 25);
		asignarUnidades("caballero", 2);

		
		this->_monedas = 1000;
		this->_civilizacion = "Chinos";
		this->_puntosTotales = 2*5 + 25*10 + 2*20;
	} else if(civilizacion == "ingleses" || civilizacion == "Ingleses"){
		asignarUnidades("piquero", 10);
		asignarUnidades("arquero", 10);
		asignarUnidades("caballero", 10);
		
		this->_monedas = 1000;
		this->_civilizacion = "Ingleses";
		this->_puntosTotales = 10*5 + 10*10 + 10*20;
	} else{
		// para evitar problemas, asumo que si pone mal la civilización, seran bizantinos
		asignarUnidades("piquero", 5);
		asignarUnidades("arquero", 8);
		asignarUnidades("caballero", 15);
		
		this->_monedas = 1000;
		this->_civilizacion = "Bizantinos";
		this->_puntosTotales = 5*5 + 8*10 + 15*20;
	}
}

Ejercito::~Ejercito(){

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
				this->_monedas -= 10;
				this->_puntosTotales += 3;
			}
			break;
		}
	} else if(unidad == "Arquero" || unidad == "arquero"){
		for (auto elem : this->_arqueros)
		{
			if(elem.getFuerza() == fuerza){
				elem.entrenar();
				this->_monedas -= 20;
				this->_puntosTotales += 7;
			}
			break;
		}
	} else if(unidad == "Caballero" || unidad == "caballero"){
		for (auto elem : this->_caballeros)
		{
			if(elem.getFuerza() == fuerza){
				elem.entrenar();
				this->_monedas -= 30;
				this->_puntosTotales += 10;
			}
			break;
		}
	}
	
}

void Ejercito::transformar(string unidad){
	if(unidad == "Piquero" || unidad == "piquero"){
		// busco el de menor fuerza
		list<Piquero> piqueros = this->_piqueros;
		std::list<Piquero>::iterator iter = piqueros.begin();	
		tuple<int, std::list<Piquero>::iterator> min = make_tuple(0, iter);
		while (iter != piqueros.end())
		{

			if(get<0>(min) > (*iter).getFuerza()){
				get<0>(min) = (*iter).getFuerza();
				get<1>(min) = iter;
			}
			iter++;
		}
		// elimino el minimo
		// en minimo me guarde un iterador al minimo, por lo que puedo borrarlo directamente.
		if(get<0>(min) != 0){ // si es igual a 0, implica que piqueros no tiene elementos
			piqueros.erase(get<1>(min));
			// ahora solo queda agregar un arquero a this->_arqueros
			asignarUnidades("arquero", 1);
		}

		
		
	} else if(unidad == "Arquero" || unidad == "arquero"){
		// busco el de menor fuerza
		list<Arquero> arqueros = this->_arqueros;
		std::list<Arquero>::iterator iter = arqueros.begin();	
		tuple<int, std::list<Arquero>::iterator> min = make_tuple(0, iter);
		while (iter != arqueros.end())
		{

			if(get<0>(min) > (*iter).getFuerza()){
				get<0>(min) = (*iter).getFuerza();
				get<1>(min) = iter;
			}
			iter++;
		}
		// elimino el minimo
		// en min me guarde un iterador al minimo, por lo que puedo borrarlo directamente.
		if(get<0>(min) != 0){ // si es igual a 0, implica que arqueros no tiene elementos
			arqueros.erase(get<1>(min));
			// ahora solo queda agregar un arquero a this->_arqueros
			asignarUnidades("caballero", 1);
		}
	} // si no es arquero o piquero, no hace nada.
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



list<tuple<cantidad, nivelDeFuerza>> Ejercito::getCaballeros(){
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



int Ejercito::getPuntosTotales(){
	return this->_puntosTotales;
}

void Ejercito::actualizarHistorial(string ejercitoEnemigo){
	this->_historial.push_back(ejercitoEnemigo);
}

string Ejercito::getCivilizacion(){
	return this->_civilizacion;
}
void Ejercito::aumentar100MonedasPorGanar(){
	this->_monedas +=100;
}

void Ejercito::borrarUnidadesMasFuertes(int cantidad){
	for (int i = 0; i < cantidad; i++) // elimino al mas fuerte la cantidad de veces indicada por "cantidad"
	{
		// primero busco en todas las unidades de las 3 listas (piqueros, arqueros y caballeros) cual es el mas fuerte.
		// busco el de mayor fuerza en piqueros
		list<Piquero> piqueros = this->_piqueros;
		std::list<Piquero>::iterator iterPiqueros = piqueros.begin();	
		tuple<int, std::list<Piquero>::iterator> maxPiqueros = make_tuple(0, iterPiqueros);
		while (iterPiqueros != piqueros.end())
		{

			if(get<0>(maxPiqueros) < (*iterPiqueros).getFuerza()){
				get<0>(maxPiqueros) = (*iterPiqueros).getFuerza();
				get<1>(maxPiqueros) = iterPiqueros;
			}
			iterPiqueros++;
		}


		// busco el de mayor fuerza en arqueros
		list<Arquero> arqueros = this->_arqueros;
		std::list<Arquero>::iterator iterArqueros = arqueros.begin();	
		tuple<int, std::list<Arquero>::iterator> maxArqueros = make_tuple(0, iterArqueros);
		while (iterArqueros != arqueros.end())
		{

			if(get<0>(maxArqueros) < (*iterArqueros).getFuerza()){
				get<0>(maxArqueros) = (*iterArqueros).getFuerza();
				get<1>(maxArqueros) = iterArqueros;
			}
			iterArqueros++;
		}

		// busco el de mayor fuerza en arqueros
		list<Caballero> caballeros = this->_caballeros;
		std::list<Caballero>::iterator iterCaballeros = caballeros.begin();	
		tuple<int, std::list<Caballero>::iterator> maxCaballeros = make_tuple(0, iterCaballeros);
		while (iterCaballeros != caballeros.end())
		{

			if(get<0>(maxCaballeros) < (*iterCaballeros).getFuerza()){
				get<0>(maxCaballeros) = (*iterCaballeros).getFuerza();
				get<1>(maxCaballeros) = iterCaballeros;
			}
			iterCaballeros++;
		}

		// veo max(maxPiqueros, maxArqueros y maxCaballeros) y elimino el maximo.

		if(get<0>(maxCaballeros) >= get<0>(maxArqueros) && get<0>(maxCaballeros) >= get<0>(maxPiqueros)){
			// el maximo es de caballeros, asi que lo elimino.
			caballeros.erase(get<1>(maxCaballeros));
		} else if(get<0>(maxArqueros) >= get<0>(maxPiqueros)){ // el mayor es de arquero o piquero.
			// el maximo es de arqueros, asi que lo elimino.
			arqueros.erase(get<1>(maxArqueros));
		} else{
			// el maximo es de piqueros, asi que lo elimino.
			piqueros.erase(get<1>(maxPiqueros));
		}
	}
	
}