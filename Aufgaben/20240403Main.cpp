//------------------------------------------------------------------
// 20240403Main.cpp
// Copyright 02.04.2024
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;


// 2-ter Integrand
double f(double x) {
  double y = std::sqrt(x) / (1 + 2*x);
  return y;
}     
// 1) Trapezregel
double trapez(double (*f)(double), double a, double b, int n) {
  double h = (b-a)/n;
  double erg = 0.0;
  for(int j = 1; j < n; ++j){
    erg += f(a + j*h);
  }
  erg = h/2 * (f(a) + f(b) + 2*erg);
  return erg;
}

// Typ-Deklaration TFP mit using
using TFP = double (*)(double);

double cube(double x){
  return x*x*x;
}
int main()
{
  
  //-------------------------------------------------------------------
  // 1) Numerische Integration mit Funktionspointern
  //    Skript S. 109
  //cout << "Integral ueber sin: " << trapez(sin, 1, 2, 100) << endl;
  //cout << "Integral ueber f: " << trapez(f, 1, 2, 100) << endl;
  
  //    Anlegen Feld vfp von Funktionspointern auf Stack
  //    Initialisieren mit sin, cos, exp, log
  constexpr int N = 4;
  double (*vfp[N])(double) = {sin, cos, exp, log};
  // vereinfachen mit Typen-Deklaration
  //TFP vfp[N] =  {sin, cos, exp, log};
  cout << vfp[2](1.0) << endl;
  
  // for (int i = 0; i < 4; ++i) {
  //  cout << "Integranl Nr. " << i << " = " << trapez(vpf[i], 1, 2, 100) << endl;
  //}
  
  // Anlegen Feld pfp von Funktionspointern auf Heap
  // Initialisieren mit sin, cos, exp, log
  //double (**pfp)(double) = new (double (*[4])(double)){sin, cos, exp, log};
  // Vereinfachen mit Typen-Deklaration
  TFP* pfp = new TFP[4]{sin, cos, exp, log};
  cout << pfp[2](1.0) << endl;
    
 
    
  for (int i = 0; i < 4; ++i) {
    cout << "Integra Nr. " << i << " = " << trapez(pfp[i], 1, 2, 100) << endl;
  }
  
  // delete !!!
  delete[] pfp;
  pfp = nullptr;
  
  //-------------------------------------------------------------------
  // 2) Durchlaufen von Containern
  /*
  // I) auch C-Array
  double v[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
  //    a) mit Pointern pIt, PEnd
  double* pIt = v;
  double* pEnd = v + 5;
  while (pIt != pEnd){
    cout << *pIt << endl;
    ++pIt;
  }
  //    b) mit Iterator
  auto aIt = std::begin(v);
  while (aIt != std::end(v)) {
    cout << *aIt << endl;
    ++aIt;
  }
  
  //    c) bereichsbasierte Schleife lesend
  for(auto e: v){
    cout << e << endl;
  }
  
  
  //    d) bereichsbasierte Schleife schreibend
  //       neue Befuellung mit den Quadraten
  for(auto& e: v){
    e = e*e;
  }
  for(auto e: v){
    cout << e << endl;
  }
  */
  //const int ci = 5;
  //const auto& x = ci;
  //++x;
  //cout << x << endl;
  
  // II) gleiches funktioniert mit den Containern der STL
  // z. B. vector
  //std::vector<double> vec = {1.2, 2.3, 3.4, 4.5, 5.6};
  //cout << vec.size() << " , " << vec.capacity() << endl;
  
  // a) Mit Iterator durchlaufen
  // std::vector<double>::iterator it = vec.begin();
  // Hier hilft auto sehr!
  //auto it = vec.begin();
  //while (it != vec.end()){
  //  cout << *it << endl;
  //  ++it;
  //}
  //for(auto it = vec.begin(); it != vec.end(); ++it){
  //  cout << *it << endl;
  //}
  
  // b) Bereichsbasierte Schleife lesend
  //for(double e: vec){
  //for(auto e: vec){
  //  cout << e << endl;
  //}
  // c) Bereichsbasierte Schleife schreibend mit Kuben befuellen
  //for(auto& e: vec){
  //  e = e*e*e;
  //}
  
  // Alternative: Algorithmus transform aus der STL
  // Verwendet Anfangs und End Iterator fuer Bereich der
  // Elemente, fuer die der unaere Operator (Funktion mit 1 Parameter)
  // aufgerufen wird und den Anfangs-Iterator fuer den Ausgabe-Container
  // Durch die hier vorgenommen Wahl sind Eingabe-Container und Ausgabe-Container
  // gleich
  // @HOME: so veraendern, dass Ergebnisse in einen neuen Container geschrieben
  //        werden, danach die Ergebnisse mit Iterator und mit bereichsbasierter
  //        Schleife ausgeben.
  //std::transform(vec.begin(), vec.end(), vec.begin(), cube);
  //for(auto e: vec){
  //  cout << e << endl;
  //}
  
  //-------------------------------------------------------------------
  // 3) Erstellung der Klasse Uhr
   
  
  return 0;
}
