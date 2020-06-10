#pragma once
void quicksort(int *begin, int size);
//void binaryarray(int size,int* begin);
void swapvalue(int size, int *begin, int &mid);
void quicksort(int *begin, int size)
{
    if (size <= 1)
    {
        return;
    }
    int mid;
    int tmp = *begin;
    *begin = *(begin + size / 2);
    *(begin + size / 2) = tmp;
    swapvalue(size, begin, mid);
    quicksort(begin, mid);
    quicksort(begin + mid, size - mid);
}
void swapvalue(int size, int *begin, int &mid)
{
    int compnum = *begin;
    int left = 0;
    int right = size - 1;
    while (1)
    {
        // if (right - left == 1)
        // {
        //     mid = right;
        //     return;
        // }
        int i = left;
        int j = right;
        for (; !(i == right || *(begin + i) > compnum); ++i)
            ;
        if (i == right)
        {
            if (*(begin + i) > compnum)
            {
                int tmp;
                tmp = *(begin + i);
                *(begin + i) = compnum;
                *begin = tmp;
                mid = i;
                return;
            }
            else
            {
                mid = i + 1;
                return;
            }
        }
        else
        {
            left = i++;
        }

        for (; !(j == left || *(begin + j) <= compnum); --j)
            ;
        if (j == left)
        {
            if (*(begin + j) <= compnum)
            {
                int tmp = *(begin + j);
                *(begin + j) = compnum;
                *begin = tmp;
                mid = ++j;
                return;
            }
            else
            {
                mid=j;
            }
        }
        else
        {
            right = j;
            int tmp = *(begin + left);
            *(begin + left) = *(begin + right);
            *(begin + right) = tmp;
            --right;
        }
    }
}
