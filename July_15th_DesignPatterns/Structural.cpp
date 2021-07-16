#include"Structural.hpp"

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