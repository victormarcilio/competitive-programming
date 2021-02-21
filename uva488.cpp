#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, a, b;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &a, &b);
		while (b--)
		{
			for (int i = 1; i <= a; i++)
			{
				for (int k = 0; k < i; k++)
					printf("%d", i);
				printf("\n");
			}
			for(int i = a - 1; i > 0; i--)
			{
				for (int k = 0; k < i; k++)
					printf("%d", i);
				printf("\n");
			}
			if(b)
				printf("\n");
		}

		if (n)
			printf("\n");
	}
}