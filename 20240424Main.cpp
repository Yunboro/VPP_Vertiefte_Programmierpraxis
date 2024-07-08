//------------------------------------------------------------------
// 20240424Main.cpp
// Copyright 23.04.2024
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// @HOME fuer jede Klasse eine eigene Header und cpp-Datei erstellen

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

//g) Schnittstelle ILebewesen
class ILebewesen {
 public:
  virtual void gibLaut() const = 0;
  virtual double getLebensAlter() const = 0;
  virtual void output(std::ostream& os) const = 0;
  virtual ~ILebewesen() {}
};

// Abstrakte Klasse Lebewesen
class Lebewesen : public ILebewesen {
 private:
  int alter;
 public:
  explicit Lebewesen(int a) : alter{a} {}
  virtual int getAlter() const {return alter;}
  // statt diese Methoden allgemeingueltig zu implementieren
  // ist es besser sie als rein virtuelle Methoden in der
  // Schnittstelle zu deklarieren
  //virtual void gibLaut() const { cout << "hust hust" << endl;}
  //virtual double getLebensAlter() const {return alter;}
  virtual void output(std::ostream& os) const override {
    os << "Alter: " << alter << endl;
  }
  virtual ~Lebewesen() {}
  
};

class Hund : public Lebewesen {
 private:
  double gewicht;
 public:
  Hund(int a, double g) : Lebewesen{a}, gewicht{g} {}
  void output(std::ostream& os) const override {
    Lebewesen::output(os);
    cout << "Hund mit Gewicht: " << gewicht << endl;
  }
  
  // noch ergaenzt:
  void gibLaut() const override {
    cout << "Wau Wau" << endl;
  }
  double getLebensAlter() const override {return getAlter() * 5.5;}
  virtual ~Hund() {}
};

// @ HOME, Klasse Wellensittich, in main() Objekte anlegen
class Wellensittich : public Lebewesen {
 private:
  char geschlecht;
 public:
  Wellensittich(int a, char g) : Lebewesen{a}, geschlecht{g} {}
  void output(std::ostream& os) const  override {
    Lebewesen::output(os);
    cout << "Wellensittich mit Geschlecht: " << geschlecht << endl;
  }
  void gibLaut() const override {
    cout << "Piep Piep" << endl;
  }
  double getLebensAlter() const override {return getAlter() * 12.9;}
  void pick() const {cout << "Pick Pick" << endl;}
  virtual ~Wellensittich() {}
};

// k) Ueberladung Ausgabe-Operators <<
inline std::ostream& operator<<(std::ostream& os, const ILebewesen& il){
  il.output(os);
  return os;
}

// Methoden-Aufrufe auch ueber Basisklassen-Pointer/Basisklassen-Referenz

int main()
{
  Hund rex{5, 27.3};
  Hund struppi{2, 11.4};
  Wellensittich hansi{1, 'm'};
  
  // a) Statische Bindung
  //rex.output(cout);
  // Verwendung des Ueberladenen Ausgabe-Operators 
  cout << rex << endl;
  rex.gibLaut();
  
  // hansi.output(cout);
  // Verwendung des Ueberladenen Ausgabe-Operators 
  cout << hansi << endl;
  hansi.gibLaut();
  
  // b) dynamische Bindung mit Basisklassen-Referenz
  const Lebewesen& rl = rex;
  //const Lebewesen& rl = hansi;
  rl.output(cout);
  rl.gibLaut();
  
  // e) Methode pick() nur fuer Wellensittich, down-Cast
  //    ist erforderlich
  // rl.pick();
  // dynamic_cast<const Wellensittich&>(rl).pick();
  
  // c) dynamische Bindung mit Basisklassen-Pointer
  //Lebewesen* pl = &rex;
  Lebewesen* pl = &hansi;
  pl->output(cout);
  pl->gibLaut();
  Wellensittich* pw = dynamic_cast<Wellensittich*>(pl);
  if (pw == nullptr){
    cout << "kein wellsnsittich" << endl;
  } else {
    pw->pick();
  }
  
  // h) Polymorphie, alle in meinZoo geben Laut
  std::vector<ILebewesen*> meinZoo;
  meinZoo.push_back(&rex);
  meinZoo.push_back(&hansi);
  meinZoo.push_back(&struppi);
  
  //  Gleichartige Behandlung duch Aufruf einer Methode die in der
  //  Schnittstelle definiert ist, z. B. Lebensalter ausgeben,
  // analog @HOME Laut ausgeben
  auto it = meinZoo.begin();
  while (it != meinZoo.end()) {
    cout << (*it)->getLebensAlter() << endl;
    ++it;
  }
  
  // j) Typ-Information mit down-cast, nur Hunde geben Laut
  for(auto e: meinZoo) {
    Hund* ph = dynamic_cast<Hund*>(e);
    if (ph != nullptr){
      ph->gibLaut();
    }
  }
  return 0;
}
