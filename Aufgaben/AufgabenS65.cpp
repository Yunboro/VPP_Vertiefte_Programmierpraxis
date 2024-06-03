
#include <iostream>
#include <cmath>
#include <main.h>
using std::cout;
using std::cin;
using std::endl;

int S65_ein_ausgabe(){
    double radius, umfang;
    char anfangVorname, anfangNachname;

    //Umfang-Berechnung
    cout << "Eingabe Radius:";
    cin >> radius;
    umfang = 2 * M_PI * radius;
    cout << "Der Kreis hat den Umfang: " << umfang << endl;

    //Anfangsbuchstaben von Vorname
    //und Nachnameds1s
    cout << "Eingabe Vorname blank Nachname:";
    cin >> anfangVorname;
    cin.ignore(20, ' ');
    cin >> anfangNachname;
    cout << "Ihre Initialien lauten: " << anfangVorname << " und " << anfangNachname << endl;
    return 0;
}
