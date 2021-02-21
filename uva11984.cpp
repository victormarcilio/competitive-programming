#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, c, f, caso = 1;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &c, &f);
		double F = c*9.0/5 + 32 + f;
		printf("Case %d: %.2f\n", caso++, (F - 32.)*5/9);
	}
}
