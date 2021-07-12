#include<iostream>

class Date 
{
    int d, m, y;
    public:
        Date(int dd, int mm, int yy);
        /* the const after the brackets 
           indicate that these functions
           do not modify the state of a Date
        */
        int day() const {return d;}
        int month() const {return m;}
        int year() const {return y;}

        void add_year(int n);
        void Print() const;
};

Date::Date(int dd, int mm, int yy)
{
    d = dd;
    m = mm;
    y = yy;
}
void Date::add_year(int n)
{
    y += n;
}

void Date::Print() const
{
    std::cout << "day: " << day() << ", month: " << month() << ", year: " << year() << std::endl;
}

int main()
{
    Date d1(10,1,2020);
    d1.Print();
    d1.add_year(5);
    d1.Print();
}