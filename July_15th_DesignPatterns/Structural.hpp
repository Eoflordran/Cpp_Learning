
#include<memory>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<iterator>

#ifndef STRUCTURAL_H
#define STRUCTURAL_H
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

/*************** Composite design pattern ***************/


class Component
{
    protected:
        std::string m_Name;
    public:
    /*if a virtual function isn't defined you'll get
    undefined reference to vtable, either has to be a 
    pure interface or it has to have empty definitions.
    They cannot just be prototypes.*/

        Component(std::string x);
        ~Component(){};
        virtual void Operation(){};
        std::string getName();
};

class Composite : public Component
{
    //std::vector<std::shared_ptr<Component>> m_children;
    //std::map<std::shared_ptr<Component>, std::string> m_children;
    
    std::list<std::shared_ptr<Component>> m_children;
    public:
    using Component::Component;
        void AddChild(std::shared_ptr<Component> child);
        void RemoveChild(std::shared_ptr<Component> child);
        std::shared_ptr<Component> GetChild(int index);
        void Operation() override;

};

class Leaf : public Component
{
    public:
        using Component::Component;
        void Operation() override;
};
/*************** Composite design pattern ***************/



/*************** Decorator design pattern ***************/
class ComponentBase
{
    public:
        ComponentBase(){};
        virtual void Operation(){};
};

class ConcreteComponent : ComponentBase
{
    public:
        void Operation() override;
};

class DecoratorBase : ComponentBase
{
    protected:
        ComponentBase m_component;
    public:
        DecoratorBase(ComponentBase x) : m_component(x) {};
        void Operation() override;
};

class ConcreteDecorator : DecoratorBase
{
    public:
        using DecoratorBase::DecoratorBase;
        void Operation() override;
};


/*************** Decorator design pattern ***************/


/*************** Flyweight design pattern ***************/


class FlyweightBase;
class FlyweightFactory;
class Tank;
class Soldier;
class Target;
/*
class Target
{
    public:
        FlyweightBase unitData;
        
};*/

class FlyweightBase
{
    public:
        FlyweightBase(){};
        virtual std::string getName(){return "";};
        virtual int firePower(){return 1;};
        virtual void fireAt(std::shared_ptr<Target> target);
};

class Target
{   
    
    public:
        std::shared_ptr<FlyweightBase> unitData;
        Target(std::shared_ptr<FlyweightBase> x) : unitData(x) {};
        
};

class FlyweightFactory
{
    /*
    probably better to implement this as a setting/getting type instead of an
    inheritance type, let the std::map handle the details of the factory
    instead of having the factory return polymorphic instances, but I'll leave
    this as is, since this was a good lesson on how to do such a thing. 
    */
    std::map<std::string, int> m_flyweights { {"tank", 1}, {"soldier",2}};
    public:
        std::shared_ptr<FlyweightBase> getFlyweight(std::string key);

};

class Tank : public FlyweightBase
{   
    std::string getName() override;
    int firePower() override;
    void fireAt(std::shared_ptr<Target> target) override;
};

class Soldier : public FlyweightBase
{
    std::string getName() override;
    int firePower() override;
    void fireAt(std::shared_ptr<Target> target) override;
};


/*************** Flyweight design pattern ***************/

#endif