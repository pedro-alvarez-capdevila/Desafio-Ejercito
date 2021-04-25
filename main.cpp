#include "ejercito.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Ejercito ejercito1("chinos");
	Ejercito ejercito2("Ingleses");
	Ejercito ejercito3("Bizantinos");

	int puntosEjercito1 = ejercito1.getPuntosTotales();
	int puntosEjercito2 = ejercito2.getPuntosTotales();
	int puntosEjercito3 = ejercito3.getPuntosTotales();

	string civilizacionEjercito1 = ejercito1.getCivilizacion();
	string civilizacionEjercito2 = ejercito2.getCivilizacion();
	string civilizacionEjercito3 = ejercito3.getCivilizacion();


	cout << "puntos ejercito1: " << puntosEjercito1 << "  civilizacion: "<< civilizacionEjercito1<<'\n';
	cout << "puntos ejercito2: " << puntosEjercito2 << "  civilizacion: "<< civilizacionEjercito2<<'\n';
	cout << "puntos ejercito3: " << puntosEjercito3 << "  civilizacion: "<< civilizacionEjercito3<<'\n';

	cout << "ejercito 1:" << endl;
	ejercito1.getPiqueros();
	ejercito1.getArqueros();
	ejercito1.getCaballeros();

	cout << "ejercito 2:" << endl;
	ejercito2.getPiqueros();
	ejercito2.getArqueros();
	ejercito2.getCaballeros();


	cout << "ejercito 3:" << endl;

	ejercito3.getPiqueros();
	ejercito3.getArqueros();
	ejercito3.getCaballeros();


	// los entreno
	// cout << "entrenamiento..."<<'\n';
	// cout << "pruebo piqueros:" << endl;
	// ejercito1.entrenar("piquero", 5);
	// ejercito1.getPiqueros();
	// cout << '\n';
	// ejercito1.entrenar("piquero", 8);
	// ejercito1.getPiqueros();
	// cout << '\n';
	// ejercito1.entrenar("piquero", 5);
	// ejercito1.entrenar("piquero", 8);
	// ejercito1.getPiqueros();

	// cout << "pruebo arqueros:" << endl;
	// ejercito1.entrenar("arquero", 10);
	// ejercito1.getArqueros();

	// cout << "pruebo caballeros:" << endl;
	// ejercito1.entrenar("caballero", 20);
	// ejercito1.getCaballeros();
	// cout << '\n';
	// ejercito1.entrenar("caballero", 20);
	// ejercito1.getCaballeros();


	// los transformo
	// cout << "transformación..."<<'\n';
	// cout << "pruebo piqueros:" << endl;
	// ejercito3.transformar("piquero");
	// ejercito3.getPiqueros();
	// ejercito3.getArqueros();

	// cout << "pruebo arqueros:" << endl;
	// ejercito3.transformar("arquero");
	// ejercito3.getArqueros();
	// ejercito3.getCaballeros();

	// cout << "pruebo caballeros:" << endl;
	// ejercito3.transformar("caballero");
	// ejercito3.getCaballeros();

	// batalla
	cout << "inicio ejercito1:" << endl;
	ejercito1.getPiqueros();
	ejercito1.getArqueros();
	ejercito1.getCaballeros();
	cout << "monedas: " << ejercito1.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito1.getPuntosTotales() << endl;
	cout << "inicio ejercito2:" << endl;
	ejercito2.getPiqueros();
	ejercito2.getArqueros();
	ejercito2.getCaballeros();
	cout << "monedas: " << ejercito2.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito2.getPuntosTotales() << endl;

	cout << endl;
	cout << "batallas..."<<endl;
	
	cout << "caso: ejercito2 mas fuerte" << endl;
	ejercito1.batallar(ejercito2);
	cout << "fin ejercito1:" << endl;
	ejercito1.getPiqueros();
	ejercito1.getArqueros();
	ejercito1.getCaballeros();
	cout << "monedas: " << ejercito1.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito1.getPuntosTotales() << endl;
	cout << "fin ejercito2:" << endl;
	ejercito2.getPiqueros();
	ejercito2.getArqueros();
	ejercito2.getCaballeros();
	cout << "monedas: " << ejercito2.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito2.getPuntosTotales() << endl;

	cout << endl;
	cout << endl;
	cout << "caso: ejercito1 mas fuerte" << endl;
	ejercito1.transformar("arquero");
	ejercito1.transformar("arquero");
	ejercito1.entrenar("caballero", 20);
	ejercito1.entrenar("caballero", 30);
	ejercito1.entrenar("caballero", 40);
	ejercito1.entrenar("caballero", 50);
	ejercito1.entrenar("caballero", 60); 
	ejercito1.entrenar("caballero", 20);
	ejercito1.entrenar("caballero", 30);
	ejercito1.entrenar("caballero", 40);
	ejercito1.entrenar("caballero", 50); 
	ejercito1.entrenar("caballero", 60); 

	cout << "inicio ejercito1:" << endl;
	ejercito1.getPiqueros();
	ejercito1.getArqueros();
	ejercito1.getCaballeros();
	cout << "monedas: " << ejercito1.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito1.getPuntosTotales() << endl;
	cout << "inicio ejercito2:" << endl;
	ejercito2.getPiqueros();
	ejercito2.getArqueros();
	ejercito2.getCaballeros();
	cout << "monedas: " << ejercito2.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito2.getPuntosTotales() << endl;

	cout << endl;
	ejercito1.batallar(ejercito2);
	cout << "fin ejercito1:" << endl;
	ejercito1.getPiqueros();
	ejercito1.getArqueros();
	ejercito1.getCaballeros();
	cout << "monedas: " << ejercito1.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito1.getPuntosTotales() << endl;
	cout << "fin ejercito2:" << endl;
	ejercito2.getPiqueros();
	ejercito2.getArqueros();
	ejercito2.getCaballeros();
	cout << "monedas: " << ejercito2.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito2.getPuntosTotales() << endl;


	cout << endl;
	cout << endl;
	cout << "caso: empate" << endl;
	ejercito2.entrenar("caballero", 20);
	ejercito2.entrenar("caballero", 30);
	ejercito2.entrenar("caballero", 20);
	ejercito2.entrenar("caballero", 30);
	ejercito2.entrenar("caballero", 40);


	cout << "inicio ejercito1:" << endl;
	ejercito1.getPiqueros();
	ejercito1.getArqueros();
	ejercito1.getCaballeros();
	cout << "monedas: " << ejercito1.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito1.getPuntosTotales() << endl;
	cout << "inicio ejercito2:" << endl;
	ejercito2.getPiqueros();
	ejercito2.getArqueros();
	ejercito2.getCaballeros();
	cout << "monedas: " << ejercito2.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito2.getPuntosTotales() << endl;

	cout << endl;
	ejercito1.batallar(ejercito2);
	cout << "fin ejercito1:" << endl;
	ejercito1.getPiqueros();
	ejercito1.getArqueros();
	ejercito1.getCaballeros();
	cout << "monedas: " << ejercito1.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito1.getPuntosTotales() << endl;
	cout << "fin ejercito2:" << endl;
	ejercito2.getPiqueros();
	ejercito2.getArqueros();
	ejercito2.getCaballeros();
	cout << "monedas: " << ejercito2.getMonedas() << endl;
	cout << "puntosTotales: " << ejercito2.getPuntosTotales() << endl;
	
	cout << endl;
	cout << endl;
	cout << "historial..." << endl;
	ejercito1.getHistorial();
	ejercito2.getHistorial();

	return 0;
}

