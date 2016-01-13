/* day-5-loops.cpp
   https://www.hackerrank.com/contests/30-days-of-code/challenges/day-5-loops
 */
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int t, a, b, n, r;

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        r = a;
        for (int i = 0; i < n; ++i)
        {
            r += pow(2, i) * b;
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}
