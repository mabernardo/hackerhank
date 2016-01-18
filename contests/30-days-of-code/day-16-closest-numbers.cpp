/* day-16-closest-numbers.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-16-closest-numbers
 */
#include <vector>
#include <iostream>
using namespace std;

void sort_array(vector<int>& arr)
{
    int j, key;
    for (unsigned int i = 1; i < arr.size(); ++i)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_closest_numbers(vector<int>& arr)
{
    int a, b, diff;
    int min_diff = 10000000;
    sort_array(arr);

    vector<int> closest;
    for (vector<int>::iterator it = arr.begin() + 1; it != arr.end(); ++it)
    {
        a = *it;
        b = *(it - 1);
        diff = abs(a - b);
        if (diff < min_diff)
        {
            min_diff = diff;
            closest.clear();
            closest.push_back(min(a, b));
            closest.push_back(max(a, b));
        }
        else if (diff == min_diff)
        {
            closest.push_back(min(a, b));
            closest.push_back(max(a, b));
        }
    }

    for (const int& n : closest)
        cout << n << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    print_closest_numbers(arr);
    return 0;
}
