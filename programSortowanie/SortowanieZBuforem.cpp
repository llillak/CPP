
#include <iostream>
using namespace std;



void zamiana(int *liczba1, int *liczba2)
{
  //utworzenie funkcji zamiana do zamieniania kolejnosci int'ow z wykorzystaniem bufora do przechowania liczb.
	int bufor;

	bufor = *liczba1;
	*liczba1 = *liczba2;
	*liczba2 = bufor;

	
}
int main()
{

  // po podaniu dwoch liczb do posortowania program sprawdzi czy jest potrzeba sortowania i jesli tak to to zrobi i wyswietli odpowiedni komunikat z posortowanymi liczbami. 
	int liczba1;
	int liczba2;

	cout << "podaj pierwsza zmienna do posortowania:" << endl;
	cin >> liczba1;
	cout << "podaj druga zmienna do posortowania" << endl;
	cin >> liczba2;

	cout<<"\n";
	cout << "liczby wybrane niezamienione: \n";
	cout << " pierwsza liczba:" << liczba1 << endl;;
	cout << "druga liczba:" << liczba2 << endl;;
	

	if(liczba2 < liczba1) {
		zamiana(&liczba1, &liczba2);
    cout<<"\n";
		cout << "liczby wybrane zamienione: \n";
		cout << " pierwsza liczba:" << liczba1<<endl;
		cout << "druga liczba:" << liczba2 << endl;;

	}
	

	return 0;
}