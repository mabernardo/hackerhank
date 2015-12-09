/* cut-the-sticks.cpp
 * https://www.hackerrank.com/challenges/cut-the-sticks
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    int cuts;
    int shortest;

    cin >> t;
    vector<int> sticks(t);

    for (int i = 0; i < t; ++i)
        cin >> sticks[i];

    do
    {
        cuts = 0;
        shortest = 1000;
        for (int& s : sticks)
        {
            if (s > 0 && s < shortest)
                shortest = s;
        }

        for (int& s : sticks)
        {
            if (s >= shortest)
            {
                s -= shortest;
                ++cuts;
            }
        }
        if (cuts)
            cout << cuts << endl;
    }
    while (cuts);

    return 0;
}
