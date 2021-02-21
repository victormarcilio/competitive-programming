#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int cont = 1, r, c;
	char pz[12][12];
	int nums[12][11];
	while (scanf("%d %d\n", &r, &c) == 2)
	{
		if (cont > 1)
			printf("\n");
		memset(pz, 0, sizeof pz);
		memset(nums, 0, sizeof nums);
		for (int i = 1; i <= r; i++)
		{
			scanf("%s", &pz[i][1]);
			for (int j = 1; j <= c; j++)
				if (pz[i][j] == '*')
					pz[i][j] = 0;
		}
		int k = 1;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				if (pz[i][j] && (!pz[i - 1][j] || !pz[i][j - 1]))
					nums[i][j] = k++;
		printf("puzzle #%d:\nAcross\n", cont++);
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				if (pz[i][j] && !pz[i][j - 1])
					printf("%3d.%s\n", nums[i][j], &pz[i][j]);
		printf("Down\n");
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				if (pz[i][j] && !pz[i - 1][j])
				{
					printf("%3d.%c", nums[i][j], pz[i][j]);
					for (int k = i + 1; pz[k][j]; k++)
						printf("%c", pz[k][j]);
					printf("\n");
				}
	}
}