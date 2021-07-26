#include<iostream>
#include "root.hpp"


int main()
{
    /*
    RootFind *x = new RootFind(10,50,10,0.01);

    CompoundInterest *xx = new CompoundInterest(10,50,10,0.01);

    Bisection *xxx = new Bisection(10,50,10,0.01);
    */
    CompBi *y = new CompBi(40.92,57.49,3,0.000001);

    //std::cout << y->function(0.1) << std::endl;
    y->method();
}