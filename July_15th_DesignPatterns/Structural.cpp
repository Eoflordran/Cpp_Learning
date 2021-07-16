#include"Structural.hpp"


/*************** Adapter example ***************/
void ITarget::MethodA()
{
    std::cout << "incompatible method\n";
}

void Adaptee::MethodB()
{
    std::cout << "MethodB called\n";
}


void Adapter::MethodA() 
{
    _adaptee.MethodB();
}

Client::Client(ITarget* target)
{
    _target = target;
}

Client::Client(std::shared_ptr<ITarget> target)
{
    std::cout << "hey this constructor also works\n";
    sharedTarget = target;
}

void Client::MakeRequest()
{
    //_target.MethodA();
    //_target->MethodA();
    sharedTarget->MethodA();
}

/*************** Adapter example ***************/


/*************** Bridge example ***************/
void ImplementationBase::OperationImplementation()
{
    // nothing, this is a pseudo interface   
}

void ConcreteImplementation1::OperationImplementation()
{
    std::cout << "Concrete implemenation #1\n";
}

void ConcreteImplementation2::OperationImplementation()
{
    std::cout << "Concrete implemenation #2\n";
}

Abstraction::Abstraction(std::shared_ptr<ImplementationBase> X)
{
    implementer = X;
}

void Abstraction::Operation()
{
    std::cout << "ImplementationBase:Operation\n";
    implementer->OperationImplementation();
}

void RefinedAbstraction::Operation()
{
    std::cout << "Refined Abstraction, ImplentationBase::Operation\n";
    implementer->OperationImplementation();
}
/*************** Bridge example ***************/