/* the-ultimate-question.cpp
 * https://www.hackerrank.com/contests/indeed-prime-codesprint/challenges/the-ultimate-question
 *
 * Code by maberna (mabernardo@gmail.com)
 */
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c == 42)
        cout << a << "+" << b << "+" << c << endl;
    else if (a + b * c == 42)
        cout << a << "+" << b << "*" << c << endl;
    else if (a * b + c == 42)
        cout << a << "*" << b << "+" << c << endl;
    else if (a * b * c == 42)
        cout << a << "*" << b << "*" << c << endl;
    else
        cout << "This is not the ultimate question" << endl;

    return 0;
}
