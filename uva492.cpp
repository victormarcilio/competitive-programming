#include <bits/stdc++.h>

using namespace std;

int main()
{
	char c, p;
	while(~scanf("%c", &c))
	{
		if(isalpha(c))
		{
			if(strchr("aeiouAEIOU", c))
			{
				printf("%c", c);
				while(scanf("%c", &c), isalpha(c))
					printf("%c", c);
				printf("ay%c", c);
			}
			else
			{
				p = c;
				while(scanf("%c", &c), isalpha(c))
					printf("%c", c);
				printf("%cay%c", p, c);
			}
		}
		else
			printf("%c", c);
	}
	
    return 0;
}
