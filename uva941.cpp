#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	long long k;
	cin >> n;
	cin.ignore();
	string s1;
	long long fat[21];
	fat[0] = 1;
	for (int i = 1; i < 21; i++)
		fat[i] = i * fat[i - 1];
	while (n--)
	{
		getline(cin, s1);
		cin >> k;
		cin.ignore();
		sort(s1.begin(), s1.end());
		string s2;
		int pos = s1.size() - 1;;
		while(s1.size())
		{
			s2 += s1[k / fat[pos]];
			s1.erase(k / fat[pos], 1);
			k = k % fat[pos];
			pos--;
		}
		cout << s2 << endl;
	}
}