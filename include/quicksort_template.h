
struct Bigger_int;
struct Less_int;
void swap(int &a, int &b);

template <typename T, typename bigger, typename less>
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
    quicksort1<T, bigger, less>(array, left, rightCursor - 1);
    quicksort1<T, bigger, less>(array, rightCursor + 1, right);
};

template <typename T, typename bigger>
int indexOfMax(T *array, int size, bigger bigger_int = bigger())
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (bigger_int(array[i], array[i + 1]))
        {
            swap(array[i], array[i + 1]);
        }
    }
}

template <typename T>
void quicksort(T *array, int size)
{
    if (size <= 1)
        return;
    int max = indexOfMax<T, Bigger_int>(array, size);
    swap(array[size - 1], array[max]);
    quicksort1<T, Bigger_int, Less_int>(array, 0, size - 2);
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
struct Less_int
{
public:
    bool operator()(const int &a, const int &b) const
    {
        if (a < b)
            return true;
        else
            return false;
    }
};
struct Bigger_int
{
public:
    bool operator()(const int &a, const int &b) const
    {
        if (a > b)
            return true;
        else
            return false;
    }
};