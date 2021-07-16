
#include<memory>
#include<iostream>


/*************** adapter design pattern ***************/
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
/*************** adapter design pattern ***************/

/*************** Bridge design pattern ***************/
/* The bridge pattern is used to separate the abstract elements
of a class from the implementation details, providing the means to replace
the implementation details without modifying the abstraction*/

/*************** Bridge design pattern ***************/