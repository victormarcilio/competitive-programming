#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char palavra[10];
	scanf("%d\n", &n);
	while(n--)
	{
		gets(palavra);
		if(strlen(palavra) > 3)
			printf("3\n");
		else if((palavra[0] == 'o') + (palavra[1] == 'n') + (palavra[2] == 'e') > 1)
			printf("1\n");
		else
			printf("2\n");
	}
}
