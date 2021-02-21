#include <bits/stdc++.h>

using namespace std;

int main()
{
	char st[1000];
	while(gets(st))
	{
		if(isdigit(st[0]))
		{
			for(int i = strlen(st) - 1; ~i; i--)
			{
				if(st[i] == '1')
				{
					printf("%c", 100 + 10*(st[i - 1] - '0') + st[i - 2] - '0');
					i -= 2;
				}
				else
				{
					printf("%c", 10*(st[i] - '0') + st[i - 1] - '0');
					i--;
				}
			}
		}
		else
		{
			for(int i = strlen(st) - 1; ~i; i--)
			{
				int v = st[i];
				while(v)
				{
					printf("%d", v%10);
					v = v/10;
				}
			}
		}
		printf("\n");
	}
	
    return 0;
}
