#include "utilFuncs.hpp"


int getInt(char *x)
{
    int i = 0, j = 0, ret = 0;

    while(x[i] != '\0')
    {
        i++;
    }

    while(i > -1)
    {
        switch(x[i])
        {
            case '0':
                break;
            case '1':
                ret += (int) 1*powf((float) 10, (float) j-1);
                break;
            case '2':
                ret += (int) 2*powf((float) 10, (float) j-1);
                break;
            case '3':
                ret += (int) 3*powf((float) 10, (float) j-1);
                break;
            case '4':
                ret += (int) 4*powf((float) 10, (float) j-1);
                break;
            case '5':
                ret += (int) 5*powf((float) 10, (float) j-1);
                break;
            case '6':
                ret += (int) 6*powf((float) 10, (float) j-1);
                break;
            case '7':
                ret += (int) 7*powf((float) 10, (float) j-1);
                break;
            case '8':
                ret += (int) 8*powf((float) 10, (float) j-1);
                break;
            case '9':
                ret += (int) 9*powf((float) 10, (float) j-1);
                break;
        }
        j++;
        i--;
    }
    return ret;
}