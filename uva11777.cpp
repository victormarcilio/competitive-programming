#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, a[3], caso = 1, A, B, C, D;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d %d %d %d %d", &A, &B, &C, &D, a, a + 1, a + 2);
		sort(a, a + 3);
		int n = A + B + C + D + ((a[1] + a[2]) >> 1);
		printf("Case %d: ", caso++);
		switch(n)
		{
			case 90 ... 100: printf("A\n"); break;
			case 80 ... 89: printf("B\n"); break;
			case 70 ... 79: printf("C\n"); break;
			case 60 ... 69: printf("D\n"); break;
			default:
				printf("F\n");
		}
	}
    return 0;
}
