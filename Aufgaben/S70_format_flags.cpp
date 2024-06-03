#include <iostream>
using std::cout;
using std::clog;
using std::endl;
using std::ios;

int S70_format_flags(){
    // Fuer ganze Zahlen
    int i = 255;
    // Speichere aktuellen Status der Format-Flags
    ios::fmtflags myFlags = cout.flags();
    clog << "myFlags: " << myFlags << endl;
    // myFlags: 4098
    // Umschalten auf hexadezimale Ausgabe
    cout.setf(ios::hex, ios::basefield);
    // Umschalten auf Ausgabe der Zahlensystem-Kennung
    cout.setf(ios::showbase);
    cout << "i = " << i << endl;
    // i = 0xff
    // Ausgabe des aktuellen Status der Format-Flags
    clog << "myFlags: " << cout.flags() << endl;
    // myFlags: 4616
    // Umschalten auf Gorssbuchstaben
    cout.setf(ios::uppercase);
    cout << "i = " << i << endl;
    // i = 0XFF
    // Ausgabe des aktuellen Status der Format-Flags
    clog << "myFlags: " << cout.flags() << endl;
    // myFlags: 21000#
    // Zuruecksetzen der Ausgabe der Zahlensystem-Kennung
    cout.unsetf(ios::showbase);
    // Umschalten auf dezimale Ausgabe
    cout.setf(ios::dec, ios::basefield);
    cout << "i = " << i << endl;
    // i = 255
    // Fuer Gleitpunktzahlen
    double x = 4712.123456;
    cout << "x = " << x << endl;
    // x = 4712.12
    // Umschalten auf Wissenschaftliche Darstellung
    cout.setf(ios::scientific, ios::floatfield);
    cout << "x = " << x << endl;
    // x = 4.712123E+03
    // Ausgabe des aktuellen Status der Format-Flags
    clog << "myFlags: " << cout.flags() << endl;
    // myFlags: 20738
    // Setzen der Feld-Breite
    cout << "x = ";
    cout.width(20); // gilt nur fuer die naechste Ausgabe
    // unschoen, die Ausgabe-Kette muss
    // unterbrochen werden
    // deshalb bessere Loesung:
    // Manipulatoren (s.u.)
    clog << "Aktuele Feldbreite: " << cout.width() << endl;
    // Aktuele Feldbreite: 20
    cout << x << endl;
    // x = 4.712123E+03
    // Linksbuendige Ausgabe:
     cout.setf(ios::left, ios::adjustfield);
     cout << "x = ";
     cout.width(20);
     cout << x << endl;
     //x = 4.712123E+03
     // Setzen der Genauigkeit auf 3 Nachkommastellen
     cout.precision(3);
     cout << "x = ";
     cout.width(20);
     cout << x << endl;
     // x = 4.712E+03
     // Zureucksetzen auf Rechtsbuendige Ausgabe
     cout.setf(ios::right, ios::adjustfield);
     // Setze ? als Fuellzeichen
     cout.fill('?');
     cout << "x = ";
     cout.width(20);
     cout << x << endl;
     // x = ???????????4.712E+03
     return 0;
 }
