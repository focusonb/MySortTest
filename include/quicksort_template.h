
struct Bigger_int;
struct Less_int;
void swap(int &a, int &b);

template <typename T, typename bigger=Bigger_int,typename less=Less_int>
void quicksort1(T *array, int left, int right)
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
        } while (less()(array[leftCursor], pivot));
        do
        {
            rightCursor--;
        } while (bigger()(array[rightCursor], pivot));
        if (leftCursor >= rightCursor)
            break;
        swap(array[leftCursor], array[rightCursor]);
    }
    array[left] = array[rightCursor];
    array[rightCursor] = pivot;
    quicksort1<T>(array, left, rightCursor - 1);
    quicksort1<T>(array, rightCursor + 1, right);
};

template <typename T, typename less>
int indexOfMax(T *array, int size)
{
    int max=0;
    for (int i = 0; i < size - 1; ++i)
    {
        if (less()(array[max], array[i + 1]))
        {
            max=i+1;
        }  
    }
    return max;
}

template <typename T, typename bigger=Bigger_int,typename less=Less_int>
void quicksort(T *array, int size)
{
    if (size <= 1)
        return;
    int max = indexOfMax<T, Less_int>(array, size);
    swap(array[size - 1], array[max]);
    quicksort1<T>(array, 0, size - 2);
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

struct Bigger_int
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};
struct Less_int
{
    bool operator()(const int &a, const int &b) const
    {
        return a < b;
    }
};