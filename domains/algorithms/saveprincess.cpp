/* saveprincess.cpp
 * https://www.hackerrank.com/challenges/saveprincess
 */
#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, const vector<string>& grid)
{
    int bot_i, bot_j;
    int princess_i, princess_j;

    int i = 0;
    for (const string& s : grid)
    {
        for (unsigned int j = 0; j < s.size(); ++j)
        {
            if (s[j] == 'm')
            {
                bot_i = i;
                bot_j = j;
            }
            else if (s[j] == 'p')
            {
                princess_i = i;
                princess_j = j;
            }
        }
        ++i;
    }

    while (abs(bot_i - princess_i))
    {
        if (bot_i > princess_i)
        {
            cout << "UP" << endl;
            --bot_i;
        }
        else
        {
            cout << "DOWN" << endl;
            ++bot_i;
        }
    }

    while (abs(bot_j - princess_j))
    {
        if (bot_j > princess_j)
        {
            cout << "LEFT" << endl;
            --bot_j;
        }
        else
        {
            cout << "RIGHT" << endl;
            ++bot_j;
        }
    }

}

int main(void)
{
    int m;
    vector<string> grid;

    cin >> m;
    for(int i=0; i<m; i++)
    {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m, grid);

    return 0;
}
