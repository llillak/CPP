
#include <iostream>
using namespace std;

class Czworokat{ 
// utworzenie klasy Czworokat ze zmiennymi chronionymi a,b,c i d oraz z publiczna funkcją wypisz() i wirtualną funkcją pole(), która na początku przyjmuje wartość 0. znajduje się też tam konstruktor klasy Czworokat.

protected: int a, b, c, d;
public:
    void wypisz(){
        cout << a << b << c << d << endl;
    }
    virtual void pole() = 0;
        
    Czworokat(int a, int b, int c, int d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    Czworokat() {}
    


};


class Prostokat :public Czworokat {
//definiowanie klasy Prostokat, z zainicjowaną funkcją wymiary() oraz pole().
public:
    Prostokat(int a, int b) {
        this->a = a;
        this->b = b;
        this->c = a;
        this->d = b;
    }
    void wymiary(int w1, int w2) {
        a = w1;
        c = w1;
        b = w2;
        d = w2;
    }

    void pole() {
      
        cout <<"Pole Prostokata wynosi:"<< a * b << endl;

    }

};

class Kwadrat : public Czworokat {

//definiowanie klasy Kwadrat, z zainicjowaną funkcją wymiary() oraz pole().
public:
    
    Kwadrat(int a) {
        this->a = a;
        this->b = a;
        this->c = a;
        this->d = a;
    }

    void wymiary(int w1) {
        a = w1;
        c = w1;
        b = w1;
        d = w1;
    }

    void pole() {

        cout << "Pole Kwadratu wynosi:" << a*a << endl;

    }
};

int main()
{
  //wczytywanie wartości a, b, c i d do obliczenia pola Kwadratu i Prostokata
  int a, b, c;
  cout << "podaj bok a dla prostokąta: \n";
  cin >> a ;
  cout<< "podaj bok b dla prostokąta: \n";
  cin>> b;
  cout<< "podaj boka a dla kwadratu: \n";
  cin>> c;

  //tworzenie nowych obiektów klasy Prostokat i Kwadrat oraz wyświetlanie ich pola
    Czworokat* obj;
  cout<<"\n";
    obj = new Prostokat(a,b);
    obj->pole();
  cout<<"\n";
    obj = new Kwadrat(c);
    obj->pole();
