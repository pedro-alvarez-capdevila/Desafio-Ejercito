#ifndef _ARQUERO_H_
#define _ARQUERO_H_

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Arquero {
	public:
		Arquero();
		~Arquero();
		void entrenar();

		int getFuerza();


	private:
		int _fuerza;
};

#endif