#include <bits/stdc++.h>

using namespace std;

int main()
{
	int l, c;
	while(scanf("%d %d", &l, &c), l || c)
	{
		int menor = min(l, c);
		if (!menor)
			printf("0 knights may be placed on a %d row %d column board.\n", l, c);
		else if(menor == 1)
			printf("%d knights may be placed on a %d row %d column board.\n", max(l, c), l, c);
		else if(menor == 2)
		{
			int maior = max(l, c);
			printf("%d knights may be placed on a %d row %d column board.\n", maior/4*4 + 2*(min(2, maior%4)), l, c);
		}
		else
		{
			int prod = l * c;
			printf("%d knights may be placed on a %d row %d column board.\n", prod/2 + prod%2, l, c);
		}
	}
}
