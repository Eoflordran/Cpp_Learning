
#include "root.hpp"


double CompoundInterest::function(double x)
{
    //std::cout << m_principal << " " << m_ret << " " << m_periods << std::endl;
    return m_ret - m_principal * pow((1 + x), m_periods);
}

void Bisection::method()
{
    double a, b, c, hold;
    bool a_b;
    a = m_start;
    std::cout << "hello\n";
    if (function(a) < 0)
    {
        b = a + 0.05;
        while(function(b) < 0)
        {
            b -= 0.05;
            //std::cout << "hello\n";
        }
        a_b = true;
    }
    else
    {
        b = a - 0.05;
        while(function(b) > 0)
        {
            b += 0.05;
        }
        a_b = false;
    }

    //c = (a + b)/2;
    hold = 10;
    std::cout << a << " "<< b << " "<< c << std::endl;
    while(hold > m_err)
    {
        c = (a + b)/2;
        hold = function(c);
        
        if(hold > 0)
        {
            if(a_b){
                b = c;
            }else{
                a = c;
            }
        }else{
            if(a_b){
                a = c;
            }else{
                b = c;
            }
        }

        if(hold < 0) hold *= -1; // abs() seems to struggle with doubles.
    }
    //std::cout << hold << " " << m_err << std::endl;
    std::cout << "result is:" << c << std::endl;
}