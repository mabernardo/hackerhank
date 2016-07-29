#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

char* strrev(char* str)
{
	int len = strlen(str);
	char* tmp = new char[len + 1];
	
	for (int i = 0; i < len; ++i)
		tmp[i] = str[len - i - 1];
	tmp[len] = '\0';

	strcpy(str, tmp);
	delete tmp;

	return str;
}


bool is_funny(const char* str)
{
	int len = strlen(str);
	char* rev = new char[len + 1];
	bool funny = true;

	strcpy(rev, str);
	strrev(rev);
	for (int i = 1; i < len; ++i)
	{
		int sum = 0;
		sum = abs(str[i] - str[i - 1]) - abs(rev[i] - rev[i - 1]);
		if (sum != 0)
		{
			funny = false;
			break;
		}
	}
	delete rev;
	
	return funny;
}


int main()
{
	int t = 0;
	string input;
	getline(cin, input);
	stringstream strinput(input);
	strinput >> t;
	
	while (t--)
	{
		string str;
		getline(cin, str);

		if (is_funny(str.c_str()))
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
	}
	return 0;
}