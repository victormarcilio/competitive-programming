#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &a);
		a = (a * 567 / 9 + 7492) * 235 / 47 - 498;
		printf("%d\n", abs(a/10%10));
	}
}
