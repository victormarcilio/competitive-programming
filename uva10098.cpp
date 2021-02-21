#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	char l[11];
	scanf("%d\n", &n);
	while(n--)
	{
		gets(l);
		int tam = strlen(l);
		sort(l, l + tam);
		
		do
		{
			printf("%s\n", l);
		} while(next_permutation(l, l + tam));	
		printf("\n");
	}
}
