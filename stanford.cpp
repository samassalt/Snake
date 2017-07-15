#include "stanford.h"
#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <ctime>

const double kWaitTime = 0.1; // Pause 0.1 seconds between frames
void Pause()
{
    clock_t startTime = clock(); // clock_t is a type which holds clock ticks.
    /* This loop does nothing except loop and check how much time is left.
    * Note that we have to typecast startTime from clock_t to double so
    * that the division is correct. The static_cast<double>(...) syntax
    * is the preferred C++ way of performing a typecast of this sort;
    * see the chapter on inheritance for more information.
    */
    while(static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC < kWaitTime);
}

bool isEven(int x)
{
    return x % 2 == 0;
}

string GetLine()
{
    string result;
    getline(cin, result);
    return result;
}

void OpenUserFile(ifstream& input)
{
    while(true)
    {
        cout << "Enter filename: ";
        string filename = GetLine();

        input.open(filename.c_str());
        if(input.is_open()) return;

        cout << "Sorry, I can't find the file " << filename << endl;
        input.clear();
    }
}
