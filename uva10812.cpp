#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, c, d;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &a, &b);
		c = (a + b) >> 1;
		d = a - ((a + b) >> 1);
		
		if(c + d == a && c - d == b && a >= b)
			printf("%d %d\n", c, d);
		else
			printf("impossible\n");
	}
}
