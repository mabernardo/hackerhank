/* insertion-sort-2.cpp
 * https://www.hackerrank.com/challenges/insertionsort2
 */
#include <iostream>
#include <vector>
using namespace std;

void print_vector(const vector<int>& v)
{
    for (const int& n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}

void insertion_sort(vector<int>& v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        int j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            int t = v[j - 1];
            v[j - 1] = v[j];
            v[j] = t;
            j--;
        }
        print_vector(v);
    }

}

int main()
{
    int size, item;

    cin >> size;
    vector<int> v;

    while (size--)
    {
        cin >> item;
        v.push_back(item);
    }

    insertion_sort(v);
    return 0;
}
