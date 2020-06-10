#pragma once
void findmax(int size, int *begin, int &tmp);

void bubblesort(int *array, int size)
{
    int tmp;
    for (;size>1;--size)
    {
        findmax(size, array, tmp);
    }
}
void comptwo(int *a, int *b, int &tmp)
{
    if (*a > *b)
    {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
void findmax(int size, int *begin, int &tmp)
{
    for (int i = 0; i < size - 1; ++i)
    {
        comptwo(begin + i, begin + i + 1, tmp);
    }
}