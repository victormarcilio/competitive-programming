#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, N, x1, x2, y1, y2;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &N);
		while(n--)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if(x1 == x2 &&  y1 == y2)
				printf("0\n");
			else if(abs(x1 - x2) == abs(y1 - y2))
				printf("1\n");
			else if((x1 + y1)%2 != (x2 + y2)%2)
				printf("no move\n");
			else
				printf("2\n");
		}
	}
}
