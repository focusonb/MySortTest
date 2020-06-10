#pragma once
bool bigger(const int &a, const int &b);
bool less(const int &a, const int &b);


void swap(int &a, int &b);

template <typename T>
void quicksort1(T *array, int left, int right,bool (*bigger)(const int &a, const int &b),
bool (*less)(const int &a, const int &b))
{
    if (left >= right)
        return;
    int leftCursor = left, rightCursor = right + 1;
    int pivot = array[left];
    while (1)
    {
        do
        {
            leftCursor++;
        } while ((*less)(array[leftCursor], pivot));
        do
        {
            rightCursor--;
        } while ((*bigger)(array[rightCursor], pivot));
        if (leftCursor >= rightCursor)
            break;
        swap(array[leftCursor], array[rightCursor]);
    }
    array[left] = array[rightCursor];
    array[rightCursor] = pivot;
    quicksort1<T>(array, left, rightCursor - 1,bigger,less);
    quicksort1<T>(array, rightCursor + 1, right,bigger,less);
};

template <typename T>
int indexOfMax(T *array, int size,bool (*less)(const int &a, const int &b))
{
    int max = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        if ((*less)(array[max], array[i + 1]))
        {
            max = i + 1;
        }
    }
    return max;
}

template <typename T>
void quicksort(T *array, int size)
{
    bool less(const int &a, const int &b);
    if (size <= 1)
        return;
    int max = indexOfMax<T>(array, size,less);
    swap(array[size - 1], array[max]);
    quicksort1<T>(array, 0, size - 2,bigger,less);
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

bool bigger(const int &a, const int &b)
{
    return a > b;
}

bool less(const int &a, const int &b)
{
    return a < b;
}
