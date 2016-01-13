/* day-8-dictionaries-and-maps.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-8-dictionaries-and-maps
 */
#include <map>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> book;
    cin.ignore(10000, '\n');

    while (n--)
    {
        string name;
        int number;

        getline(cin, name);
        cin >> number;
        cin.ignore(10000, '\n');

        pair<string, int> p(name, number);
        book.insert(p);
    }

    string query;
    while (getline(cin, query))
    {
        auto entry = book.find(query);
        if (entry != book.end())
        {
            cout << entry->first << "=" << entry->second << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }
    return 0;
}
