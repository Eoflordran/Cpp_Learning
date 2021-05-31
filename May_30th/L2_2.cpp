//Preprocessor directive that includes header iostream
#include <iostream>
#include <string>
// Start of your program: function block main()
int main(int argc, char* argv[])
{
    /*  Note that this is a janky implementation
        using the "using" keyword as some std
        features require the use of std:: and
        some don't*/

    using std::cout;
    using std::endl;
    int v;
    std::cin >> v;
    cout << v << endl;

    std::string inString;

    std::cin >> inString;
    cout << inString << endl;
    // Return a value to the OS
    return 0; 
}
