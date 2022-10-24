#include <iostream>
#include <string>
using namespace std;

struct osoba {
    string imie, nazwisko;
    int wiek;
    struct osoba* nastepna;
    osoba(string imie, string nazwisko, int wiek);
    osoba();
};

osoba::osoba() {
    nastepna = 0;
}

struct dane {
    osoba* pierwsza;
    dane();
    void dodaj_osobe(string imie, string nazwisko, int wiek);
    void usun_osobe_po_numerze(int numer);
    void usun_po_nazwisku(string nazwidko);
    void wyswietl_liste();
    void szukaj_osobe_po_nazwisku(string nazwisko);

};

dane::dane() {
    pierwsza = 0;
}

int main()
{
    dane* osoby = new dane;
    string imie, nazwisko;
    int wiek, numer, operacja;
    for (int i = 0; i < 1;)
    {
        cout << endl;
        cout << "wybierz operacje: " << endl;
        cout << "1. Dodaj osobe (podaj imie, nazwisko oraz wiek nowej osoby)" << endl;
        cout << "2. Usun osobe po numerze (podaj numer osoby)" << endl;
        cout << "3. Usun osobe o nazwisku (podaj nazwisko)" << endl;
        cout << "4. Wypisywanie listy osob" << endl;
        cout << "5. Szukaj osoby po nazwisku (podaj nazwisko osoby ktora szukasz" << endl;
        cout << "6. Koniec" << endl;
        cout << "wybrana operacja: ";
        cin >> operacja;
        if (operacja == 1) {
            cout << "podaj imie: " << endl;
            cin >> imie;
            cout << "podaj nazwisko: " << endl;
            cin >> nazwisko;
            cout << "podaj wiek: " << endl;
            cin >> wiek;
            cout << endl;
            osoby->dodaj_osobe(imie, nazwisko, wiek);
        }
        else if (operacja == 2) {
            cout << "podaj numer: " << endl;
            cin >> numer;
            osoby->usun_osobe_po_numerze(numer);
        }

        else if (operacja == 3) {
            cout << "podaj nazwisko: " << endl;
            cin >> nazwisko;
            osoby->usun_po_nazwisku(nazwisko);
        }
        else  if (operacja == 4) {
            cout << "LISTA Z DANYMI OSOB: " << endl;
            cout << "imie  " << " nazwisko  " << " wiek " << endl;
            osoby->wyswietl_liste();
        }
        else if (operacja == 5) {
            cout << "podaj nazwisko: " << endl;
            cin >> nazwisko;
            cout << "imie  " << " nazwisko  " << " wiek " << endl;
            osoby->szukaj_osobe_po_nazwisku(nazwisko);
        }
        else if (operacja == 6) {
            exit(0);
        }
        else {
            cout << "nie ma takiej operacji!" << endl;
        }
        

    }

}
void dane::dodaj_osobe(string imie, string nazwisko, int wiek)
{
    osoba* nowa = new osoba;

    nowa->imie = imie;
    nowa->nazwisko = nazwisko;
    nowa->wiek = wiek;

    if (pierwsza == 0)
    {

        pierwsza = nowa;
    }
    else
    {
        osoba* szablon = pierwsza;
        while (szablon->nastepna)
        {
            szablon = szablon->nastepna;
        }
        szablon->nastepna = nowa;
        nowa->nastepna = 0;
    }
}



void dane::usun_osobe_po_numerze(int numer)
{

    if (numer == 1)
    {
        osoba* szablon = pierwsza;
        pierwsza = szablon->nastepna;
        delete szablon;
    }
    else if (numer >= 2) {
        int j = 1;
        osoba* szablon = pierwsza;
        while (szablon) {
            if ((j + 1) == numer) break;

            szablon = szablon->nastepna;
            j++;
        }
        if (szablon->nastepna->nastepna == 0) {
            delete szablon->nastepna;
            szablon->nastepna = 0;
        }
        else {
            osoba* usuwana = szablon->nastepna;
            szablon->nastepna = szablon->nastepna->nastepna;
            delete usuwana;
        }
    }
}
void dane::usun_po_nazwisku(string nazwisko)
{
    osoba* szablon = NULL;
    osoba* osoba = pierwsza;

    while (osoba && osoba->nazwisko != nazwisko)
    {
        szablon = osoba;
        osoba = osoba->nastepna;
    }
    if (osoba == NULL)
    {
        cout << "Nie ma juz tego nazwiska na liscie" << endl;
    }
    else if (osoba == pierwsza)
    {
        pierwsza = pierwsza->nastepna;
        delete osoba;
        usun_po_nazwisku(nazwisko);
    }
    else
    {
        szablon->nastepna = osoba->nastepna;
        delete osoba;
        usun_po_nazwisku(nazwisko);
    }


    return;
}




void dane::wyswietl_liste()
{
    osoba* szablon = pierwsza;
    while (szablon) {

        cout << szablon->imie << "  " << szablon->nazwisko << "  " << szablon->wiek << endl;
        szablon = szablon->nastepna;
    }
}

void dane::szukaj_osobe_po_nazwisku(string nazwisko)
{
    osoba* szablon = pierwsza;

    while (szablon->nazwisko == nazwisko) {

        cout << szablon->imie << "  " << szablon->nazwisko << "  " << szablon->wiek << endl;
        szablon = szablon->nastepna;
       
    }

}