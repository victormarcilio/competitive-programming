#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &a, &b);
		a-= 2;
		b-= 2;
		printf("%d\n", (a/3 + (a % 3 ? 1 : 0)) * (b/3 + (b % 3 ? 1 : 0)));
	}
}
