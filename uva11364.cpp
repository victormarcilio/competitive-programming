#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, menor, maior;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &a);
		scanf("%d", &menor);
		maior = menor;
		while(--a)
		{
			scanf("%d", &b);
			maior = max(maior, b);
			menor = min(menor, b);
		}
		printf("%d\n", (maior - menor) << 1);
	}
}
