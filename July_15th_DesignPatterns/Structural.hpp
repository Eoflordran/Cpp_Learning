
#include<memory>
#include<iostream>


/*************** Adapter design pattern ***************/
/* The adapter pattern is used to provide a link between two otherwise
incompatible types by wrapping the "adaptee" with a class that supports
the interface required by the client*/
class ITarget
{
    public:
        virtual void MethodA();
};

class Adaptee
{
    public:
        void MethodB();
};

class Adapter : public ITarget
{
    Adaptee _adaptee;
    public:
        void MethodA() override;
};

class Client
{
    private:
        ITarget* _target;
        std::shared_ptr<ITarget> sharedTarget;
    public:
        Client(ITarget* target);

        Client(std::shared_ptr<ITarget> target);

        void MakeRequest();
        
};
/*************** Adapter design pattern ***************/

/*************** Bridge design pattern ***************/
/* The bridge pattern is used to separate the abstract elements
of a class from the implementation details, providing the means to replace
the implementation details without modifying the abstraction*/

class ImplementationBase
{
    public:
        virtual void OperationImplementation();
};

class ConcreteImplementation1 : public ImplementationBase
{
    public:
        void OperationImplementation() override;
};

class ConcreteImplementation2 : public ImplementationBase
{
    public:
        void OperationImplementation() override;
};

class Abstraction
{
    public:
        std::shared_ptr<ImplementationBase> implementer;
        Abstraction(){};
        Abstraction(std::shared_ptr<ImplementationBase> X);
        virtual void Operation();
};

class RefinedAbstraction : public Abstraction
{
    public:
        using Abstraction::Abstraction;
        /*
        RefinedAbstraction(std::shared_ptr<ImplementationBase> X) 
        { // this only works if a default constructor is defined in Abstraction
            implementer = X;
        }*/
        void Operation() override;
};
/*************** Bridge design pattern ***************/