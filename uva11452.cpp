#include <bits/stdc++.h>
#include <regex>
using namespace std;
bool check(char *linha, int k)
{
	for (int i = 0; i < k; i++)
		if (linha[i] != linha[k + i])
			return false;
	k <<= 1;
	for (int i = 0; linha[k + i]; i++)
		if (linha[i] != linha[k + i])
			return false;

	return true;
}
int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	int n;
	char linha[2010];
	scanf("%d\n", &n);
	while (n--)
	{
		scanf("%s\n", linha);
		int len = strlen(linha);
		for (int k = len / 2; ; k--)
			if (check(linha, k))
			{
				for (int i = 0, j = len % k; i < 8; i++)
				{
					printf("%c", linha[j]);
					j++;
					if (j == k)
						j = 0;
				}
				printf("...\n");
				break;
			}
	}
}