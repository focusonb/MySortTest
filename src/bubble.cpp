//#define showresult 
#define BUBBLE_SORT 1
#define QUICK_SORT 2
#define QUICK_SORT_TEMPLATE 3
#define VECTORSORT 4
#define MYQUICKSORT 5
#define MYSORT 3
#define MYVECTOR
#include <iostream>
#include <algorithm>
#include "randnum.h"
#include "timecount.h"

#if (MYSORT == QUICK_SORT_TEMPLATE)
#include "quicksort_template.h"
#elif (MYSORT == BUBBLE_SORT)
#include "bubblesort.h"
#elif MYSORT == MYQUICKSORT
#include "quicksort1.h"
#elif (MYSORT == QUICK_SORT)
#include "quicksort.h"
#elif MYSORT == VECTORSORT
#include <vector>
#endif

#ifdef MYVECTOR
#include "myvector.h"
#endif

using namespace std;

int main()
{
    using namespace chrono;
    int size = 1000;
    RandNum a(size);
    int *begin = a.getptr();

#ifdef MYVECTOR
    MyVector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = begin[i];
    }
#endif

#if MYSORT == VECTORSORT
    vector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = begin[i];
    }
#endif

    TimeCount timmer;
    timmer.setbegin();

#ifdef MYVECTOR
begin=vec.getbegin();
#endif
#if MYSORT == BUBBLE_SORT
    bubblesort(begin, size);
#elif MYSORT == QUICK_SORT || MYSORT == MYQUICKSORT
    quicksort(begin, size);
#elif MYSORT == QUICK_SORT_TEMPLATE
    quicksort<int>(begin, size);
#elif MYSORT == VECTORSORT
    sort(vec.begin(), vec.end());
#endif

    timmer.setend();

#ifdef showresult
#if MYSORT != VECTORSORT
#ifndef MYVECTOR
    for (int i = 0; i < size; ++i)
    {
        cout << *(begin + i) << endl;
    }
#else
    for (int i = 0; i < size; ++i)
    {
        cout << vec[i] << endl;
    }
#endif
#else
    for (int i = 0; i < size; ++i)
    {
        cout << vec[i] << endl;
    }
#endif
#endif

    timmer.showtime();
    return 0;
}