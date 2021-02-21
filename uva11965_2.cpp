#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	int n, l, caso = 1;
	char linha[1000];
	cin >> n;
	while (n--)
	{
		cin >> l;
		cin.ignore();
		printf("Case %d:\n", caso++);
		while (l--)
		{
			string s;
			getline(cin, s);
			cout << regex_replace(s, regex("[[:blank:]]+"), " ") << endl;
		}
		if (n)
			printf("\n");
	}
}