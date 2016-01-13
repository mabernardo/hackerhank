/* day-12-inheritance.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/inheritance
 */
#include <iostream>
using namespace std;

class Student
{
    protected:
        string firstName;
        string lastName;
        int phone;
    public:
        Student(string fname, string lname, int p)
        {
            firstName = fname;
            lastName = lname;
            phone = p;
        }

        void display()
        {
            cout << "First Name: " << firstName << endl;
            cout << "Last Name: " << lastName << endl;
            cout << "Phone: " << phone;
        }
};

class Grade : public Student{
    private:
        int score;
    public:
        Grade(string fname, string lname, int phone, int grade) :
                Student(fname, lname, phone), score(grade) { }

        char calculate()
        {
            if (score < 40)
                return 'D';
            else if (score >= 40 && score < 60)
                return 'B';
            else if (score >= 60 && score < 75)
                return 'A';
            else if (score >= 75 && score < 90)
                return 'E';
            else
                return 'O';
        }
};

int main()
{
    string firstName,lastName;
    int score, phone;
    cin >> firstName;
    cin >> lastName;
    cin >> phone;
    cin >> score;
    Student *stu = new Grade(firstName, lastName, phone, score);
    stu->display();
    Grade *g= (Grade*) stu;
    cout << endl << "Grade: " << g->calculate();
    delete stu;

    return 0;
}
