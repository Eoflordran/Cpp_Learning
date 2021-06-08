#include <iostream>
#include <thread>

void hello(){

    std::cout <<"Hello World\n";
}
int main(){

    
    //std::cout << __cplusplus << "\n";
    //std::thread t(hello);
    std::thread t[10];
    for(int i = 0; i<10 ; i++){
        t[i] = std::thread(hello,i);
    }
    
    for(int i = 0 ; i<10 ; i++){
        t[i].join();
    }
    
}