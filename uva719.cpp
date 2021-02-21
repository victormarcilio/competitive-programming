#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	char st[20010];
	scanf("%d\n", &n);
	while (n--)
	{
		int ians = 1;
		memset(st, 0, sizeof st);
		scanf("%s\n", st);
		string v = st;
		int len = v.size();
		for (int i = 1; i < len; i++)
		{
			st[len + i - 1] = st[i - 1];
			if (v > &st[i])
			{
				ians = i + 1;
				v = &st[i];
			}
		}
		printf("%d\n", ians);
	}
}