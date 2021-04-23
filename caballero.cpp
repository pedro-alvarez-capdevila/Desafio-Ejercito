#include "caballero.h"

Caballero::Caballero() {
	this->_fuerza = 20;
}

void Caballero::entrenar() {
	this->_fuerza += 10;
}

int Caballero::getFuerza(){
	return this->_fuerza;
}