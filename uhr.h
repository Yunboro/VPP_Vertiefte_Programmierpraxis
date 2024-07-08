//------------------------------------------------------------------
// Uhr
// Copyright 10.04.2024
// Author: KJR
//------------------------------------------------------------------
#ifndef UHR_H
#define UHR_H

#include <iostream>

// Fuer Sequenz-Konstruktor
#include <initializer_list>


class Uhr
{
 private:
  // Klassen-Variable
  static int SDEFAULT;
  
  // Attribute
  int stunden, minuten, sekunden;
  
  // private Hilfsmethode
  void checkAttributes() {
    if (stunden < 0 || stunden >= 24){
      stunden = 0;
    }
    minuten = ((minuten < 0 || minuten >= 60) ? 0 : minuten);
    sekunden = ((sekunden < 0 || sekunden >= 60) ? 0 : sekunden);
  }
  
 public:
  // Klassen-Methode
  static int getSDefault();
  
  // Methoden
  void displayClock() const;
  void output(std::ostream& os) const;
  void tick();
  
  // Konstruktoren
  // Standard Konstruktor
  // Compiler explizit bitten ihn zu erstellen
  // Uhr() = default;
  
  // Eigene Implementierung als Delegierender Konstruktor
  
  // Anderer Konstruktor kann nur innerhalb der Memeber-Initialsierunsliste
  // aufgerufen werden
  // Uhr() : Uhr{0,0,0} {
  // Wegen Sequnzkonstruktor hier die runden Klammern verwenden
  Uhr() : Uhr(0,0,SDEFAULT) {
    std::cout << "Standard-Konstruktor" << std::endl;
    
    // Vorsicht falscher Aufruf des Konstruktos mit Parametern
    // anstelle den Konstruktor mit Parametern aufzurufen wird hierdurch
    // ein temporaeres Uhr Objekt erstellt
    // Uhr(0,0,0);
  }
  
  // Erstellung des Copy-Konstruktors durch Compiler unterbinden
  Uhr(const Uhr& rhs) = delete;
  
  // Konstruktor mit Parametern
  // Konvertierender Konstruktor 
  // Uhr(int h, int m=0, int s=0)

  // nicht konvertierender Konstruktor mit der Hilfe von explicit
  explicit Uhr(int h, int m=0, int s=0)
      // Member-Initialisrungsliste
      // Vorsicht: Initiaisrung in der Reihenfolge in der
      // Attribute deklariert wurden
      //: minuten{m}, stunden{h}, sekunden{s}
      : stunden{h},  minuten{m}, sekunden{s}
    {
    
    std::cout << "Konstruktor mit Parametern" << std::endl;
    
    // Setzen der Attribute im Rumpf ist nicht effizient
    // besser mit Member-Initialisrungsliste (s.o.)
    // stunden = h;
    // minuten = m;
    // sekunden = s;
    checkAttributes();
  }
  
  // Sequenz-Konstruktor
  Uhr(std::initializer_list<int> liste) {
    std::cout << "Sequenzkonstruktor" << std::endl;
    // Arbeiten mit Iterator
    auto it = liste.begin();
    if(it != liste.end()){
      stunden = *it;
      ++it;
    } else {
      stunden = 0;
    }
    if(it != liste.end()){
      minuten = *it;
      ++it;
    } else {
      minuten = 0;
    }
    if(it != liste.end()){
      sekunden = *it;
      ++it;
    } else {
      sekunden = 0;
    }
    checkAttributes();   
  }
  ~Uhr();
};

// Ueberladen des Ausgabe-Operators als freie Funktion
// std::ostream& operator<<(std::ostream& os, const Uhr& u);

// Verletzung der One Definition rule ohne inline
// Trick inline 
inline std::ostream& operator<<(std::ostream& os, const Uhr& u) {
  u.output(os);
 return os;
  
}

#endif // UHR_H
