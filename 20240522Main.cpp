//------------------------------------------------------------------
// 20240522Main.cpp
// Copyright 22.05.2024
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <complex>
#include <stdexcept>
#include <vector>
#include <string>

using std::complex;
using std::cout;
using std::endl;

/*
// Composite Pattern
class IZweipol {
 public:
  virtual complex<double> widerstand(double omega) const = 0;
  virtual ~IZweipol() {}
  
};

class R : public IZweipol {
 private:
  double r;
 public:
  explicit R(double rInOhm) : r{rInOhm} {}
  complex<double> widerstand(double omega) const override {
    return complex<double>{r, 0 * omega};
  }
  
};

class L : public IZweipol {
 private:
  double l;
 public:
  explicit L(double lInHenry) : l{lInHenry} {}
  complex<double> widerstand(double omega) const override {
    return complex<double>{0, l * omega};
  }
  
};

class C : public IZweipol {
 private:
  double c;
 public:
  explicit C(double cInFarad) : c{cInFarad} {}
  complex<double> widerstand(double omega) const override {
    return complex<double>{0, -1./(c * omega)};
  }
  
};

class Schaltung : public IZweipol {
 private:
  IZweipol* elemente[2]{nullptr, nullptr};
  void checkIndex(int index) const {
    if (index < 0 || index > 1) {
      throw std::out_of_range("ungueltiger Index");
    }
    
  }
 protected:
  void checkChildren() const {
    if (elemente[0] == nullptr || elemente[1] == nullptr) {
      throw std::logic_error("Kind ist nullptr");
    }
  }
  
 public:
  void add(IZweipol* e, int index) {
    checkIndex(index);
    elemente[index] = e;
  }
  
  void remove(int index) {
    checkIndex(index);
    elemente[index] = nullptr;
  }
  
  IZweipol* getChild(int index) const {
    checkIndex(index);
    return elemente[index];
  }
  
  ~Schaltung() {
    elemente[0] = nullptr;
    elemente[1] = nullptr;
  }
};

class SerSchaltung : public Schaltung {
 public:
  complex<double> widerstand(double omega) const override {
    checkChildren();
    return getChild(0)->widerstand(omega) + getChild(1)->widerstand(omega);
  }
};

class ParSchaltung : public Schaltung {
 public:
  complex<double> widerstand(double omega) const override {
    checkChildren();
    complex<double> z0 = getChild(0)->widerstand(omega);
    complex<double> z1 = getChild(1)->widerstand(omega);
    
    return z0 * z1 /(z0 + z1);
  }
};
*/

// Observer Pattern
class IObserver {
 public:
  virtual void update(double preis) = 0;
  virtual ~IObserver() {}
};

class Publisher {
 private:
  std::vector<IObserver*> myObs;
 public:
  void anmelden(IObserver* o) {
    myObs.push_back(o);
  }
  
  void abmelden(IObserver* o) {
    // std::vector hat kein remove, sonder nur ein erase,
    // diese Methode benoetigt eine Iterator-Position
    auto it = myObs.begin();
    while(it != myObs.end()) {
      if(*it == o) {
        myObs.erase(it);
        break;
      }
      ++it;
    }
  }
  
  void notify(double preis) const {
    for(auto e: myObs){
      e->update(preis);
    }
    // @HOME anstelle der bereichsbasierten Schleife
    //       einen Iterator verwenden 
  }
  
};

class DieselTanke: public Publisher {
 private:
  double preis;
 public:
  void setPreis(double p) {
    preis = p;
    notify(preis);
  }
};

class Bauer : public IObserver {
 private:
  std::string name;
  DieselTanke* meineTanke;
  double preiseAlt[2]{0.0, 0.0};
  int nPreise;
 public:
  Bauer(const std::string& n, DieselTanke* dt)
      : name{n}, meineTanke{dt}, nPreise{0} {
    meineTanke->anmelden(this);
    
  }
  ~Bauer() {
    meineTanke->abmelden(this);
  }
  
  void update(double preis) override {
    switch(nPreise) {
      case 0:
        preiseAlt[0] = preis;
        ++nPreise;
        break;
      case 1:
        preiseAlt[1] = preis;
        ++nPreise;
        break;
      default:
        if(preis < preiseAlt[1] && preiseAlt[1] < preiseAlt[0]){
          cout << "Bauer " << name << " tankt voll" << endl;
        }
        preiseAlt[0] = preiseAlt[1];
        preiseAlt[1] = preis;
        break;
    }
  }
};

// @HOME Klasse Privatkunde erstellen



int main()
{
  DieselTanke dt;
  
  // Bauer auf Heap
  Bauer* pb = new Bauer{"Xaver", &dt};
  
  
  // Loeschen
  delete pb;
  pb = nullptr;
  
  // @HOME:
  // 1) Auf Stack Privatekunde und Bauer Objekt erstellen
  // 2) Auf Heap  Privatekunde und Bauer Objekt erstellen
  // 3) Preise veraendern und Ausgabe ueberpreufen
  // 4) Objekte auf Heap loeschen
  // 5) Preise veraendern und Ausgabe ueberpreufen
  
  
  /*
  R r1{50}, r2{300}, r3{20};
  L l1{1}, l2{1.5};
  C c1{10E-6};
  SerSchaltung s1, s2, s3, s4;
  s1.add(&r3, 0);
  s1.add(&l2, 1);
  
  s2.add(&r2, 0);
  s2.add(&c1, 1);
  
  s3.add(&r1, 0);
  s3.add(&l1, 1);
  
  ParSchaltung p1;
  p1.add(&s1, 0);
  p1.add(&s2, 1);
  
  s4.add(&s3, 0);
  s4.add(&p1, 1);
  
  cout << "Gesampt-Impedanz = " << s4.widerstand(300) << endl;
  */
  
  
  
  
  
  
  
  
  
  
  return 0;
}
