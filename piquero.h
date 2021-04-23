#ifndef _PIQUERO_H_
#define _PIQUERO_H_

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Piquero {
	public:
		Piquero();
		~Piquero();
		void entrenar();

		int getFuerza();


	private:
		int _fuerza;
};

#endif