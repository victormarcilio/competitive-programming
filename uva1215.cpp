#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	int n, k, cuts[1000];
	scanf("%d", &n);
	char palavra[10100];
	bool cut[10100];
	int esq[200], dir[200];
	while (n--)
	{
		memset(cut, false, sizeof cut);
		int custo = 0;
		scanf("%d", &k);
		for(int i = 0; i < k; i++)
			scanf("%d", cuts + i);
		scanf("\n%s", palavra);
		for (int i = 0; i < k; i++)
		{
			memset(dir, 0, sizeof dir);
			memset(esq, 0, sizeof esq);
			for (int j = cuts[i]; palavra[j] && !cut[j]; j++)
				dir[palavra[j]]++;
			for (int j = cuts[i] - 1; ~j && !cut[j + 1]; j--)
				esq[palavra[j]]++;
			for (char c = 'a'; c <= 'z'; c++)
				if ((esq[c] && !dir[c]) || (!esq[c] && dir[c]))
					custo++;
			cut[cuts[i]] = true;
		}
		printf("%d\n", custo);
	}
}