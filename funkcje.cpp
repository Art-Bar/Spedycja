#include "funkcje.h"

void czytaj(string input, std::vector <trasy>& tab)
{
	
	ifstream plik(input, ios::in);
	trasy t;

	if (plik.good())
	{
		while (!plik.eof())
		{
			plik >> t.Od;
			plik >> t.Do;
			plik >> t.dlugosc;
			tab.push_back(t);
		}
	}
	else
	{
		std::cout << "Nieprawidlowy plik wejsciowy!" << "\n";
	}
	plik.close();


	


}


	

void ilemiast(vector<string>& vect, vector<trasy>& tab)
{
	bool wpisac = true;
	vect.push_back(tab[0].Od);
	if (tab[0].Do != vect[0])
	{
		vect.push_back(tab[0].Do);
	}
	for (int i = 1; i < tab.size(); i++)
	{
		for (int j = 0; j < vect.size(); j++)
		{
			if (tab[i].Od == vect[j])
			{
				wpisac = false;
				break;
			}
		}
		if (wpisac) vect.push_back(tab[i].Od);
		wpisac = true;
		for (int j = 0; j < vect.size(); j++)
		{
			if (tab[i].Do == vect[j])
			{
				wpisac = false;
				break;
			}

		}
		if (wpisac) vect.push_back(tab[i].Do);
		wpisac = true;
	}
}
int minDist(int dist[], bool odwiedzone[], int ile)
{
	int minimum = MAX, next;
	for (int k = 0; k < ile; k++)
	{
		if (odwiedzone[k] == false && dist[k] <= minimum)// szuka najbli¿szego nieodwiedzonego punktu
		{
			minimum = dist[k];
			next = k;
		}
	}
	return next;
}
void Dijkstra(vector<string>& miasta, int centrala_tab, int** graph, string output)
{

	const int ile = miasta.size();
	int* dist = new int[ile];
	bool* odwiedzone = new bool[ile];
	int* parent = new int[ile];
	for (int i = 0; i < ile; i++)
	{
		dist[i] = MAX; // maksymalny dystans do wszystkich miast oprócz centrali (dla centrali dystans wynosi 0)
		odwiedzone[i] = false;//¿adne miasto nie odwiedzone
		parent[i] = i;//elementem trasy do ka¿dego miasta jest sama centrala (czyli pocz¹tek podró¿y)
	}
	//pêtla inicjuje tablice zmiennych 
	dist[centrala_tab] = 0;
	//Pocz¹tek algorytmu dijkstry
	
	for (int i = 0; i < ile; i++) //algorytm wykonuje siê tyle razy ile jest miast w wektorze miasta
	{
		
		int m = minDist(dist, odwiedzone, miasta.size()); //wyznacza miejsce w tablicy najbli¿szego nieodwiedzonego miasta
		odwiedzone[m] = true;//zmienia miasto m na odwiedzone 
		for (int j = 0; j < ile; j++)//pêtla wykonuje siê dla wszystkich miast w wektorze miasta (pierwsze powtórzenie pêtli wykonuje sie dla samej centrali.)
		{
			if (!odwiedzone[j] &&       graph[m][j] && dist[m] != MAX        && dist[m] + graph[m][j] < dist[j])
			{
				dist[j] = dist[m] + graph[m][j]; // zastêpuje "bezpoœrednie"(które mo¿e wynosiæ nieskoñczonoœæ) po³¹czenie tras¹ przez miasto m
				parent[j] = m; // miasto m staje siê elementem trasy do miasta j;
			}//sprawdza czy miasto 1. jest nie odwiedzone 2.jest po³¹czone z miastem m i czy miasto m jest po³¹czone z central¹ 3. dystans z centrali do miasta j przez miasto m jest krótszy ni¿ bezpoœrednio do j.
		}

	}
	//koniec algorytmu dijkstry
	/////////////////////////////////////do osobnej funkcji//////////////////////////////////
	vector<string> trasa;
	ofstream wynik(output, ios::out);
	for (int i = 0; i < miasta.size(); i++)
	{
		if (i != centrala_tab)
		{
			wynik << miasta[centrala_tab] << " ->";
			int parnode = parent[i];
			while (parnode != centrala_tab)
			{
				trasa.push_back(miasta[parnode]);

				// cout << miasta[parnode] << "->" << " ";
				parnode = parent[parnode];

			}
			for (int j = trasa.size() - 1; j >= 0; j--)
			{
				wynik << trasa[j] << "->" << " ";;
			}
			trasa.clear();
			wynik << miasta[i] << " :" << dist[i] << "\n";
		}
	}
	wynik.close();
	//////////////////////////////////////////////////////////////////////////////////////////

}

void Spedycja(string centrala, string output, vector<trasy>& tab)
{
	vector < string > miasta;
	ilemiast(miasta,tab);
	int centrala_tab;
	for (int j = 0; j < miasta.size(); j++)
	{
		cout << miasta[j] << "\n";
		if (miasta[j] == centrala)
		{
			centrala_tab = j;
		}
	}


	int** graph;
	graph = new int* [miasta.size()];
	for (int i = 0; i < miasta.size(); i++)
	{
		graph[i] = new int[miasta.size()];
	}
	for (int i = 0; i < miasta.size(); i++)
	{
		for (int j = 0; j < miasta.size(); j++)
		{
			graph[i][j] = 0;
		}

	}


	for (int i = 0; i < miasta.size(); i++)
	{
		for (int j = 0; j < miasta.size(); j++)
		{
			for (int k = 0; k < tab.size(); k++)
			{
				if (tab[k].Od == miasta[i] && tab[k].Do == miasta[j])
				{
					graph[i][j] = tab[k].dlugosc;
				}
				if (tab[k].Do == miasta[i] && tab[k].Od == miasta[j])
				{
					graph[i][j] = tab[k].dlugosc;
				}
			}

		}
	}
	for (int i = 0; i < miasta.size(); i++)
	{
		for (int j = 0; j < miasta.size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	Dijkstra(miasta, centrala_tab, graph, output);


	
	for (int i = 0; i < miasta.size(); i++) {
		delete[] graph[i];
	}
	
	delete[] graph;

}


