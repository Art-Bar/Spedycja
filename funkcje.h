#ifndef FUNKCJE_S
#define FUNKCJE_S
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "struktury.h"
#define MAX 100000

using namespace std;




	

	/**Funkcja czyta list� mo�liwych tras z pliku.
	@param nazwa Nazwa pliku wej�ciowego.
	@param wektor Wektor tras pomiedzy miastami.
	*/
	void czytaj(string input,std::vector <trasy> &tab);
	/**Funkcja tworzy liste wszystkich miast ktore znajduja sie w podanym pliku.
	@param wektor Wektor w kt�rm funkcja zapisuje liste wszystkich r�nych miast znajduj�cych si� w pliku.
	@param wektor Wektor tras pomi�dzy miastami.
	*/
	void ilemiast(vector<string>& vect, vector<trasy>& tab);
	/**Funkcja wyznacza indeks najbli�szego nieodwiedzonego miasta do podanego.
	@param tablica Tablica odleg�o�ci ka�dego miasta od centrali.
	@param tablica Tablica, w kt�rej znajduj� si� informacje o tym czy miasto zosta�o odwiedzone.
	@param zmienna Ilo�� miast.
	@param[out] zmienna Indeks najbli�szego nieodwiedzonego miasta.
	*/
	int minDist(int dist[], bool odwiedzone[], int ile);
	/**Funkcja implementuj�ca algorytm Dijkstry do wyznaczenia najkr�tszych tras z centrali i wypisuj�ca wyniki do pliku.
	@param wektor wektor wszystkich r�nych miast znajdujacych sie w pliku.
	@param liczba Indeks centrali w wektorze miast.
	@param tablica Dwuwymiarowa tablica odleg�o�ci mi�dzy miastami.
	@param nazwa Nazwa pliku wyj�ciowego.
	*/
	void Dijkstra(vector<string>& miasta, int centrala_tab, int** graph, string output);
	/**Funkcja tworzy z listy tras oraz listy wszystkich miast dwuwymiarow� tablic� odleg�o�ci pomi�dzy miastami.
	@param nazwa Nazwa Centrali.
	@param nazwa Nazwa pliku wyj�ciowego.
	@param wektor Wektor tras pomi�dzy miastami.
	*/
	void Spedycja(string centrala, string output, vector<trasy>& tab);
	

#endif
