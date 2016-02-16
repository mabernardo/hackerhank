/* day-28-regex-patterns.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-28-regex-patterns-intro-to-databases
 * by @mabernardo
 */
#include <regex>
#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;
    cin.clear();
    cin.ignore(10000, '\n');

    while (t--)
    {
        string pattern;
        getline(cin, pattern);

        try
        {
            regex rx(pattern);
            cout << "Valid" << endl;
        }
        catch (regex_error& err)
        {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
