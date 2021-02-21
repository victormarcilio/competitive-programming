#include <bits/stdc++.h>

using namespace std;

int main()
{
	char st[1000];
	while(gets(st))
	{
		for(int i = 0; st[i]; i++)
			printf("%c", st[i] - 7);
		printf("\n");
	}
	
    return 0;
}
