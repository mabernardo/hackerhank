/* saveprincess2.cpp
 * https://www.hackerrank.com/challenges/saveprincess2
 */
#include <iostream>
#include <vector>
using namespace std;

void nextMove(int n, int r, int c, const vector<string>& grid)
{
    int princess_i, princess_j;
    int i = 0;
    for (const string& s : grid)
    {
        for (unsigned int j = 0; j < s.size(); ++j)
        {
            if (s[j] == 'p')
            {
                princess_i = i;
                princess_j = j;
            }
        }
        ++i;
    }

    if (abs(r - princess_i))
    {
        if (r > princess_i)
            cout << "UP" << endl;
        else
            cout << "DOWN" << endl;
    }
    else
    {
        if (c > princess_j)
            cout << "LEFT" << endl;
        else
            cout << "RIGHT" << endl;
    }
}

int main(void)
{
    int n, r, c;
    vector<string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
