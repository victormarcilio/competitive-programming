#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	int n, caso = 1;
	char st[40];
	scanf("%d\n", &n);
	int v[500];
	v['A'] = 0;  v['C'] = 1; v['G'] = 2; v['T'] = 3;
	while (n--)
	{
		scanf("%s\n", st);
		int len = strlen (st);
		printf("Case %d: (%d:", caso++, len);
		unsigned long long res = 0, m = 1;
		for (int i = 1; i < len; i++)
			m *= 4;
		for (int i = 0; st[i]; i++, m /= 4)
			res += v[st[i]] * m;

		printf("%llu)\n", res);
	}
}