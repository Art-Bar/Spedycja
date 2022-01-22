#ifndef FUNKCJE_S
#define FUNKCJE_S
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "struktury.h"
#define MAX 100000

using namespace std;




	

	/**Funkcja czyta listê mo¿liwych tras z pliku.
	@param nazwa Nazwa pliku wejœciowego.
	@param wektor Wektor tras pomiedzy miastami.
	*/
	void czytaj(string input,std::vector <trasy> &tab);
	/**Funkcja tworzy liste wszystkich miast ktore znajduja sie w podanym pliku.
	@param wektor Wektor w którm funkcja zapisuje liste wszystkich ró¿nych miast znajduj¹cych siê w pliku.
	@param wektor Wektor tras pomiêdzy miastami.
	*/
	void ilemiast(vector<string>& vect, vector<trasy>& tab);
	/**Funkcja wyznacza indeks najbli¿szego nieodwiedzonego miasta do podanego.
	@param tablica Tablica odleg³oœci ka¿dego miasta od centrali.
	@param tablica Tablica, w której znajduj¹ siê informacje o tym czy miasto zosta³o odwiedzone.
	@param zmienna Iloœæ miast.
	@param[out] zmienna Indeks najbli¿szego nieodwiedzonego miasta.
	*/
	int minDist(int dist[], bool odwiedzone[], int ile);
	/**Funkcja implementuj¹ca algorytm Dijkstry do wyznaczenia najkrótszych tras z centrali i wypisuj¹ca wyniki do pliku.
	@param wektor wektor wszystkich ró¿nych miast znajdujacych sie w pliku.
	@param liczba Indeks centrali w wektorze miast.
	@param tablica Dwuwymiarowa tablica odleg³oœci miêdzy miastami.
	@param nazwa Nazwa pliku wyjœciowego.
	*/
	void Dijkstra(vector<string>& miasta, int centrala_tab, int** graph, string output);
	/**Funkcja tworzy z listy tras oraz listy wszystkich miast dwuwymiarow¹ tablicê odleg³oœci pomiêdzy miastami.
	@param nazwa Nazwa Centrali.
	@param nazwa Nazwa pliku wyjœciowego.
	@param wektor Wektor tras pomiêdzy miastami.
	*/
	void Spedycja(string centrala, string output, vector<trasy>& tab);
	

#endif
