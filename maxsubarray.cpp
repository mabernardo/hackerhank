/* maxsubarray.cpp
 * https://www.hackerrank.com/challenges/maxsubarray
 */
#include <iostream>
#include <vector>
using namespace std;

int sum_continous(const vector<int>& arr)
{
    int best_sum = -1000000000;
    int current_sum = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        current_sum += arr[i];
        if (arr[i] > current_sum)
            current_sum = arr[i];

        if (current_sum > best_sum)
            best_sum = current_sum;
    }
    return best_sum;
}

int sum_non_continous(const vector<int>& arr)
{
    int best_sum = -1000000000;

    for (const int& val : arr)
    {
        if (val < 0 && val > best_sum)
            best_sum = val;

        if (val > 0)
        {
            if (best_sum < 0)
                best_sum = 0;

            best_sum += val;
        }
    }
    return best_sum;
}

int main()
{
    int t, n, a;

    cin >> t;
    while (t--)
    {
        vector<int> arr;
        cin >> n;

        while (n--)
        {
            cin >> a;
            arr.push_back(a);
        }
        cout << sum_continous(arr) << " ";
        cout << sum_non_continous(arr) << endl;
    }
    return 0;
}
