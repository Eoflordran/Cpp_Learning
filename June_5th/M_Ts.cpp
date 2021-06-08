#include <iostream>
#include <thread>
#include <string>
void doSomeWork();


class Entity
{
    public:
        std::string myName;
        Entity(std::string x)
        {
            printf("Hey the constructor was called!\n");
            myName = x;
        }
        void Print()
        {
            
            std::cout << myName << std::endl;
            std::cout << myName[0] << std::endl;
            std::cout << sizeof(myName) << std::endl;
            
            std::cout << sizeof(int) << std::endl;
            std::cout << sizeof(std::string) << std::endl;
        }
};

class background_task
{
    public:
        int X, Y;

        background_task(int x, int y)
        {
            X = x;
            Y = y;
        }
        void operator()() const
        {
            printf("Hey neat this is called first\n");
            printf("X:%d, Y:%d\n", X, Y);
        }
};

int main(){

    /*This is some prototyping methods for my class*/
    /*
    Entity eric("My name is eric");
    eric.Print();
    */

   /*an example of using a constructor then using a function operator, */
    background_task f(3,5);
    //f();
    std::thread t(f);
    t.join();
    
    /*This is a way of spawning and terminating multiple threads*/ 
    /* 
    std::thread t[10];
    for(int i = 0; i<10 ; i++){
        t[i] = std::thread(hello,i);
    }
    
    for(int i = 0 ; i<10 ; i++){
        t[i].join();
    }
    */
}