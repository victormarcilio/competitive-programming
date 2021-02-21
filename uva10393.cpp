#include <bits/stdc++.h>
#include <regex>
using namespace std;

bool pode(string st, set<char> &s)
{
	for (auto i : st)
		if (s.find(i) == s.end())
			return false;
	return true;
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	int n, f, v;
	char fingers[11][7] = {"", "qaz", "wsx", "edc", "rfvtgb", "", "", "yhnujm", "ik", "ol", "p"};
	while (~scanf("%d %d", &f, &n))
	{
		set<char> s;
		for (char c = 'a'; c <= 'z'; c++)
			s.insert(c);
		for (int i = 0; i < f; i++)
		{
			scanf("%d", &v);
			for (int j = 0; fingers[v][j]; j++)
				s.erase(fingers[v][j]);
		}
		int maxlen = 0;
		set<string> words;
		char palavra[100];
		for (int i = 0; i < n; i++)
		{
			scanf("\n%s", palavra);
			int len = strlen(palavra);
			if (pode(palavra, s))
				if (len == maxlen)
					words.insert(palavra);
				else if (len > maxlen)
				{
					words.clear();
					maxlen = len;
					words.insert(palavra);
				}
		}
		printf("%d\n", words.size());
		for (auto i : words)
			printf("%s\n", i.c_str());
	}
}