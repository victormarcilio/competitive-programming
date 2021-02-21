#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int primeira = true;
	int n;
	while (~scanf("%d\n", &n))
	{
		if (!primeira)
			printf("\n");
		primeira = false;
		char linha[5000];
		map<string, int> m;
		while (scanf("%[^\n]\n", linha), strcmp(linha, "EndOfText"))
		{
			string s(linha);
			regex e("[[:alpha:]]+");
			sregex_iterator it(s.cbegin(), s.cend(), e);
			sregex_iterator end;

			for (; it != end; it++)
			{
				string temp = it->str(0);
				for (auto &i : temp)
					i = tolower(i);
				m[temp]++;
			}
		}
		int k = 0;
		for (auto it : m)
			if (it.second == n)
				k += printf("%s\n", it.first.c_str());
		if (!k)
			printf("There is no such word.\n");
	}
}