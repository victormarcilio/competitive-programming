#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	int primeiro = true;
	prox: while (~scanf("%d\n", &n))
	{
		if (!primeiro)
			printf("\n");
		primeiro = false;
		char c;
		vector<char> v[2];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%c\n", &c);
				v[i].push_back(c);
			}
		bool mudou = true;
		map<char, char> m;
		while (mudou)
		{
			mudou = false;
			for (int i = 0; i < n; i++)
			{
				if (isdigit(v[0][i]) && isalpha(v[1][i]))
				{
					mudou = true;
					if (m.find(v[0][i]) != m.end())
					{
						if (m[v[0][i]] != v[1][i])
						{
							printf("NO\n");
							goto prox;
						}
						else
							v[0][i] = v[1][i];
					}
					else
						v[0][i] = m[v[0][i]] = v[1][i];
				}
				else if (isalpha(v[0][i]) && isdigit(v[1][i]))
				{
					mudou = true;
					if (m.find(v[1][i]) != m.end())
					{
						if (m[v[1][i]] != v[0][i])
						{
							printf("NO\n");
							goto prox;
						}
						else
							v[1][i] = v[0][i];
					}
					else
						v[1][i] = m[v[1][i]] = v[0][i];
					
				}
				else if (isalpha(v[0][i]) && isalpha(v[1][i]) && v[0][i] != v[1][i])
				{
					printf("NO\n");
					goto prox;
				}
				else if (isdigit(v[0][i]) && isdigit(v[1][i]))
				{
					if (m.find(v[0][i]) != m.end())
					{
						v[0][i] = m[v[0][i]];
						mudou = true;
					}

					if (m.find(v[1][i]) != m.end())
					{
						v[1][i] = m[v[1][i]];
						mudou = true;
					}
				}
			}
		}
		printf("YES\n");
		for (auto it : m)
			printf("%c %c\n", it.first, it.second);
	}
}