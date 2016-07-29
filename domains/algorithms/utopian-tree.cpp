#include <iostream>
using namespace std;

int grow(int cycles)
{
	int size = 1;
	for (int i = 1; i <= cycles; ++i)
	{
		if (i % 2 == 0)
			size++;
		else
			size *= 2;
	}
	return size;
}

int main()
{
	int tests;
	cin >> tests;
	
	while (tests--)
	{
		int size;
		int cycles;

		cin >> cycles;
		size = grow(cycles);		
		cout << size << endl;
	}
	
	return 0;
}