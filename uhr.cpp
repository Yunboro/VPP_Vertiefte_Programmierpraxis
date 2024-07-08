//------------------------------------------------------------------
// Uhr
// Copyright 10.04.2024
// Author: KJR
//------------------------------------------------------------------
#include "uhr.h"

// Defeiniton der Klassenvariablen
int Uhr::SDEFAULT = 42;

// Klassen-Methode
int Uhr::getSDefault() {
  // return Uhr::SDEFAULT;
  return SDEFAULT;
}

// nicht inline Methoden
void Uhr::displayClock() const{
  std::cout << stunden << ":"
            << minuten << ":"
            << sekunden << std::endl; 
}
void Uhr::output(std::ostream& os) const{
  os << stunden << ":"
     << minuten << ":"
     << sekunden << std::endl; 
}

void Uhr::tick() {
  ++sekunden;
  if (sekunden == 60){
    sekunden = 0;
    ++minuten;
    if (minuten == 60){
      minuten = 0;
      ++stunden;
      if (stunden == 24){
        stunden = 0;
      }
    }
  }
}
// Destruktor
Uhr::~Uhr()
{
  displayClock();
  std::cout << "Uhr Objekt stribt" << std::endl;
}
/*
std::ostream& operator<<(std::ostream& os, const Uhr& u) {
  u.output(os);
  return os;
  
}
*/
