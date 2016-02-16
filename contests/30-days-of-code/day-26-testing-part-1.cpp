/* day-26-testing-part-1.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-26-testing-part-1-plus-implementations
 * by @mabernardo
 */
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    int fine = 0;
    int d1, m1, y1;
    int d2, m2, y2;
    tm tm1{0}, tm2{0};

    cin >> d1 >> m1 >> y1;
    tm1.tm_mday = d1;
    tm1.tm_mon = m1 - 1;
    tm1.tm_year = y1 - 1900;

    cin >> d2 >> m2 >> y2;
    tm2.tm_mday = d2;
    tm2.tm_mon = m2 - 1;
    tm2.tm_year = y2 - 1900;

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    time_t diff = difftime(t1, t2) / (60 * 60 * 24);

    if (diff <= 0)
    {
        fine = 0;
    }
    else if (tm1.tm_year > tm2.tm_year)
    {
        fine = 10000;
    }
    else if (tm1.tm_year == tm2.tm_year && tm1.tm_mon > tm2.tm_mon)
    {
        fine = 500 * (tm1.tm_mon - tm2.tm_mon);
    }
    else
    {
        fine = 15 * (tm1.tm_mday - tm2.tm_mday);
    }
    cout << fine << endl;

    return 0;
}
