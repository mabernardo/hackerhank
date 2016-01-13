/* day-11-more-review.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-11-more-review
 */
#include <vector>
#include <iostream>
using namespace std;

const int MATRIX_SIZE = 6;

int max_hourglass(const vector<vector<int>> &arr)
{
    int sum, max_sum = -99999;
    for (unsigned int i = 0; i <= arr.size() - 3; ++i)
    {
        for (unsigned int j = 0; j <= arr[i].size() - 3; ++j)
        {
            sum = 0;
            sum += arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            sum += arr[i + 1][j + 1];
            sum += arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

int main()
{
    vector<vector<int>> arr(MATRIX_SIZE, vector<int>(MATRIX_SIZE));
    for(int arr_i = 0; arr_i < MATRIX_SIZE; arr_i++)
    {
        for(int arr_j = 0; arr_j < MATRIX_SIZE; arr_j++)
        {
            cin >> arr[arr_i][arr_j];
        }
    }

    cout << max_hourglass(arr) << endl;
    return 0;
}
