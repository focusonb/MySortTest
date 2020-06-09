#include <cstdlib>

class RandNum
{
    int numcount;
    int *ptr_array;

public:
    RandNum(int num = 0);
    int *getptr();
};