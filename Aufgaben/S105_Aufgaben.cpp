#include <iostream>
//#include <main.h>
//S105_Aufgaben

void tuWas(int i) {
    int* ptr = new int(i);
    std::cout << *ptr * *ptr << std::endl;
    delete ptr; ptr = nullptr;
}


int mmain(){

int i = 42;
    int* ip = new int;
    *ip = i;
    std::cout << *ip << std::endl;
    delete ip; ip= nullptr;
    return 0;

char c = 'A';
    char* cp = &c;
    std::cout << *cp << std::endl;
    //delete cp;
    cp = nullptr;
    std::cout << c << std::endl;

double* pd = new double{13};
    std::cout << *pd << std::endl;
    delete pd; pd = nullptr;
    pd = new double(14);
    std::cout << *pd << std::endl;
    delete pd; pd = nullptr;

//S_105_Aufgaben

for( int i = 1; i < 10; ++i ) {
    tuWas( i );
    }
}
