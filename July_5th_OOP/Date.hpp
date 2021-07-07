#include <iostream>
#include <string>

class Example 
{
    public:
        Example()
        {
            std::cout << "Created Entity!" << std::endl;
        }

        Example(int x)
        {
            std::cout << "Created Entity with" << x << std::endl;
        }
};

class Entity
{
    private:
    //Example m_Example; // uncomment for initializer list example
    public:
    /*
        Entity () //: m_Example(19)
        {
            m_Example = Example(30);
        }
    */ // example of why initializer lists are good to use
        virtual std::string GetName() { return "Entity"; }
    
};

class Player : public Entity
{
    private:
        std::string m_Name;
    public:
        Player(const std::string& name) : m_Name(name) {}

        std::string GetName() override { return m_Name; }
};