#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, k;
	cin >> n;
	cin.ignore();
	string s1, s2, s3, s4, s5, l2;
	while (n--)
	{
		getline(cin, s1, '<');
		getline(cin, s2, '>');
		getline(cin, s3, '<');
		getline(cin, s4, '>');
		getline(cin, s5);
		getline(cin, l2);

		l2.replace(l2.find("..."), 3, s4 + s3 + s2 + s5);
		cout << s1 + s2 + s3 + s4 + s5 << endl << l2 << endl;
	}
}