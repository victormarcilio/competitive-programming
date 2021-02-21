#include <bits/stdc++.h>
#include <regex>
using namespace std;

int checki(char *s, int pos, int k)
{
	int res = 1, esq = pos - 1, dir = pos + 1;
	while (s[dir] && ~esq)
	{
		if (s[dir++] != s[esq--])
			k--;
		if (k < 0)
			return res;
		res += 2;
	}
	return res;
}

int checkp(char *s, int pos, int k)
{
	int esq = pos - 1;

	int res = 0;
	while (s[pos] && ~esq)
	{
		if (s[pos++] != s[esq--])
			k--;
		if (k < 0)
			return res;
		res += 2;
	}
	return res;
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	int n, k;
	scanf("%d\n", &n);
	char palavra[1010];
	while (n--)
	{
		scanf("%s %d\n", palavra, &k);
		int res = 0;
		for (int i = 0; palavra[i]; i++)
			res = max(res, checki(palavra, i, k));
		for (int i = 1; palavra[i]; i++)
			res = max(res, checkp(palavra, i, k));


		printf("%d\n", res);
	}
}