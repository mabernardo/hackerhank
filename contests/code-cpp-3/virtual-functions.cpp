/* virtual-functions.cpp
 * https://www.hackerrank.com/contests/code-cpp-3/challenges/virtual-functions
 * by @mabernardo
 */
#include <vector>
#include <iostream>
using namespace std;

class Person
{
public:
    virtual void putdata()
    {
        cout << name << " " << age << " ";
    }

    virtual void getdata()
    {
        cin >> name;
        cin >> age;
    }

private:
    string name;
    int age;
};

class Professor : public Person
{
public:
    static int next_id;

    void putdata()
    {
        Person::putdata();
        cout << publications << " " << cur_id << endl;
    }

    void getdata()
    {
        Person::getdata();
        cin >> publications;
        cur_id = Professor::next_id++;
    }

private:
    int publications;
    int cur_id;
};
int Professor::next_id = 1;

class Student : public Person
{
public:
    static int next_id;

    Student() : sum(0) {}

    void putdata()
    {
        Person::putdata();
        cout << sum << " " << cur_id << endl;
    }

    void getdata()
    {
        Person::getdata();
        int mark;
        for (int i = 0; i < 6; ++i)
        {
            cin >> mark;
            marks.push_back(mark);
            sum += mark;
        }
        cur_id = next_id++;
    }

private:
    vector<int> marks;
    int cur_id;
    int sum;
};
int Student::next_id = 1;


int main()
{
    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n; i++)
    {
        cin >> val;
        if(val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
