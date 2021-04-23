#include "arquero.h"

Arquero::Arquero(){
	this->_fuerza = 10;
}

void Arquero::entrenar() {
	this->_fuerza += 7;
}

int Arquero::getFuerza(){
	return this->_fuerza;
}

Arquero::~Arquero(){
	
}