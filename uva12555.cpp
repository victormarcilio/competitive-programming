#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, n, b, c = 1;
	char t;
	scanf("%d", &n);
	while(n--)
	{
		b = 0;
		scanf("%d", &a);
		do{
			scanf("%c", &t);
			if(isdigit(t))
				b = t - '0';
		}while(t != '\n');
	
		printf("Case %d: %.5g\n", c++, a * 0.5 + b * 0.05);
	}
}
