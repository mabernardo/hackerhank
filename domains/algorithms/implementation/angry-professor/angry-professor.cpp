/*
 * angry-professor.cpp
 * https://www.hackerrank.com/challenges/angry-professor
 *
 * Solution by mabernardo
 * https://github.com/mabernardo
 * https://www.hackerrank.com/mabernardo
 *
 */
#include <iostream>
#include <vector>
using namespace std;

bool cancelled(vector<int>& arr, int threshold)
{
	int ontime = 0;
	for (const auto &i : arr)
	{
		if (i <= 0)
			++ontime;
	}
	return ontime < threshold;
}

int main()
{
	int tests;
	cin >> tests;
	while (tests--)
	{
		int students;
		int threshold;
		vector<int> arrivals;

		cin >> students;
		cin >> threshold;

		while (students--)
		{
			int a;
			cin >> a;
			arrivals.push_back(a);
		}

		if (cancelled(arrivals, threshold))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}