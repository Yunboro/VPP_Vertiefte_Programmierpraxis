#include <iostream>
#include <iomanip> // fuer Manipulatoren
// mit Parameter
using std::cout;
using std::endl;
int S75_format_manipulatoren(){
    // Fuer ganze Zahlen
    int i = 255;
    // Umschalten auf hexadezimale Ausgabe
    // Umschalten auf Ausgabe der Zahlensystem-Kennung
    cout << "i = " << std::hex << std::showbase << i << endl;
    // i = 0xff
    // Umschalten auf Gorssbuchstaben
    cout << "i = " << std::uppercase << i << endl;
    // i = 0XFF
    // Umschalten auf dezimale Ausgabe
    cout << "i = " << std::dec << i << endl;
    // i = 255
    // Fuer Gleitpunktzahlen
    double x = 4712.123456;
    cout << "x = " << x << endl;
    x = 4712.12;
    // Umschalten auf Wissenschaftliche Darstellung
    cout << "x = " << std::scientific << x << endl;
    // x = 4.712123E+03
     // Setzen der Feld-Breite
     cout << "x = " << std::setw(20) << x << endl;
     // x = 4.712123E+03
     // Linksbuendige Ausgabe:
     cout << "x = " << std::setw(20)
     << std::left << x << endl;
     // x = 4.712123E+03
     // Setzen der Genauigkeit auf 3 Nachkommastellen
     cout << "x = " << std::setw(20)
     << std::setprecision(3) << x << endl;
     // x = 4.712E+03
     // Zureucksetzen auf Rechtsbuendige Ausgabe
     // Setze ? als Fuellzeichen
     cout << "x = " << std::setw(20) << std::right
     << std::setfill('?')
     << x << endl;
     // x = ???????????4.712E+03
     return 0;
 }
