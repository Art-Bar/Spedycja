#ifndef STRUKTURY_H  // zabezpieczenie przed wielokrotnym do³¹czaniem pliku nag³ówkowego
#define STRUKTURY_H

#include <vector>
#include <string>

///Struktura, do ktorej w funkcji czytaj() czytane sa z pliku nazwy miast i odleg³oœci miedzy nimi.
struct trasy
{
	///Miasto pocz¹tkowe.
	std::string Od;
	///Miasto koñcowe.
	std::string Do;
	///Odleg³oœæ pomiêdzy miastami.
	int dlugosc;



};


#endif
	
