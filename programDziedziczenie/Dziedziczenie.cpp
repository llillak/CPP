#include <iostream>
using namespace std;


class Dodawanie{
//klasa Dodawania posiadajaca funkcje dodaj 
public:
	int wynik;
	void dodaj(int a, int b) {
		wynik = a + b;
	}
};

class Odejmowanie{
//klasa Odejmowanie posiadajaca funkcje odejmij 
public:
int wynik;
void odejmij(int a, int b) {
	wynik = a - b;
}
};

class Mnozenie{
//klasa Mnozenie posiadajaca funkcje pomnoz
public:
int wynik;
void pomnoz(int a, int b) {
	wynik = a * b;
}
};


class Dzielenie{
//klasa Dzielenie posiadajaca funkcje podziel 
public:
int wynik;
void podziel(int a, int b) {
	wynik = a / b;
}
};

class Dzialanie : public Dodawanie, public Odejmowanie, public Dzielenie, public
Mnozenie
{
//dziedziczenie klasy Dzialanie
public:
Dzialanie() {
  //konstruktor klasy Dzialanie
a = 0;
b = 0;
};
private:
int a,b;
public:
	void wczytajWartosci() {
    //funkcja wczytajWartosci, ktora wczytuje dane dwoch liczb a i b
		cout << "podaj liczby: \n";
		cout << "liczba a:";
		cin >> a;
		cout << "liczba b:";
		cin >> b;
	}
	void obliczDzialania() {
//funkcja obliczDzialania, ktora zbiera dane dla funkcji z wczesniejszych klas 
		
		dodaj(a, b);

		odejmij(a, b);

		pomnoz(a, b);

		podziel(a, b);

	}
	void print() {

		cout << "suma: ";
		cout << Dodawanie::wynik;
		cout << endl;

		cout << "roznica: ";
		cout << Odejmowanie::wynik;
		cout << endl;

		cout << "iloczyn: ";
		cout << Mnozenie::wynik;
		cout << endl;

		cout << "iloraz: ";
		cout << Dzielenie::wynik;
		cout << endl;
	}
};

int main()
{
	Dzialanie obiekt;
  // wczytywanie danych do funkcji i wykonanie ich w main'ie

	obiekt.wczytajWartosci();
	obiekt.obliczDzialania();
	obiekt.print();

}
