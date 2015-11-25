#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    while (size--)
    {
        unsigned int num;
        cin >> num;

        num = ~num;
        cout << num << endl;
    }
    return 0;
}
