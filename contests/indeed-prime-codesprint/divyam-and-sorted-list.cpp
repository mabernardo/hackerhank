/* divyam-and-sorted-listn.cpp
 * https://www.hackerrank.com/contests/indeed-prime-codesprint/challenges/divyam-and-sorted-list
 *
 * Code by maberna (mabernardo@gmail.com)
 */
#include <iostream>
#include <vector>
using namespace std;

bool is_related(const vector<long>& a, const vector<long>& b)
{
    bool related = true;
    int len = a.size();
    int m, x, p;
    vector<long> c(len);

    if (len == 1)
        return (a[0] == b[0]);

    for (int i = 0; i < len; ++i)
    {
        if (i > 0)
        {
            p = c[i - 1];
            m = min(a[i], b[i]);
            x = max(a[i], b[i]);
            if (m >= p)
                c[i] = m;
            else
            {
                if (x >= p)
                    c[i] = x;
                else
                {
                    related = false;
                    break;
                }
            }
        }
        else
            c[0] = min(a[0], b[0]);
    }
    return related;
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<long> a(n);
        vector<long> b(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        cout << (is_related(a, b) ? "YES" : "NO") << endl;
    }
    return 0;
}
