#define showresult 
#define BUBBLE_SORT 1
#define QUICK_SORT 2
#define QUICK_SORT_TEMPLATE 3
#define VECTORSORT 4
#define MYQUICKSORT 5
#define MYSORT 5
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "randnum.h"

#if (MYSORT==QUICK_SORT_TEMPLATE)
#include "quicksort_template.h"
#elif (MYSORT==BUBBLE_SORT)
#include "bubblesort.h"
#elif MYSORT==MYQUICKSORT
#include "quicksort1.h"
#elif (MYSORT==QUICK_SORT)
#include "quicksort.h"
#endif

using namespace std;

int main()
{
    // const long double time_begin = time(NULL)*1000;

    using namespace chrono;
    int size = 100;
    RandNum a(size);
    int *begin = a.getptr();
#if MYSORT==VECTORSORT
    vector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = begin[i];
    }
#endif

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

#if MYSORT==BUBBLE_SORT
    bubblesort(begin, size);
#elif MYSORT==QUICK_SORT||MYSORT==MYQUICKSORT
    quicksort(begin, size);
#elif MYSORT==QUICK_SORT_TEMPLATE
    quicksort<int>(begin, size);
#elif MYSORT==VECTORSORT
    sort(vec.begin(), vec.end());
#endif

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;

#ifdef showresult
#if MYSORT!=VECTORSORT
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
#endif

    std::cout << "It took me " << time_span.count() << " milliseconds.";
    return 0;
}