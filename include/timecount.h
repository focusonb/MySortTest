#pragma once
#include <chrono>
//#include <ctime>
using namespace std;
class TimeCount
{
private:
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

public:
    void setbegin()
    {
        begin = chrono::high_resolution_clock::now();
    }
    void setend()
    {
        end = chrono::high_resolution_clock::now();
    }
    void showtime()
    {
        chrono::duration<double, std::milli> totaltime = end-begin;
        std::cout << "It took me " << totaltime.count()<< " milliseconds.";
    }
};