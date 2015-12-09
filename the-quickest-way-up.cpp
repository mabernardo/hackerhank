/* the-quickest-way-up.cpp
 * https://www.hackerrank.com/challenges/the-quickest-way-up
 */
#include <iostream>
#include <vector>
using namespace std;


#ifdef DEBUG
    #define LOG( x ) cout << x
    #define LOG_LEVEL( x ) cout << std::string(level * 2, '.') << x
#else
    #define LOG( x )
    #define LOG_LEVEL( x )
#endif

const int BOARD_SIZE = 100;
const int DICE_MIN = 1;
const int DICE_MAX = 6;

int level = -1;
int count = 0;

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

    LOG_LEVEL( "moving from " << pos << " to " << end << " [" );
    while (pos < end)
    {
        distance = end - pos;
        dice_value = distance > DICE_MAX ? DICE_MAX : distance;
        for (dice = dice_value; dice >= DICE_MIN - 1; --dice)
        {
            if (!hasPath(paths, pos + dice, end))
            {
                LOG ( " +" << dice << " " );
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
    LOG( "]  moved " << moves << endl );
    return moves;
}

bool hasPassed(const Path& path, const vector<Path>& paths)
{
    for (const Path& pd : paths)
    {
        if (path.start == pd.start && path.end == pd.end)
        {
            return true;
        }
    }
    return false;
}

int quickest_way(const vector<Path>& paths, const vector<Path>& passed, int start)
{
    int pos = start;
    int shortest = BOARD_SIZE;
    int m, moves = 0;
    int total_moves = 0;
    vector<Path> track = passed;

    ++level;
    ++count;

    for (const Path& p : paths)
    {
        if (start > p.start || hasPassed(p, track))
            continue;

        moves = 0;
        m = move(start, p.start, paths);
        if (m == -1 || m > shortest)
            continue;
        moves += m;

        LOG_LEVEL("entering path (" << p.start << ", " << p.end << ")" << endl);
        track.push_back(p);
        m = quickest_way(paths, track, p.end);
        if (m > -1)
        {
            moves += m;
            LOG_LEVEL("moves = " << moves << endl );
            if (moves < shortest)
            {
                shortest = moves; // + moves_to_path;
                pos = p.end;
                LOG_LEVEL("shortest = " << shortest << endl);
            }
            else
                break;
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

    LOG_LEVEL("best = " << total_moves << endl );

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
        LOG("calculations: " << count << endl);
    }
    return 0;
}
