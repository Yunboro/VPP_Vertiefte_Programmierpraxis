#include <iostream>
#include <iomanip>
int S105_Pascal_Dreieck(int n){
    //Enthält die Pointer zu jedem Eintrag des Arrays/Zeile des Dreiecks
    int** arrays = new int*[n];

    //Anlegen von Zeilenvektoren
    for(int i = 0; i < n; ++i){
        arrays[i] = new int[i+1];

        for(int j = 0; j < i+1; ++j){
            //Rand immer eins
            if(j == 0 | j == i){
                arrays[i][j] = 1;
            }
            else{
                arrays[i][j] = arrays[i-1][j-1]+arrays[i-1][j];
            }
        }
    }

    int row = 0;


    //Ausgabe des Dreiecks
    for(int i = 0; i < n; ++i){
        //if(i==0) {std::cout << (n-i)*2 << std::endl;}
        std::cout << std::setw((n-i)*2);

        for(int j = 0; j < i+1; ++j){
            //Eintrag auslesen
            std::cout << arrays[i][j] << std::setw(3) << "   ";
            row++;
        }
        //Neue Zeile
        std::cout << std::endl;
    }

    //Speicher freigeben in umgekehrter Reihenfolge
    //Loeschen der Zeilen-Vektoren
    for(int i = 0; i < n; ++i){
        delete[] arrays[i]; arrays[i] = nullptr;
    }

    //Loeschen der Spalten-Vektoren
    delete[] arrays; arrays = nullptr;

    return 0;
}
