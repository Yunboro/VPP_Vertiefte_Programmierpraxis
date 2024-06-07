#include <main.h>
#include <iostream>

/*int main(){
    //S65_ein_ausgabe();
    //S60_namespaces();
    //S70_format_flags();
    //S75_format_manipulatoren();
    //S77_Aufgabe_iomanip();
    return 0;
}*/

using std::cout;
using std::endl;

void swapP(int &x, int &y){ //Falls keine Adressen verwendet.
    int hilf = x;           //Werden einfach nur lokale Kopien erzeugt
    x = y;                  //und der Tausch der Werte funktioniert nicht
    y = hilf;
}
int main(){
    int i = 5, j = 8;
    swapF(i, j);
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
