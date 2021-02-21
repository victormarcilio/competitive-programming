#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x;
	scanf("%d\n", &n);
	char s[10000];
	while(n--)
	{
		gets(s);
		if(!strcmp(s, "1") || !strcmp(s, "4") || !strcmp(s, "78"))
			printf("+\n");
		else
		{
			int tam = strlen(s);
			if(s[tam - 1] == '5' && s[tam - 2] == '3')
				printf("-\n");
			else if(s[0] == '9' && s[strlen(s) - 1] == '4')
				printf("*\n");
			else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
				printf("?\n");
			
		}
	}
}
