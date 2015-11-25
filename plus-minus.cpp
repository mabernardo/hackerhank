#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n > 0)
    {
        int* array = new int[n];

        for (int i = 0; i < n; ++i)
            cin >> array[i];

        int positives{0}, negatives{0}, zeroes{0};
        for (int i = 0; i < n; ++i)
        {
            if (array[i] > 0)
                positives++;
            else if (array[i] < 0)
                negatives++;
            else
                zeroes++;
        }
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << std::setprecision(3) << float(positives) / float(n) << endl;
        cout << std::setprecision(3) << float(negatives) / float(n) << endl;
        cout << std::setprecision(3) << float(zeroes) / float(n) << endl;

        delete[] array;
    }
    return 0;
}
