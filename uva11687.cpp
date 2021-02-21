#include <bits/stdc++.h>

using namespace std;

int main()
{
	char n[1000010];
	while(gets(n), strcmp(n, "END"))
	{
		int i = 1;
		int novo = strlen(n);
		
		while(strcmp(n, "1"))
		{
			sprintf(n, "%d", novo);
			novo = strlen(n);
			i++;
		}
		printf("%d\n", i);
	}
	
}
