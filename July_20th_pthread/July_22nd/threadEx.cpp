#include "threadEx.hpp"
#include "utilFuncs.hpp"

//pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

//int glob = 0;

void mutexExFunc(int argc, char* argv[])
{
    pthread_t t1,t2;
    int loops, s;

    loops = (argc > 1) ? getInt(argv[1]) : 1000000;

    s = pthread_create(&t1, NULL, threadFunc, &loops);

    s = pthread_create(&t2, NULL, threadFunc, &loops);

    s = pthread_join(t1,NULL);

    s = pthread_join(t2,NULL);

    std::cout << glob << "\n";
}

void* threadFunc(void* x)
{
    int loops = *((int*) x);
    int loc, j, s;

    for(j = 0; j< loops; j++)
    {
        s = pthread_mutex_lock(&mtx);
        /*
        loc = glob;
        loc++;
        glob = loc;
        */
        glob++; // equivalent
        s = pthread_mutex_unlock(&mtx);

    }
    return (void*) 0;
}

void ptAttributesEx()
{
    pthread_t thr;
    pthread_attr_t attr;
    int s;

    s = pthread_attr_init(&attr);
    std::cout << s << std::endl;

    s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    std::cout << s << std::endl;

    s = pthread_create(&thr, &attr, threadFunc, (void*) 1);
    std::cout << s << std::endl;

    s = pthread_attr_destroy(&attr);
    std::cout << s << std::endl;
    
    while(1)
    {

    }
    
}