#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int t, n;
	scanf("%d\n", &n);
	while (n--)
	{
		char linha[100010], sub[1010];
		scanf("%s\n", linha);
		scanf("%d\n", &t);
		while (t--)
		{
			scanf("%s\n", sub);
			printf("%c\n", strstr(linha, sub) ? 'y' : 'n');
		}
	}
}
