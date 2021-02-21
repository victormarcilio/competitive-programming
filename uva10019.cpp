#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n;
	scanf("%d", &n);
	char aux[100];
	while(n--)
	{
		int x;
		scanf("%d", &x);
		bitset<100> b(x);
		int b1 = b.count(), b2 = 0;
		
		sprintf(aux, "0x%d", x);
		sscanf(aux, "%i", &x);
		b = bitset<100>(x);
		b2 = b.count();
		printf("%d %d\n", b1, b2);
	}
	
    return 0;
}
