#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, x;
	char linha[100000];
	while(scanf("%d", &n), n)
	{
		prox:
		while (scanf("%d", &x), x)
		{
			stack<int> s;
			s.push(0);
			int k = 1;
			while(k < x)
				s.push(k++);
			k++;
			for(int i = 1; i < n; i++)
			{
				scanf("%d", &x);
				while(k <= x && s.top() != x)
					s.push(k++);
				if(s.top() != x)
				{
					printf("No\n");
					gets(linha);
					goto prox;
				}
				else
					s.pop();
			}
			printf("Yes\n");
		}
		printf("\n");
	}
    return 0;
}
