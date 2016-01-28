/* variable-sized-arrays.cpp
 * https://www.hackerrank.com/contests/code-cpp-3/challenges/variable-sized-arrays
 * by @mabernardo
 */
#include <iostream>
using namespace std;

int main()
{
    int n, q, k, a, b;
    cin >> n >> q;
    int** s = new int*[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        s[i] = new int[k];
        for (int j = 0; j < k; ++j)
            cin >> s[i][j];
    }

    while (q--)
    {
        cin >> a >> b;
        cout << s[a][b] << endl;
    }

    for (int i = 0; i < n; ++i)
        delete[] s[i];
    delete[] s;
    return 0;
}
