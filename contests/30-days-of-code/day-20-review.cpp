/* day-20-review.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-20-review-plus-more-string-methods
 * by @mabernardo
 */
#include <cstring>
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    allocator_traits<string>::size_type len = s.size();
    char* s2 = new char[len + 1];
    s.copy(s2, len);
    s2[len] = '\0';

    vector<string> tokens;
    char* token = strtok(s2, " ![,?.\\_'@+]");
    while (token != NULL)
    {
        tokens.push_back(token);
        token = strtok(NULL, " ![,?.\\_'@+]");
    }

    cout << tokens.size() << endl;
    for (const string& str : tokens)
        cout << str << endl;

    delete[] s2;
    return 0;
}
