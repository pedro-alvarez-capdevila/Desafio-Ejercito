#include "juego.h"

void batallar(Ejercito &ejercito1, Ejercito &ejercito2){
	// esto siempre se actualiza sin importar quien gane.
	ejercito1.actualizarHistorial(ejercito2.getCivilizacion());
	ejercito2.actualizarHistorial(ejercito1.getCivilizacion());
	if(ejercito1.getPuntosTotales() < ejercito1.getPuntosTotales()){ // ganó ejercito2.
		ejercito2.aumentar100MonedasPorGanar();
	} else if (ejercito1.getPuntosTotales() > ejercito1.getPuntosTotales()){
		ejercito1.aumentar100MonedasPorGanar();
	} else { // implica que es un empate.

	}
}