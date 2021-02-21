#include <bits/stdc++.h>

using namespace std;
int main()
{
	char code[15];
	gets(code);
	while(gets(code), strcmp(code, "___________"))
	{
		int c = 0;
		for(int i = 9, k = 0; i > 0; i--, k++)
			if(code[i] == 'o')
				c += (1 << k);
			else if(code[i] == '.')
				k--;
		printf("%c", c);
	}
    return 0;
}
