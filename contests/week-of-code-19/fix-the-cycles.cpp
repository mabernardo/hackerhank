/* fix-the-cycles.cpp
 * https://www.hackerrank.com/contests/w19/challenges/fix-the-cycles
 * by @mabernardo
 */
 #include <iostream>
 using namespace std;

 int main()
 {
 	int a, b, c, d, e, f;
 	int sum1, sum2, sum3;

 	cin >> a >> b >> c >> d >> e >> f;
 	sum1 = b + c + d + a;
 	sum2 = b + f + a;
 	sum3 = e + d + a;

	int min_sum = min(min(sum1, sum2), sum3);
	for (int i = 0; i <= 20; ++i)
	{
		if (min_sum + i >= 0)
		{
			min_sum = i;
			break;
		}
	}
	if (min_sum < 0)
	{
		min_sum = -1;
	}
 	cout << min_sum << endl;
 	return 0;
 }