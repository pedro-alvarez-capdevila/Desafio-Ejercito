#include "juego.h"

void batallar(Ejercito &ejercito1, Ejercito &ejercito2){
	// esto siempre se actualiza sin importar quien gane.
	ejercito1.actualizarHistorial(ejercito2.getCivilizacion());
	ejercito2.actualizarHistorial(ejercito1.getCivilizacion());
	if(ejercito1.getPuntosTotales() < ejercito1.getPuntosTotales()){ // ganó ejercito2.
		ejercito2.aumentar100MonedasPorGanar();
		// busco las dos unidades con mayor puntaje y las borro.
		ejercito1.borrarUnidadesMasFuertes(2);
	} else if (ejercito1.getPuntosTotales() > ejercito1.getPuntosTotales()){ // ganó ejercito1.
		ejercito1.aumentar100MonedasPorGanar();
		ejercito2.borrarUnidadesMasFuertes(2);
	} else { // empate.
		// cada uno pierde la unidad de mas valor.
		ejercito1.borrarUnidadesMasFuertes(1);
		ejercito2.borrarUnidadesMasFuertes(1);
	}
}

juego::~juego(){

}
