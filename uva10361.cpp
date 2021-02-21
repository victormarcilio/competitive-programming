#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, k ;
	cin >> n;
	cin.ignore();
	string s1, l2;
	while (n--)
	{
		getline(cin, s1);
		getline(cin, l2);
		string s2 = s1.substr(s1.find_first_of('<') + 1, s1.find_first_of('>') - s1.find_first_of('<') - 1);
		string s3 = s1.substr(s1.find_first_of('>') + 1, s1.find_last_of('<') - s1.find_first_of('>') - 1);
		string s4 = s1.substr(s1.find_last_of('<') + 1, s1.find_last_of('>') - s1.find_last_of('<') - 1);
		string s5 = s1.substr(s1.find_last_of('>') + 1);
		while ((k = s1.find('<')) != string::npos)
			s1.replace(k, 1, "");
		while ((k = s1.find('>')) != string::npos)
			s1.replace(k, 1, "");
		l2.replace(l2.find("..."), 3, s4 + s3 + s2 + s5);
		cout << s1 << endl << l2 << endl;
	}
}