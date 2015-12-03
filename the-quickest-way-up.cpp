/* the-quickest-way-up.cpp
 * https://www.hackerrank.com/challenges/the-quickest-way-up
 */
#include <iostream>
#include <vector>
using namespace std;

//#define DEBUG

const int BOARD_SIZE = 100;
const int DICE_MIN = 1;
const int DICE_MAX = 6;

struct Path {
    int start;
    int end;
};

bool hasSnake(const vector<Path>& snakes, int pos)
{
    for (const Path& s : snakes)
    {
        if (s.start == pos)
            return true;
    }
    return false;
}

int move(int start, int end, const vector<Path>& snakes)
{
    int pos = start;
    int moves = 0;
    int dice, dice_value;
    int distance;

    //cout << "  moving from " << pos << " to " << end << endl;
    while (pos < end)
    {
        distance = end - pos;
        dice_value = distance > DICE_MAX ? DICE_MAX : distance;
        for (dice = dice_value; dice >= DICE_MIN - 1; --dice)
        {
            if (!hasSnake(snakes, pos + dice))
            {
                //cout << "   dice " << dice << endl;
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
    //cout << "  moved " << moves << endl;
    return moves;
}

int quickest_way(const vector<Path>& ladders, const vector<Path>& snakes,
        int start)
{
        int pos = start;
        int shortest = 100;
        int moves_to_ladder, moves = 0;
        int total_moves = 0;
        int distance;
        int dice_value;

        //cout << "moving from " << start << endl;
        for (const Path& p : ladders)
        {
            if (start < p.start)
            {
                //cout << " climbing ladder [" << p.start << ", " << p.end << "]" << endl;
                moves_to_ladder = move(start, p.start, snakes);
                if (moves_to_ladder == -1)
                    continue;

                moves = quickest_way(ladders, snakes, p.end);
                if (moves > -1 && moves < shortest)
                {
                    shortest = moves + moves_to_ladder;
                    pos = p.end;
                }
            }
        }

        if (shortest < 100)
            total_moves += shortest;
        else
        {
            moves = move(pos, BOARD_SIZE, snakes);
            total_moves = moves > -1 ? total_moves + moves : -1;
        }
        //cout << " total_moves = " << total_moves << endl;

        return total_moves;
}

int main()
{
    int t;
    int l, s;

    cin >> t;
    while(t--)
    {
        vector<Path> ladders;
        vector<Path> snakes;

        cin >> l;
        while (l--)
        {
            Path p;
            cin >> p.start >> p.end;
            ladders.push_back(p);
        }

        cin >> s;
        while (s--)
        {
            Path p;
            cin >> p.start >> p.end;

            snakes.push_back(p);
        }

        cout << quickest_way(ladders, snakes, 1) << endl;
#ifdef DEBUG
        for (Path& p : ladders)
            cout << "l.s=" << p.start << " l.e=" << p.end << endl;

        for (Path& p : snakes)
            cout << "s.s=" << p.start << " s.e=" << p.end << endl;
#endif
    }
    return 0;
}
