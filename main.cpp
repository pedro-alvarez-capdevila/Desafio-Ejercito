#include "juego.h"

using namespace std;

int main(int argc, char const *argv[])
{
	juego juego1();
	Ejercito ejercito1("chinos");
	Ejercito ejercito2("Ingleses");
	Ejercito ejercito3("Bizantinos");

	int puntosEjercito1 = ejercito1.getPuntosTotales();
	int puntosEjercito2 = ejercito2.getPuntosTotales();
	int puntosEjercito3 = ejercito3.getPuntosTotales();

	cout << "puntos ejercito1:" << puntosEjercito1 << '\n';
	cout << "puntos ejercito2:" << puntosEjercito2 << '\n';
	cout << "puntos ejercito3:" << puntosEjercito3 << '\n';

	return 0;
}
