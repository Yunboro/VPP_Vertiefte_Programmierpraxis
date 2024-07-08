#include <cmath>
#include <iostream>
#include <main.h>

double trapez(double (*f)(double), double a, double b, int n){
    double ret = 0;
    double sum = 0;
    if(n>0){
        double h = (b-a)/n;
        for(int j = 1; j<n; ++j){
            sum += f(a+j*h);
        }
        ret = 0.5*h* (f(a)+f(b)+2*sum);
    }
    return ret;
}

double argA(double x){
    return sin(x);
}

double argB(double x){
    return sqrt(x)/(1+2*x);
}

int add(int x, int y){
    return x+y;
}

int mult(int x, int y){
    return x*y;
}

void S109_funktionszeiger(){
    int (*op)(int, int);
    op = add; // oder: op = &add;
    std::cout << op(3,4) << std::endl; // Aufruf add
    op = mult;
    std::cout << op(3,4) << std::endl; // Aufruf mult
}

void S109_funktionszeiger_trapez(){
    std::cout << trapez(argA, 1, 2, 15) << std::endl;
    std::cout << trapez(argB, 1, 2, 15) << std::endl;
    /*
    constexpr int n = 15;
    double res1[n-1], res2[n-1];
    for (int i = 0; i < n-1; ++i) {
        res1[i] = trapez([](double x){ return std::sin(x);}, 1, 2, i+1);
        res2[i] = trapez([](double x){ return std::sqrt(x) / (1 + 2*x);}, 1, 2, i+1);
    }

    std::cout << "Integral 1:" << std::endl;
    for(const auto& res : res1)
        std::cout << res << std::endl;

    std::cout << "\n\n Integral 2:" << std::endl;
    for(const auto& res : res2)
        std::cout << res << std::endl;
    */
}
