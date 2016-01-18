/* day-14-scope-and-imports.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-14-scope-and-imports
 */
#include <vector>
#include <iostream>
using namespace std;

class Difference
{
private:
    vector<int> elements;

public:
    int maximumDifference;

    Difference(vector<int> v) : elements(v), maximumDifference(0) { }

    void computeDifference()
    {
        int diff;
        for (vector<int>::iterator vi = elements.begin(); vi != elements.end(); ++vi)
        {
            for (vector<int>::iterator vj = vi + 1; vj != elements.end(); ++vj)
            {
                diff = abs(*vj - *vi);
                if (diff > maximumDifference)
                {
                    maximumDifference = diff;
                }
            }
        }
    }
};


int main()
{
    int N, e;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> e;
        a[i] = e;
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
