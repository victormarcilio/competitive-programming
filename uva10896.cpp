#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	char text[100], palavra[20], *p;
	while(n--)
	{
		gets(text);
		gets(palavra);
		int k = 0, tam = strlen(palavra);
		char possiveis[30];
		p = strtok(text, " ");
		while(p)
		{
			if(strlen(p) == tam)
			{
				int d = (p[0] - palavra[0] + 26)%26;
				for(int i = 1; palavra[i]; i++)
					if((p[i] - palavra[i] + 26)%26 != d)
						goto prox;
				possiveis[k++] = 'a' + d;
			}
			prox: p = strtok(NULL, " ");
		}
		possiveis[k] = 0;
		sort(possiveis, possiveis + k);
		printf("%s\n", possiveis);
	}
}
