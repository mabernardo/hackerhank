/* day-13-abstract-classes
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-13-abstract-classes
 */
#include <iostream>
using namespace std;

class Book
{
protected:
    string title;
    string author;
public:
    Book(string t,string a)
    {
        title = t;
        author = a;
    }
    virtual void display()=0;

};

class MyBook : public Book
{
protected:
    int price;
public:
    MyBook(string title, string author, int price) : Book(title, author),
            price(price) { }
    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    string title, author;
    int price;
    getline(cin, title);
    getline(cin, author);
    cin >> price;
    MyBook novel(title, author, price);
    novel.display();

    return 0;
}
