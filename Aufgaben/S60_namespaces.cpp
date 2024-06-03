#include <iostream>
using std::cout;
using std::endl;
int i = 100;
namespace A {
    int i = 13;
    void print(){
        cout << "in A\n";
    }
    namespace B {
        int i = 42;
        void print() {
            cout << "in B\n";
        }
    }
}

int S60_namespaces(){
    cout << i << endl;
    int i = 1000;
    cout << i << endl << ::i << endl;
    {
        int i = 999;
        cout << i << endl;
        cout << A::i << endl;
        cout << A::B::i << endl;
    }
    A::print();
    A::B::print();
    return 0;
}
