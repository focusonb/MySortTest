#include <cstdlib>
#include <ctime>
#include "randnum.h"

RandNum::RandNum(int num)
{
    ptr_array = new int[num];
    srand(time(NULL));
    for (int i = 0; i < num; ++i)
    {
        ptr_array[i] = rand() % 10000;
    }
    // ptr_array = new int[3];
    // ptr_array[0]=2;
    //  ptr_array[1]=3;
    //   ptr_array[2]=3;
    
}
int *RandNum::getptr()
{
    return ptr_array;
   //return new int(2);
}