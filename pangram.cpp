#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


bool is_pangram(const char* sentence)
{
	int alphabet[26]{};
	int len = strlen(sentence);
	for (int i = 0; i < len; ++i)
	{
	
		if (isalpha(sentence[i]))
			alphabet[toupper(sentence[i]) - 65] = 1;
	}

	int sum = 0;
	for (int l = 0; l < 26; ++l)
		sum += alphabet[l];
	
	return (sum == 26);
}

int main()
{
	string sentence;
	getline(cin, sentence);
	if (is_pangram(sentence.c_str()))
		cout << "pangram";
	else
		cout << "not pangram";
	
	return 0;
}