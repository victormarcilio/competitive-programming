#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("C:/Users/slipn/Desktop/in", "r", stdin);
//	freopen("C:/Users/slipn/Desktop/out", "w", stdout);

	int n, l;
	scanf("%d %d\n", &n, &l);
	map<string, string> m;
	char s1[100], s2[100];
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s\n", s1, s2);
		m[s1] = s2;
	}
	for (int i = 0; i < l; i++)
	{
		scanf("%s\n", s1);
		if (m.find(s1) != m.end())
			printf("%s\n", m[s1].c_str());
		else
		{
			int len = strlen(s1) - 1;
			if (s1[len] == 'y' && !strchr("aeiou", s1[len -1]))
				strcpy(&s1[len], "ies");
			else
			{
				if (strchr("osx", s1[len]) || s1[len] == 'h' && strchr("cs", s1[len - 1]))
					strcat(s1, "es");
				else
					strcat(s1, "s");
			}
			printf("%s\n", s1);
		}
	}

}