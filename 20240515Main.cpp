//------------------------------------------------------------------
// 20240515Main.cpp
// Copyright 15.05.2024
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <stdexcept>   // fuer die Standardt-C++-Exceptions

using std::cout;
using std::endl;

class Punkt3D {
 private:
  static const size_t DIM;
  double* koord;
  
 public:
  Punkt3D(double x, double y, double z)
      : koord{new double[DIM]{x, y, z}} {}
  
  // extra konvertierenden Konstruktor (ohne explicit) damit
  // gemischte arithmetik moeglich ist
  Punkt3D(double wert) : koord{new double[DIM]{wert, wert, wert}} {}
  
  void output(std::ostream& os) const {
    os << "(";
    for(size_t i = 0; i < DIM; ++i){
      if ( i > 0) {
        os << ", ";
      }
      os << koord[i];
    }
    os << ")";
  }
  
  // Indizierungs-Operator als L-Wert
  double& operator[](size_t i) {
    if (i < DIM) {
      return koord[i];
    } else {
      throw std::out_of_range("Falscher Index");
    }
  }
  
  // Indizierungs-Operator als R-Wert
  // Unterschied in der Signatur durch const
  const double& operator[](size_t i) const {
    cout << "R-wert von []" << endl;
    if (i < DIM) {
      return koord[i];
    } else {
      throw std::out_of_range("Falscher Index");
    }
  }
  
  // Insitu Addition
  Punkt3D& operator+=(const Punkt3D& a) {
    for(size_t i = 0; i < DIM; ++i){
      koord[i] += a[i];
    }
    return *this;
  }
  
  // Inkrement Operator
  // Praefix-Form
  Punkt3D& operator++() {
    for(size_t i = 0; i < DIM; ++i){
      ++koord[i];
    }
    return *this;
  }
  
  // Postfix-Form
  // Unterschied in der Signatur durch dummy Parameter
  Punkt3D operator++(int dummy) {
    Punkt3D tmp{*this};
    ++*this;
    return tmp;
  }
  
    
  // Big Three
  ~Punkt3D() {
    delete [] koord;
    koord = nullptr;
  }
  // Copy Konstruktor
  Punkt3D(const Punkt3D& rhs)
      // : koord{new double[DIM]{rhs.koord[0], rhs.koord[1], rhs.koord[2]}} {}
      // einfacher mit der Verwendung des ueberladenen Indizierungs-Operators
      : koord{new double[DIM]{rhs[0], rhs[1], rhs[2]}} {}
  
  // Copy Zuweisungs-Operator
  Punkt3D& operator=(const Punkt3D& rhs) {
    
    // Test auf nicht Selbstzuweisung
    if (this != &rhs) {
      // delete ist eigentlich hier nicht notwendig,
      // im Allgemeinen aber doch, da sich die Groesse aendern kann
      // siehe Aufgabe Klasse Vec Skript S. 227 (@HOME)
      delete [] koord;
      koord = new double[DIM];
      for(size_t i = 0; i < DIM; ++i){
        koord[i] = rhs[i]; // koord[i] = rhs.kood[i];
      }
      
    }
    return *this;
  }
  
  // Move Semantik (temporaeren Objekten wird Heap-Speicher gestohlen)
  // Move Konstruktor
  Punkt3D(Punkt3D&& rhs)
      : koord{rhs.koord} {
    cout << "Move-Konstruktor" << endl;
    rhs.koord = nullptr;
  }
  
  // Move Zuweisung
  Punkt3D& operator=(Punkt3D&& rhs) {
    cout << "Move-Zuweisung" << endl;
    if (this != &rhs) {
      delete [] koord;
      koord = rhs.koord;
      rhs.koord = nullptr;
    }
    return *this;
  }
  
  
};

// vor C++11 Initialisierung
// einer statische (Klassen) Variablen in cpp-Datei
const size_t Punkt3D::DIM = 3;

// Ueberladung des Ausgabe-Operators als freie Funktion
inline std::ostream& operator<<(std::ostream& os, const Punkt3D& p) {
  p.output(os);
  return os;
}

// Ueberladung der binaeren Addition als freie Funktion
inline Punkt3D operator+(const Punkt3D& a, const Punkt3D& b) {
  Punkt3D erg{a};
  erg += b;
  return erg;
}


int main()
{
  Punkt3D p1 = 3.14;
  cout << p1 << endl;
  
  Punkt3D p2{1, 2, 3};
  cout << p2 << endl;
  
  cout << "y-Koordinate von p2: " << p2[1] << endl;
  p1[0] = 99;
  cout << "p1 = " << p1 << endl;
  
  // R-Wert Version wird nur fuer const Objekte verwendet
  const Punkt3D p3{7, 8, 9};
  cout << "y-Koordinate von p3: " << p3[1] << endl;
  
  // Kopieren und Verschieben
  // Copy-Konstruktor
  // Punkt3D p4 = p2;
  Punkt3D p4{p2};
  cout << "p4 = " << p4 << endl;
  
  // Copy Zuweisung;
  Punkt3D p5{0,0,0};
  p5 = p2;
  // Selbstzuweisung p2 = p2;
  
  p2[2] = 42.0;
  cout << "p4 = " << p4 << endl;
  cout << "p5 = " << p5 << endl;
  cout << p2 << endl;
  
  // Move-Zuweisung
  p5 = p1 + p2;
  cout << "p5 = " << p5 << endl;
  
  Punkt3D i = 4;
  cout << ++i << i++ << i << endl;
  
  // durch std::move() wird in eine R-Wert-Referenz gekastet und daurch
  // das Move erzwungen anstelle der copy elison Oprimierung des Compilers
  Punkt3D p6{std::move(p1+p2)};
  cout << "p6 = " << p6 << endl;

  return 0;
}
