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
    std::shared_ptr<Composite> bob(new Composite("bob"));
    
    std::shared_ptr<Composite> steve(new Composite("steve"));
    std::shared_ptr<Composite> jake(new Composite("jake"));
    std::shared_ptr<Composite> andy(new Composite("andy"));
    bob->AddChild(steve);
    bob->AddChild(jake);
    bob->AddChild(andy);
    std::cout << bob->GetChild(0)->getName() << std::endl;
    bob->Operation();

    std::cout << "adding subordinates to steve...\n";
    std::shared_ptr<Leaf> geoff(new Leaf("geoff"));
    std::shared_ptr<Leaf> george(new Leaf("george"));
    std::shared_ptr<Leaf> jer(new Leaf("jer"));
    std::shared_ptr<Leaf> gem(new Leaf("gem"));

    steve->AddChild(geoff);
    steve->AddChild(george);
    steve->AddChild(jer);
    steve->AddChild(gem);

    bob->RemoveChild(steve);
    std::cout << bob->GetChild(0)->getName() << std::endl;
    steve->Operation();

    bob->Operation();
}

void decoratorExample()
{
    std::cout << "hello from decorator example!\n";

    /* Not much to say about this one, decorator objects can
    be used to act as/alter the fucntionality of an existing
    objet, by wrapping themselves around an object; being able
    to override all of the other object's methods. For instance
    if there was an object that handled how to communicate on a
    particular kind of socket, this method could be used to wrap
    that class and send the same kind of information on a different
    kind of socket or protocol*/
}