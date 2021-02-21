#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int zero, outro, a, caso = 1;
	while(scanf("%d", &n), n)
	{
		zero = outro = 0;
		while(n--)
		{
			scanf("%d", &a);
			if(a)
				outro++;
			else
				zero++;
		}
		printf("Case %d: %d\n", caso++, outro - zero);
	}
}
