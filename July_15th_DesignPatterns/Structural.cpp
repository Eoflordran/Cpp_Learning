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



/*************** Composite example ***************/

Component::Component(std::string x)
{
    m_Name = x;
}

std::string Component::getName()
{
    return m_Name;
}

void Composite::AddChild(std::shared_ptr<Component> child)
{
    //m_children.push_back(child);// a hashmap is better than a vector here
    m_children.push_back(child);
}


std::shared_ptr<Component> Composite::GetChild(int index)
{
    std::shared_ptr<Component> x;
    auto it = m_children.begin();

    while(it != m_children.end())
    {
        if(index == 0)
        {
            return *it;
        }
        std::advance(it,1);
        index--;
    }
    return x; /* this is an error, should look into how to return an error */
    //return m_children[index];
}

void Composite::RemoveChild(std::shared_ptr<Component> child)
{
    m_children.remove(child);
}

void Composite::Operation()
{
    std::cout << "Composite with " << m_children.size() << " children\n";
}



void Leaf::Operation()
{
    std::cout << "Leaf.";
}

/*************** Decorator example ***************/

void ConcreteComponent::Operation()
{
    std::cout<< "Component Operation\n";
}
void DecoratorBase::Operation()
{
    m_component.Operation();
}

void ConcreteDecorator::Operation()
{
    m_component.Operation();
    std::cout << "modified\n";
}