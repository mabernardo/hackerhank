/* box-it.cpp
 * https://www.hackerrank.com/contests/code-cpp-3/challenges/box-it
 * by @mabernardo
 */
#include <iostream>
using namespace std;

int BoxesCreated, BoxesDestroyed;

class Box
{
public:

    Box() : l(0), b(0), h(0)
    {
        BoxesCreated++;
    }

    Box(int l, int b, int h) : l(l), b(b), h(h)
    {
        BoxesCreated++;
    }

    Box(const Box& box) : l(box.l), b(box.b), h(box.h)
    {
        BoxesCreated++;
    }

    ~Box()
    {
        BoxesDestroyed++;
    }

    int getLength() const
    {
        return l;
    }

    int getBreadth() const
    {
        return b;
    }

    int getHeight() const
    {
        return h;
    }

    long long CalculateVolume()
    {
        return long(l) * long(b) * long(h);
    }

    bool operator<(Box &box)
    {
        if (this->l < box.l)
            return true;
        if (this->b < box.b && this->l == box.l)
            return true;
        if (this->h < box.h && this->b == box.b && this->l == box.l)
            return true;

        return false;
    }

private:
    int l, b, h;

};

ostream& operator<<(ostream& out, Box box)
{
    return out << box.getLength()
            << " " << box.getBreadth()
            << " " << box.getHeight();
}

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout<<"Lesser"<<endl;
            }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout << "Boxes Created : " << BoxesCreated << endl
            << "Boxes Destroyed : " << BoxesDestroyed << endl;
}
