/* day-6-lets-review.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-6-lets-review
 */
#include <iostream>
using namespace std;

void repeat(char c, int times)
{
    while (times--)
        cout << c;
}

int main()
{
    int size;
    cin >> size;

    for (int i = 1; i <= size; ++i)
    {
        repeat(' ', size - i);
        repeat('#', i);
        cout << endl;
    }
    return 0;
}
