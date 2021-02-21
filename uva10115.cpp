#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	string de, para, res;
	while (cin >> n, n)
	{
		vector<pair<string, string>> v;
		cin.ignore();
		while (n--)
		{
			getline(cin, de);
			getline(cin, para);
				v.push_back({ de, para });
		}
		getline(cin, res);
		int offset;
		for (auto i : v)
			while ((offset = res.find(i.first)) != string::npos)
				res.replace(offset, i.first.size(), i.second);
		printf("%s\n", res.c_str());
	}
}
