/* goty-and-the-play.cpp
 * https://www.hackerrank.com/contests/indeed-prime-codesprint/challenges/goty-and-the-play
 *
 * Marcio Bernardo (mabernardo@gmail.com)
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n, q, p, c, scene, actor, action;
    cin >> m >> n >> q;

    vector<int> scenes(m, 0);
    vector<int> count(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> actor;
        ++scenes[actor];
        ++count[scenes[actor]];
    }

    while (q--)
    {
        cin >> action;
        if (action == 1)
        {
            cin >> actor >> scene;
            --scenes[actor];
            ++scenes[scene];
            for (int& s : scenes)
                count[s] = s;
        }
        else
        {
            cin >> p;
            c = 0;
            for (int s = p - 1; s >= 0; --s)
                c += count[s];
            cout << c << endl;
        }
    }

    return 0;
}
