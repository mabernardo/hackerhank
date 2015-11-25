#include <iostream>
#include <vector>
#include <map>
using namespace std;

int lonely_integer(std::vector<int> v)
{
    int res = 0;
    map<int, int> m;
    for (const int &n : v)
        ++m[n];

    for (const auto &pair : m)
    {
        if (pair.second == 1)
        {
            res = pair.first;
            break;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    int item;
    for (int i = 0; i < n; ++i)
    {
        cin >> item;
        v.push_back(item);
    }
    int res = lonely_integer(v);
    cout << res;
    return 0;
}
