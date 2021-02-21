#include <bits/stdc++.h>

using namespace std;

unsigned int f(unsigned int x)
{
	int res = 0;
	while(x)
	{
		res = res * 10 + x%10;
		x = x/10;
	}
	return res;
}

int main()
{
	int n, x;
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%u", &x);
		int c = 0;
		while (x != f(x))
		{
			x += f(x);
			c++;
		}
		printf("%d %u\n", c, x);
	}
	
    return 0;
}
