/* the-quickest-way-up.cpp
 * https://www.hackerrank.com/challenges/the-quickest-way-up
 */
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
    #define LOG( x ) x
#else
    #define LOG( x )
#endif

const int BOARD_SIZE = 100;
const int DICE_MIN = 1;
const int DICE_MAX = 6;

struct Path {
    int start;
    int end;
};

void print_path(const vector<Path>& paths)
{
    cout << "[ ";
    for (const Path& p : paths)
        cout << "(p.s=" << p.start << " p.e=" << p.end << ") ";
    cout << "]" << endl;
}

bool hasPath(const vector<Path>& paths, int pos, int origin)
{
    for (const Path& s : paths)
    {
        if (s.start == pos && pos != origin)
            return true;
    }
    return false;
}

int move(int start, int end, const vector<Path>& paths)
{
    int pos = start;
    int moves = 0;
    int dice, dice_value;
    int distance;

    LOG( cout << "  moving from " << pos << " to " << end << " [" );
    while (pos < end)
    {
        distance = end - pos;
        dice_value = distance > DICE_MAX ? DICE_MAX : distance;
        for (dice = dice_value; dice >= DICE_MIN - 1; --dice)
        {
            if (!hasPath(paths, pos + dice, end))
            {
                LOG ( cout << " +" << dice << " " );
                pos += dice;
                break;
            }
        }
        if (dice < DICE_MIN)
        {
            moves = -1; // unreacheable
            break;
        }
        ++moves;
    }
    LOG( cout << "]  moved " << moves << endl );
    return moves;
}
int level = 0;

int quickest_way(const vector<Path>& paths, const vector<Path>& passed, int start)
{
    int pos = start;
    int shortest = BOARD_SIZE;
    int m, moves = 0;
    int total_moves = 0;
    bool deadend;
    vector<Path> track = passed;

    ++level;

    LOG( cout << "{" << level << "} moving from " << start << endl );
    for (const Path& p : paths)
    {
        if (start < p.start)
        {
            deadend = false;
            moves = 0;
            for (const Path& pd : passed)
            {
                if (p.start == pd.start && p.end == pd.end)
                {
                    deadend = true;
                    break;
                }
            }
            if (deadend)
                continue;

            LOG( cout << "{" << level << "} entering path (" << p.start << ", "
                << p.end << ")" << endl );
            m = move(start, p.start, paths);
            if (m == -1)
                continue;
            moves += m;

            track.push_back(p);
            m = quickest_way(paths, track, p.end);
            if (m > -1)
            {
                moves += m;
                LOG( cout << "{" << level << "} moves = " << moves << ", shortest = " << shortest << endl );
                if (moves < shortest)
                {
                    shortest = moves; // + moves_to_path;
                    LOG( cout << "{" << level << "} shortest = " << shortest << endl);
                    pos = p.end;
                }
            }
        }
    }

    m = move(start, BOARD_SIZE, paths);
    if (m > 0 && m < shortest)
        shortest = m;

    if (shortest < BOARD_SIZE)
        total_moves = shortest;
    else
    {
        moves = move(pos, BOARD_SIZE, paths);
        total_moves = moves > -1 ? total_moves + moves : -1;
    }

    LOG( cout << "{" << level << "} total_moves = " << total_moves << endl );
    LOG( print_path(track) );

    --level;
    return total_moves;
}

int main()
{
    int t;
    int l, s;

    cin >> t;
    while(t--)
    {
        vector<Path> paths;
        vector<Path> track;

        cin >> l;
        while (l--)
        {
            Path p;
            cin >> p.start >> p.end;
            paths.push_back(p);
        }

        cin >> s;
        while (s--)
        {
            Path p;
            cin >> p.start >> p.end;

            paths.push_back(p);
        }
        #ifdef DEBUG
        print_path(paths);
        #endif

        cout << quickest_way(paths, track, 1) << endl;
    }
    return 0;
}
