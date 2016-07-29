#include <iostream>
using namespace std;

int main()
{
    int h;
    cin >> h;

    for (int i = 0, j = h - 1; i < h, j >= 0; ++i, --j)
    {
        for (int b = 0; b < j; ++b)
            cout << " ";

        for (int s = 0; s <= i; ++s)
            cout << "#";

        cout << endl;
    }
    return 0;
}
