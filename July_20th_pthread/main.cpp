#include<iostream>
#include<pthread.h>
#include<errno.h>
#include<memory>



class A
{
    int x;
    public:
        A():x(5){};
        void f()
        {
            printf("hello from class A! %d\n", x);
        }
};


void* func(void* x)
{
    printf("hello world\n");
    A *xx = new A();
    return (void*) xx;
}

void* funcWithSmartPointer(void* x)
{
    printf("hello world, smart pointer edition\n");
    std::shared_ptr<A> xx(new A());
    x = (void*) &xx;
    return (void*) 1;//&xx;
}

void* buddy(void* x)
{
    pthread_detach(pthread_self()); // this allows us to not care about joining the thread in main
    void* res;
    pthread_t xx = (pthread_t) x;

    pthread_join(xx, &res);

    ((A*)(res))->f(); // example of how to return a pointer to an object from a thread
    delete(((A*)(res)));
    ((A*)(res))->f();

    return (void*) 1;
}
int main()
{
    pthread_t thread, thread2;
    int createError, createError2;
    void *res; // result to be returned from the thread

    std::shared_ptr<A> x(new A());
    std::shared_ptr<A> *y;
    //y = &x;
    //(y->get())->f();
    try
    {   /* thread ID, attributes, function, argument to function */
        createError = pthread_create(&thread, NULL, func, nullptr);
        createError2 = pthread_create(&thread2, NULL, buddy, (void*) &thread);
        //createError = pthread_create(&thread, NULL, funcWithSmartPointer, (void*) y);
    }
    catch(...)
    {
        printf("nay\n");
    }

    if(!createError)
    {

        /*
        pthread_join(thread, &res);

        
        ((A*)(res))->f(); // example of how to return a pointer to an object from a thread
        delete(((A*)(res)));
        ((A*)(res))->f();
        */

        /*
        //y = (std::shared_ptr<A>*) res;
        (y->get())->f();
        */

       //pthread_join(buddy,NULL); /* not necessary if detach is used, since this thread doesn't return anything useful */
        return 0;
    }
    
}