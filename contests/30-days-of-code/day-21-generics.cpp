/* day-21-generics.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-21-generics
 * by @mabernardo
 */
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printArray(const vector<T>& array)
{
    for (const T &t : array)
        cout << t << endl;
}


int main()
{
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};

    printArray<int>(vInt);
    printArray<string>(vString);

    return 0;
}
