#pragma once
void quicksort(int *begin, int size);
void swapvalue(int size, int *&begin, int &mid);
void quicksort(int *begin, int size)
{
    if (size <= 1)
    {
        return;
    }
    int mid;
    swapvalue(size, begin, mid);
    quicksort(begin, mid);
    quicksort(begin + mid, size - mid);
}

void swapvalue(int size, int *&begin, int &mid)
{
    int compnum = *begin;
    int left = 1;
    int right = size - 1;
    int tmp;
    while (1)
    {
        //int i = left;
        for (; *(begin + left) <= compnum; ++left)
        {
            if (left == right)
            {
                *begin = *(begin + left);
                *(begin + left) = compnum;
                mid = left ;
                return;
            }
        }
       // left = i;

        //int j = right;
        for (; *(begin + right) > compnum; --right)
        {
            if (right == left)
            {
                *begin = *(begin + right- 1);
                *(begin + right - 1) = compnum;
                mid = right;
                return;
            }
        }
        tmp = *(begin + left);
        *(begin + left) = *(begin + right);
        *(begin +right) = tmp;
        right = right;
        if (right - left == 1)
        {
            *begin = *(begin + left);
            *(begin + left) = compnum;
            mid = left + 1;
            return;
        }
        ++left;
        --right;
    }
}