#include <iostream>
using namespace std;

long sum_array(int* array, int size)
{
	long sum = 0;
	for (int i = 0; i < size; ++i)
		sum += array[i];

	return sum;
}	

int main()
{
	int array_size;
	int* array;
	cin >> array_size;

	if (array_size > 0)
	{
		array = new int[array_size];
		for (int i = 0; i < array_size; ++i)
			cin >> array[i];

		cout << sum_array(array, array_size);
		delete array;
	}
	return 0;
}