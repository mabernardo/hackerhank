#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v)
{
    for (int n : v)
        cout << n << " ";
    cout << endl;
}

int main()
{
    int size, item;
    vector<int> v;

    cin >> size;
    while (size--)
    {
        cin >> item;
        v.push_back(item);
    }

    int last = v.back();
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        int next = *(it + 1);
        if (next > last)
            *it = next;
        else
        {
            *it = last;
            break;
        }

        print_vector(v);
    }
    print_vector(v);
    return 0;
}
