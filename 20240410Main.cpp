//------------------------------------------------------------------
// 20240410Main.cpp
// Copyright 10.04.2024
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include "uhr.h"

using std::cout;
using std::endl;

int main()
{
  // Aufruf der Klassen-Methode
  // cout << Uhr::getSDefault() << endl;
  
  // Objekte erstellen auf Stack
  
  // Mit Standard-Konstruktor, der vom Compiler erstellt wurde
  // Vorsicht: dieser initialisiert die Attribute nicht!!
  //Uhr u1;
  
  // Vosicht kein Aufruf des Standard-Kostruktors
  // sondern Deklartion einer Funktion! 
  // Uhr u1();
  
  // Ausweg: Braces
  Uhr u1{};
  u1.displayClock();
  
  // Konstruktor mit Parametern
  //Uhr u2(12, 31, 42);
  
  // Aufruf mit Braces:
  // Sequenz-Konstruktor
  Uhr u2{12, 31, 42};
  u2.displayClock();
  
  // Aufruf des Konstruktors mit Parametern
  Uhr u3(23, 59, 13);
  u3.displayClock();
  
  // implizite Konvertierung von int nach Uhr
  // wird durch explicit verboten
  //Uhr u3 = 12;
  //u3.displayClock();
  
  // Copy-Konstruktor, vom Compiler erstellt
  // Uhr u4 = u2;
  // Uhr u4(u2);
  // durch =delete wird das Kopieren verboten
  // Uhr u4{u2};
  // u4.displayClock();
  
  Uhr u5{13};
  u5.displayClock();
  
  cout << u5 << endl;
  
  // Objekte auf Heap erstellen
  Uhr* pu1 = new Uhr(13, 13, 13);
  
  cout << *pu1 << endl;
  
  delete pu1;
  pu1 = nullptr;
  
  return 0;
}
