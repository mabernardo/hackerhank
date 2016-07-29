#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 0)
    {
        int** matrix = new int*[n];
        for (int i = 0; i < n; ++i)
            matrix[i] = new int[n];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];

        int diag1 = 0, diag2 = 0;
        for (int i = 0, j = n - 1; i < n, j >= 0; ++i, --j)
        {
            diag1 += matrix[i][i];
            diag2 += matrix[i][j];
        }
        cout << abs(diag1 - diag2) << endl;

        for (int i = 0; i < n; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }
    return 0;
}
