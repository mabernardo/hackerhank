/* day-7-arrays.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-7-arrays
 */
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> arr(t);

    for (int i = 0; i < t; ++i)
    {
        cin >> arr[i];
    }

    for (vector<int>::reverse_iterator it = arr.rbegin(); it != arr.rend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}
