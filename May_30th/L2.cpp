//Preprocessor directive that includes header iostream
#include <iostream>

// Start of your program: function block main()
int main(int argc, char* argv[])
{

    // write value on the screen
    std::cout << "Hello World" << std::endl; //"Hello World" is a string literal
    // std is also called the standard namespace
    // std::fstream is the stream into a file and cout is the stream for console out


    using namespace std;

    cout << "hello from namespace std" << endl;
    // Return a value to the OS
    return 0; // by convention 0 is returned on success and -1 is returned on failure
}
/*
    this c++ program can be broadly classified into two parts
    1) the preprocessor directives that start with a #
    2) the main body of the program that starts with int main()*/