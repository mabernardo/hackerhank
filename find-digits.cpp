#include <iostream>
using namespace std;

int find_digits(int number)
{
    int count = 0;
    int digit;
    string const s = to_string(number);

    for (int i = 0; i < s.size(); i++)
    {
        digit = stoi(s.substr(i, 1));
        if (digit != 0 && number % digit == 0)
            ++count;
    }
    return count;
}

int main()
{
    int size, num;
    cin >> size;

    while(size--)
    {
        cin >> num;

        cout << find_digits(num) << endl;
    }
    return 0;
}
