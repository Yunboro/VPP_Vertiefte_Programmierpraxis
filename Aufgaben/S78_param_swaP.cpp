#include <iostream>

using std::cout;
using std::endl;

void swapP(int &x, int &y){ //Falls keine Adressen verwendet.
    int hilf = x;           //Werden einfach nur lokale Kopien erzeugt
    x = y;                  //und der Tausch der Werte funktioniert nicht
    y = hilf;
}
int S78_param_swaP(){
    int i = 5, j = 8;
    cout << "i = " << i << ", j = " << j << endl;
    swapP(i, j);
    cout << "i = " << i << ", j = " << j << endl;
    return 0;
}

/*int main(void) {
    int var1 = 42;
    int* ptr;           //Erstellen eines Pointers
    ptr = &var1;        //Weise Pointer zu Adresse von var1
    *ptr = 13;          //Dereferenziere: auf Inhalt zugreifen und 13 setzen, alter Wert wird überschrieben
    cout << "Wert von var1:" << var1 << endl;   //Gebe jetzigen Wert von var1 aus
    int var2 = 999;
    ptr = &var2;        //Weise Pointer zu Adresse von var2
    cout << "Wert von ptr:" << ptr << endl;     //Gebe Adresse von Pointer, Adresse eine Variable mit &-Operator
    cout << "Wert von *ptr:" << *ptr << endl;   //Gebe Inhalt von Pointer
    return 0;
}*/
