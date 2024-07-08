#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

// Definition der Funktion cube
double cube(double x) {
    return x * x * x;
}

int main()
{
    // Verwendung eines std::vector anstelle eines rohen Arrays
    std::vector<double> vec = {1.2, 2.3, 3.4, 4.5, 5.6};

    // Ausgabe von Größe und Kapazität des Vektors
    cout << vec.size() << " , " << vec.capacity() << endl;
    
    // Ausgabe der Elemente des Vektors
    for (auto e : vec) {
        cout << e << endl;
    }
    
    // Transformation der Elemente des Vektors
    std::transform(vec.begin(), vec.end(), vec.begin(), cube);
    cout << endl;
    // Ausgabe der transformierten Elemente des Vektors
    for (auto e : vec) {
        cout << e << endl;
    }

    return 0;
}
