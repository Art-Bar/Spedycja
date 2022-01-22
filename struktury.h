#ifndef STRUKTURY_H  // zabezpieczenie przed wielokrotnym do��czaniem pliku nag��wkowego
#define STRUKTURY_H

#include <vector>
#include <string>

///Struktura, do ktorej w funkcji czytaj() czytane sa z pliku nazwy miast i odleg�o�ci miedzy nimi.
struct trasy
{
	///Miasto pocz�tkowe.
	std::string Od;
	///Miasto ko�cowe.
	std::string Do;
	///Odleg�o�� pomi�dzy miastami.
	int dlugosc;



};


#endif
	
