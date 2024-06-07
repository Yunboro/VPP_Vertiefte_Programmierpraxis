#include <iostream>
#include <iomanip>

constexpr int N = 5;


int S77_Aufgabe_iomanip(){
    double nettopreise[5];
    double bruttopreise[5];
    const double mwst = 0.19;


    //Einlesen der Nettorpreise
    std::cout << "Gebe bis zu 5 Nettopreise ein" << std::endl;
    for (int i = 0; i < N; ++i){
        std::cout << "Nettopreis " << (i+1) << ":";
        std::cin >> nettopreise[i];
        bruttopreise[i] = nettopreise[i] * (1 + mwst);
    }

    //Ausgeben der Preise in Tabellenform
    std::cout << std::endl
              << std::left << std::setw(4) << "Nr."
              << std::right << std::setw(8) << "Netto"
              << std::right << std::setw(10) << "Brutto"
              << std::endl;

    for(int i = 0; i < N; ++i){
        std::cout << std::left << std::setw(4) << (i+1)
                  << std::right << std::setw(8) << std::fixed << std::setprecision(2) << nettopreise[i]
                  << std::right << std::setw(10) << std::fixed << std:: setprecision(2) << bruttopreise[i]
                  << std::endl;
    }

}
