#include <bits/stdc++.h>

using namespace std;
int n, m;
bool f(int x, int y)
{
	if(x % m != y % m)
		return x % m < y % m;
	if((x & 1) ^ (y & 1))
		return x & 1;
	if((x & 1) && (y & 1))
		return x > y;
	return x < y;
}

int main()
{	
	
	int v[10000];
	while(scanf("%d %d", &n, &m), n)
	{
		printf("%d %d\n", n, m);
		for(int i = 0; i < n; i++)
			scanf("%d", v + i);
		sort(v, v + n, f);
		for(int i = 0; i < n; i++)
			printf("%d\n", v[i]);
	}
	printf("%d %d\n", n, m);
    return 0;
}
