

#include "threadEx.hpp"




/* These are both external variables declared in threadEx.hpp 
    it would also be correct to declare them in threadEx.cpp
    they would still function the same as global variables.*/
int glob = 0;
pthread_mutex_t mtx;// = PTHREAD_MUTEX_INITIALIZER;
/* ************** /\ pretty neat amiright? /\ ************** */


int main(int argc, char* argv[])
{   

    pthread_mutexattr_t mtxAttr;
    int s, type;

    s = pthread_mutexattr_init(&mtxAttr);

    s = pthread_mutexattr_settype(&mtxAttr, PTHREAD_MUTEX_ERRORCHECK);

    s = pthread_mutex_init(&mtx, &mtxAttr);

    

    //ptAttributesEx();
    mutexExFunc(argc, argv);
    
    s = pthread_mutexattr_destroy(&mtxAttr);

}

