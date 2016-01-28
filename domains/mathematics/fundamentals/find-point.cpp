/* find-point.cpp
 * https://www.hackerrank.com/challenges/find-point
 * by @mabernardo
 */
#include <iostream>
using namespace std;

int main()
{
    int t;
    int px, py, qx, qy;
    int sx, sy;
    cin >> t;

    while (t--)
    {
        cin >> px >> py >> qx >> qy;
        sx = qx + qx - px;
        sy = qy + qy - py;
        cout << sx << " " << sy << endl;
    }
    return 0;
}
