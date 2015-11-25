/* tutorial-intro.cpp
 * https://www.hackerrank.com/challenges/tutorial-intro
 */
#include <iostream>
#include <vector>
using namespace std;

int search_first(int n, vector<int>& v)
{
    int index = 0;
    for (int& x : v)
    {
        if (x == n)
            break;

        ++index;
    }
    return index;
}

int main()
{
    int search, size, item;
    vector<int> v;
    cin >> search;
    cin >> size;

    while (size--)
    {
        cin >> item;
        v.push_back(item);
    }
    cout << search_first(search, v) << endl;
    return 0;
}
