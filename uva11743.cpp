#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, y;
	scanf("%d", &n);
	int v[10];
	while(n--)
	{
		int dobrados = 0, normais = 0;
		for(int i = 0; i < 8; i++)
		{
			scanf("%1d%1d", &x, &y);
			x <<= 1;
			dobrados += x/10 + x%10;
			normais += y/10 + y%10;
		}
		printf("%s\n", (normais + dobrados)%10 ? "Invalid" : "Valid");
	}
}
