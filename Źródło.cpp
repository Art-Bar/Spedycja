#include "funkcje.h"

using namespace std;



vector <trasy> tab;
//vector <string> miasta;
	


int main(int argc, char* argv[])
{
	string input, centrala, output;

	if (argc == 1)
	{
		cout << "Argumenty polecenia:" << "\n";
		cout << "-i <nazwa pliku> : plik wejœciowy" << "\n";
		cout << "-o <nazwa pliku> : plik wyjœciowy" << "\n";
		cout << "-s <nazwa miasta>: centrala" << "\n";
		cout << "-h               : pomoc" << "\n";
	}
	else
	{
		for (int i = 0; i < argc; ++i)
		{
			if (strcmp("-i", argv[i]) == 0)
			{
				input = argv[i + 1];
				cout << input << endl;
			}
			else if (strcmp("-o", argv[i]) == 0)
			{
				output = argv[i + 1];
				cout << output << endl;
			}
			else if (strcmp("-s", argv[i]) == 0)
			{
				centrala = argv[i + 1];
			}
			else if (strcmp("-h", argv[i]) == 0)
			{
				cout << "Argumenty polecenia:" << "\n";
				cout << "-i <nazwa pliku> : plik wejœciowy" << "\n";
				cout << "-o <nazwa pliku> : plik wyjœciowy" << "\n";
				cout << "-s <nazwa miasta>: centrala" << "\n";
				cout << "-h               : pomoc" << "\n";
				return 0;
			}


		}

		czytaj(input, tab);

		bool dziala = false;

		for (int i = 0; i < tab.size(); i++)
		{
			if (centrala == tab[i].Od || centrala == tab[i].Do)
			{

				Spedycja(centrala, output, tab);
				dziala = true;
				
				break;
			}
		}
		if (dziala == false)
		{
			cout << "Nieprawidlowa centrala!" << "\n";
		}

	}

	

	return 0;
}


