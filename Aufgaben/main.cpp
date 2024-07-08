#include "main.h"
#include <iostream>
<<<<<<< HEAD
#include <iomanip>
#include <cstdlib>
#include <math.h>

using std::endl;
using std::cout;
=======
#include "S77_Aufgabe_iomanip.cpp"
>>>>>>> 581e70de9343035ad50ec9a60de6d8f27fcc1f73
int main(){
    //S65_ein_ausgabe();
    //S60_namespaces();
    //S70_format_flags();
    //S75_format_manipulatoren();
<<<<<<< HEAD
    //S77_Aufgabe_iomanip();
    //S78_param_swaP();
    //S87_bsp_new();
    //S101_dynamische_Felder_new_delete();
    //S105_dynamische_Felder_malloc();
    //S105_Pascal_Dreieck(10);
    //S109_funktionszeiger();
    //S109_funktionszeiger_trapez();


    /*int ival1 = 10;
    int ival2 = 20;
    int* iPtr = &ival1;
    int*& refPtr = iPtr;
    int i= -1;

    */

=======
    S77_Aufgabe_iomanip();
    return 0;
}

using std::cout;
using std::endl;
/*
void swapP(int &x, int &y){ //Falls keine Adressen verwendet.
    int hilf = x;           //Werden einfach nur lokale Kopien erzeugt
    x = y;                  //und der Tausch der Werte funktioniert nicht
    y = hilf;
}
int main(){
    int i = 5, j = 8;
    swapP(i, j);
    cout << "i = " << i << ", j = " << j << endl;
>>>>>>> 581e70de9343035ad50ec9a60de6d8f27fcc1f73
    return 0;
}*/


/*
int S87_bsp_new(){
    int* ip1 = new int;
    int* ip2 = new int(42);
    int* ip3 = new int{4711};

    std::cout << *ip1 << std::endl
         << *ip2 << std::endl
         << *ip3 << std::endl;

    struct Complex{
        double re, im;
    } z1 = {1.0, 2.0};

    Complex* pc1 = new Complex( z1 );
    Complex* pc2 = new Complex{ z1 };

    std::cout << (*pc1).re << ", " << pc1->im << std::endl;
    std::cout << (*pc2).re << ", " << pc2->im << std::endl;

    delete ip1; ip1 = nullptr;
    delete ip1; // unschaedlich
    delete ip2; ip2 = nullptr;
    delete ip3; ip3 = nullptr;
    delete pc1; pc1 = nullptr;
    delete pc2; pc2 = nullptr;

    int a=3;
    int* ap=new int(8);
    std::cout << "Hello World No." << *ap << std::endl;
    std::cout << "int " << sizeof(a) << std::endl;
    std::cout << "long" << sizeof(long) << std::endl;
    std::cout << sizeof(long *) << std::endl;

    delete ap; ap = nullptr;

    return 0;
}

int S101_dynamische_Felder_new_delete(){
    // Allokation eines Vektors
    constexpr int N = 3;
    double* pvec = new double[N]{1.0, 2.0, 3.0};
    for( int i = 0; i < N; ++i){
        std::cout << pvec[i] << std::endl; // Alternative fuer pvec[i]?
    }
    // Loeschen:
    delete[] pvec;
    pvec = nullptr;
    // Allokation einer NxN Matrix:
    // wobei N zur Kompilezeit bekannt ist
    // double** mat = new double[N][N]; // Syntax Fehler!!!!
    // Statt dessen:
    // mat ist ein Pointer auf ein
    // Feld mit N Elementen
    // welche der beiden Anzahlen in double[N][N]
    // kann durch eine andere Konstante ersetzt werden?
    double (*mat)[N] = new double[N][N];
    int k = 1;
    for( int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            mat[i][j] = k++;
        }
    }
    for( int i = 0; i < N; ++i){
        for( int j = 0; j < N; ++j){
            std::cout << std::setw(12) << std::setprecision(2)
                 << mat[i][j]; // Alternative fuer mat[i][j]?
        }
        std::cout << std::endl;
    }
    delete[] mat; mat = nullptr;

    // Anlegen einer mxn Matrix
    // m, n werden eingelesen
    int m, n;
    std::cout << "Eingabe m und n: ";
    std::cin >> m >> n;
    std::cout << m << ", " << n << std::endl;
    // Anlegen eines Feldes mit m Pointern auf double
    double** mat2 = new double*[m];
    // Anlegen der Zeilenvektoren und fuellen
    k = 1;
    for(int i = 0; i < m; ++i){
        mat2[i] = new double[n];
        for(int j = 0; j < n; ++j) {
            mat2[i][j] = k++;
        }
    }
    for( int i = 0; i < m; ++i){
        for( int j = 0; j < n; ++j){
            std::cout << std::setw(12) << std::setprecision(2)
                 << mat2[i][j];
        }
        std::cout << std::endl;
    }
    // Speicher freigeben in umgekehrter Reihenfolge
    // Loeschen der Zeilen-Vektoren
    for(int i = 0; i < m; ++i) {
        delete[] mat2[i]; mat2[i] = nullptr;
    }
    // Loeschen des Feldes mit den Pointer-Elementen
    delete[] mat2; mat2 = nullptr;

    return 0;
}

int S105_dynamische_Felder_malloc(){
    // nxn Matrix
    int n = 4;
    double** mat = (double**) malloc(n * sizeof(double*));
    int k = 1;
    for(int i = 0; i < n; ++i) {
        mat[i] = (double*) malloc(n * sizeof(double));
        for(int j = 0; j < n; ++j) {
            mat[i][j] = k++;
        }
    }
    // Ausgabe
    for( int i = 0; i < n; ++i){
        for( int j = 0; j < n; ++j){
            std::cout << std::setw(12) << std::setprecision(2)
                 << mat[i][j];
        }
        std::cout << std::endl;
    }
    // Speicher freigeben:
    for(int i = 0; i < n; ++i) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
*/























