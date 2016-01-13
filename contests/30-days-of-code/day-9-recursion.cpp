/* day-9-recursion.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-9-recursion
 */
#include <iostream>
using namespace std;

int find_gcd(int a, int b)
{
    if (b == 0)
        return a;

    int r = a % b;
    return find_gcd(b , r);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << find_gcd(a, b);

    return 0;
}
