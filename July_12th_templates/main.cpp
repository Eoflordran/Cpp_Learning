#include<iostream>
template<typename T>
T yeetFunc()
{

}

template<>
void yeetFunc()
{
    
}

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

struct Vector
{
    int x,y;
    Vector():x(0),y(0){}
    Vector(int xx, int yy): x(xx), y(yy){}
};

std::ostream& operator<<(std::ostream& stream, const Vector& other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    int x{29};
    float y{3.2};
    std::string hiThere = "greetings my dude";
    Vector z;
    
    Print(x);
    Print(y);
    Print(hiThere);
    Print(z);


}