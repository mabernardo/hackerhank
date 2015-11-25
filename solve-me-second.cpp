#include <iostream>
using namespace std;

int main()
{
	int lines;
	int num1, num2;
	
	cin >> lines;
	for (int l = 0; l < lines; ++l)
	{
		cin >> num1 >> num2;
		cout << num1 + num2 << endl;
	}
	return 0;
}