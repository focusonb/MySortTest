void quicksort(int *array, int left, int right);
void swap(int &a, int &b);
int indexOfMax(int *array, int size);
void quicksort(int *array, int size)
{
    if (size <= 1)
        return;
    int max = indexOfMax(array, size);
    swap(array[size - 1], array[max]);
    quicksort(array, 0, size - 2);
}
int indexOfMax(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            swap(array[i], array[i + 1]);
        }
    }
}
void quicksort(int *array, int left, int right)
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
        }
        while (array[leftCursor] < pivot);
        do
        {
            rightCursor--;
        }while (array[rightCursor] > pivot);
        if (leftCursor >= rightCursor)
            break;
        swap(array[leftCursor], array[rightCursor]);
    }
    array[left] = array[rightCursor];
    array[rightCursor] = pivot;
    quicksort(array, left, rightCursor - 1);
    quicksort(array, rightCursor + 1, right);
    // array[left] = array[leftCursor-1];
    // array[leftCursor-1] = pivot;
    // quicksort(array, left, leftCursor - 2);
    // quicksort(array, leftCursor -1, right);
}
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
