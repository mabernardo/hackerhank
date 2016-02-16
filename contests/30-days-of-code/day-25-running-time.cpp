/* day-25-running-time.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-25-running-time
 * by @mabernardo
 */
#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n == 1)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    int start = sqrt(n); // / 2 + 1;
    for (int i = start; i > 1; --i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (is_prime(n) ? "Prime" : "Not prime") << endl;
    }
    return 0;
}
