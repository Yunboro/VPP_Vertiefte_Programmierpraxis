//------------------------------------------------------------------
// 20240417Main.cpp
// Copyright 16.04.2024
// Author: KJR
//------------------------------------------------------------------
#include <iostream>

using std::cout;
using std::endl;

// Vererbungs-Hierarchie Lebewesen, Hund, Wellensittich 
// Der Einfachheit halber alles in einer cpp-Datei
// Spaeter: a) statische Bindung
//          b) dynamische Bindung mit Basisklassen-Referenz
//          c) dynamische Bindung mit Basisklassen-Pointer
//          d) Notwendigkeit von virtual, virtueller Destruktor
//          e) Methode pick() nur fuer Wellensittich, down-Cast 
//          f) Klasse Lebewesen wird Abstrakte Klasse
//          g) Schnittstelle ILebewesen
//          h) Polymorphie, alle in meinZoo geben Laut 
//          i) Schnittstellen-Programmierung
//             Algorithmus wird programmiert, indem er nur
//             die in der Schnittstelle vorhandenen Methoden
//             verwendet
//             Bsp.: freie Funktion 
//             void algo1(const ILebewesen& il)
//                      zur erstellenden "Algorithmus"
//                      1) Ausgabe des Lebewesens,
//                      2) danach Ausgabe des Lebens-Alters
//          j) Typ-Information mit down-cast, nur Hunde geben Laut
//          k) Ueberladung Ausgabe-Operators <<
class Lebewesen{
 private:
  int alter;
 public:
  explicit Lebewesen(int a) : alter{a} {}
  int getAlter() const {return alter;}
  void gibLaut() const { cout << "hust hust" << endl;}
  double getLebensAlter() const {return alter;}
  void output(std::ostream& os) const {
    os << "Alter: " << alter << endl;
  }
  ~Lebewesen() {}
  
};

class Hund : public Lebewesen {
 private:
  double gewicht;
 public:
  Hund(int a, double g) : Lebewesen{a}, gewicht{g} {}
  void output(std::ostream& os) const {
    Lebewesen::output(os);
    cout << "Hund mit Gewicht: " << gewicht << endl;
  }
  double getLebensAlter() const {return getAlter() * 5.5;}
  ~Hund() {}
};

// @ HOME, Klasse Wellensittich, in main() Objekte anlegen
// Methoden-Aufrufe auch ueber Basisklassen-Pointer/Basisklassen-Referenz

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
