/* day-10-binary-numbers.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-10-binary-numbers
 */
#include <iostream>
using namespace std;

string dec_to_bin(int num)
{
    if (num == 0)
        return string("0");

    string bin = "";
    int m;

    while (num > 0)
    {
        m = num % 2;
        bin.insert(0, to_string(m));
        num /= 2;
    }
    return bin;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << dec_to_bin(n) << endl;
    }
    return 0;
}
