/* day-18-queues-stacks.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-18-queues-stacks
 * by @mabernardo
 */
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

class Palindrome
{
private:
    queue<char> q;
    stack<char> s;
public:
    void pushCharacter(char c)
    {
        s.push(c);
    }

    char popCharacter()
    {
        char c = s.top();
        s.pop();
        return c;
    }

    void enqueueCharacter(char c)
    {
        q.push(c);
    }

    char dequeueCharacter()
    {
        char c = q.front();
        q.pop();
        return c;
    }
};

int main()
{
    // read the string s.
    string s;
    getline(cin, s);

  	// create the Palindrome class object p.
    Palindrome p;

    // push all the characters of string s to stack.
    for (unsigned int i = 0; i < s.length(); i++)
    {
        p.pushCharacter(s[i]);
    }

    // enqueue all the characters of string s to queue.
    for (unsigned int i = 0; i < s.length(); i++)
    {
        p.enqueueCharacter(s[i]);
    }

    bool f = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (unsigned int i = 0; i < s.length(); i++)
    {
        if (p.popCharacter() != p.dequeueCharacter())
        {
            f = false;
            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (f)
    {
        cout << "The word, " << s << ", is a palindrome.";
    }
    else
    {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}
