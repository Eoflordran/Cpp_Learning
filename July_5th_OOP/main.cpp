
#include "Date.hpp"
#include <iostream>

class X 
{
    private:
        int m;
    public:
        X(int i = 0) : m{i} {}

        int mf(int i)
        {
            int old = m;
            m = i;
            return old;
        }
};

void u(X var, X* ptr);
void PrintName(Entity* entity);
void FunctionA(int& x);
void FunctionB(int* x);

int main()
{
    //int i{20};
    //std::cout << i << " this is the integer initialized with {}" << std::endl;
    /*
    X var{6};
    //std::cout << var.mf(8) << std::endl;

    X vex;
    //std::cout << vex.mf(8) << std::endl;

    u(var, &vex);
    */

   // cherno's virtual functions tutorial

   Entity* e = new Entity();
   PrintName(e);

   Player* p = new Player("Eric");

   //Player testy = Player("testy");// this works, will have to look into why
                                    // they don't want to use "new" as a keyword 
                                    // at concord

   PrintName(p);

   int i{3};

   FunctionB(&i);
   std::cout << i << std::endl;

   FunctionA(i);
   std::cout << i << std::endl;
   
   Date d1{15,6,2020};
   d1.Print();

   Date d2 = Date{16,};
   d2.Print();

}
/*                  END OF MAIN                  */ 




void u(X var, X* ptr)
{
    std::cout << "object version: " << var.mf(8) << std::endl;
    std::cout << "pointer version: " << ptr->mf(8) << std::endl;
}

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

void FunctionA(int& x)
{
    x++;
}

void FunctionB(int* x)
{
    //*x++;
    //*x = *x + 1;
    (*x)++;
    std::cout << "inside B the value is : " << *x << std::endl;
}