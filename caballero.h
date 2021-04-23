#ifndef _CABALLERO_H_
#define _CABALLERO_H_

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Caballero {
	public:
		Caballero();
		~Caballero();
		void entrenar();

		int getFuerza();


	private:
		int _fuerza;
};

#endif