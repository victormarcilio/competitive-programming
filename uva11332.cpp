#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, aux;
	while(scanf("%d", &n), n)
	{
		while(n > 9)
		{
			aux = n%10;
			n = n/10;
			while(n)
			{
				aux += n%10;
				n = n/10;
			}
			n = aux;
		}
		printf("%d\n", n);
	}
}
