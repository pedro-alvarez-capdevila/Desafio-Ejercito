#include "piquero.h"

Piquero::Piquero(){
	this->_fuerza = 5;
}

void Piquero::entrenar() {
	this->_fuerza += 3;
}

int Piquero::getFuerza(){
	return this->_fuerza;
}
		
Piquero::~Piquero(){
	
}