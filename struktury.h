#ifndef STRUKTURY_H  // zabezpieczenie przed wielokrotnym dołączaniem pliku nagłówkowego
#define STRUKTURY_H

#include <vector>
#include <string>

///Struktura, do ktorej w funkcji czytaj() czytane sa z pliku nazwy miast i odległości miedzy nimi.
struct trasy
{
	///Miasto początkowe.
	std::string Od;
	///Miasto końcowe.
	std::string Do;
	///Odległość pomiędzy miastami.
	int dlugosc;



};


#endif
	
