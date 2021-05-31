//Preprocessor directive that includes header iostream
#include <iostream>

// Start of your program: function block main()
int main(int argc, char* argv[])
{

    bool decider;

    using std::cout;
    using std::endl;

    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of unsigned short int: " << sizeof(unsigned short) << endl;
    cout << "Size of short int: " << sizeof(short) << endl;

    cout << "Size of unsigned long int: " << sizeof(unsigned long) << endl;
    cout << "Size of long int: " << sizeof(long) << endl;
    cout << "Size of int: " << sizeof(int) << endl;

    cout << "Size of unsigned long long: " << sizeof(unsigned long long) << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "The output changes with compiler, hardware and OS" << endl;
    // Return a value to the OS
    return 0; 
}
