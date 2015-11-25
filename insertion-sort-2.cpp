/* insertion-sort-2.cpp
 * https://www.hackerrank.com/challenges/insertionsort2
 */
#include <iostream>
#include <vector>

void insertion_sort(vector<int>& v)
{
    for (int& n : v)
    {
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        {
            int& next = (it + 1);
            if (*next > n)
            {
                *it = *next;
                *next = n;
            }
        }
        print_vector(v);
    }

}

void print_vector(const vector<int>& v)
{
    for (const int& n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    int size, item;

    cin > size;
    vector<int> v(size);

    while (size--)
    {
        cin >> item;
        v.push_back(item);
    }

    insertion_sort(v);
    return 0;
}
