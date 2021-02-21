#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	char st[20010], v[10010];
	scanf("%d\n", &n);
	while (n--)
	{
		int ians = 1;
		memset(st, 0, sizeof st);
		scanf("%s\n", st);
		strcpy(v, st);
		int len = strlen(v);
		for (int i = 1; i < len; i++)
		{
			st[len + i - 1] = st[i - 1];
			if (strcmp(v, &st[i]) > 0)
			{
				ians = i + 1;
				strcpy(v, &st[i]);
			}
		}
		printf("%d\n", ians);
	}
}