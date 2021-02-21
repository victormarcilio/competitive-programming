#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char n1[100];
	char n2[100];
	scanf("%d\n", &n);
	prox: while(n--)
	{
		gets(n1);
		gets(n2);
		if(strlen(n1) != strlen(n2))
		{
			printf("No\n");
			continue;
		}
		for(int i = 0; n1[i]; i++)
			if((!strchr("aeiou", n1[i]) || !strchr("aeiou", n2[i])) && n1[i] != n2[i])
			{
				printf("No\n");
				goto prox;
			}
		printf("Yes\n");
	}
}