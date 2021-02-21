#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, c, caso = 1;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &a, &b, &c);
		printf("Case %d: %s\n", caso++, a <= 20 && b <= 20 && c <= 20 ? "good" : "bad");
	}
}
