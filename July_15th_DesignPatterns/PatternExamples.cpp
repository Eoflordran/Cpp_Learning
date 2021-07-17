#include"PatternExamples.hpp"
/*Creational Examples*/


/*Behavioural Examples*/


/*Structural Examples*/


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

void bridgeExample()
{
    std::cout << "bridge example!\n";
    
    std::cout << "\n";
    
    std::shared_ptr<ConcreteImplementation1> C1 = std::make_shared<ConcreteImplementation1>();
    std::shared_ptr<ConcreteImplementation2> C2 = std::make_shared<ConcreteImplementation2>();

    std::unique_ptr<Abstraction> A1(new Abstraction(C1));
    std::unique_ptr<Abstraction> A2(new Abstraction(C2));

    A1->Operation();
    A2->Operation();

    std::cout << "\n";

    std::unique_ptr<RefinedAbstraction> RA(new RefinedAbstraction(C1));
    std::unique_ptr<RefinedAbstraction> RA2(new RefinedAbstraction(C2));
    RA->Operation();
    RA2->Operation();

}

void compositeExample()
{
    std::cout << "hello from the composite example!\n";
    
}