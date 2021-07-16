#include<iostream>
#include<memory>

#include"Creational.hpp"
#include"Behavioural.hpp"
#include"Structural.hpp"

/*Creational Examples*/
/*Behavioural Examples*/
/*Structural Examples*/

void adapterExample();

int main()
{
    adapterExample();

}


void adapterExample()
{
    //std::shared_ptr<Adapter> uP;
    std::shared_ptr<Adapter> aP = std::make_shared<Adapter>();
    Adapter X;
    Adapter* Y = new Adapter();
    //Client A(Y);
    Client AA(aP);
    AA.MakeRequest();
} 