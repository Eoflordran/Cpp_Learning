

#include<iostream>
//#include<math.h>
#include<cmath>
class RootFind
{
    protected:
        double m_principal, m_ret, m_periods, m_err, m_start; ;
    public:
        RootFind(){};
        RootFind(double prin, double ret, double per, double er_stop) 
                : m_principal(prin), m_ret(ret), m_periods(per), m_err(er_stop), m_start(0.01){};
        //~RootFind(){};
        virtual void method()
        {
            /* the general assumption is that a method 
            assumes it's function is going to return 0 for
            the desired result, and that is what the method
            is going to try and find, the x that produces 0,
            i.e. a traditional root.*/
        };

        virtual double function(double x)
        {
            /* the default function is y = x + 1
                return x + 1 because we want to solve for 0*/
            return (x + 1);
        };

};

class CompoundInterest : virtual public RootFind
{
    /* Return = Principal * (1 + interest_rate/compounds_per_period)^(periods/compounds_per_period)*/
    
    public:
        using RootFind::RootFind;
        double function(double x) override;
};

class Bisection : virtual public RootFind
{
 
    public:
        using RootFind::RootFind;
        void method() override;
};

class CompBi : public CompoundInterest, public Bisection
{
    public:
        //CompBi(double prin, double ret, double per, double er_stop) 
        //        : m_principal(prin), m_ret(ret), m_periods(per), m_err(er_stop), m_start(0.01){};
        using CompoundInterest::CompoundInterest;
        using CompoundInterest::function;
        using Bisection::method;
};