#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, hand = 1, n, pontos, odd;
	char carta[30];
	scanf("%d", &t);
	while(t--)
	{
		if(hand > 1)
			printf("\n");
		odd = 0;
		scanf("%d\n", &n);
		pontos = n >> 1;
		while(n--)
		{
			gets(carta);
			if(strstr(carta, "twenty-") == carta || strstr(carta, "one of t") == carta || strstr(carta, "fool") == carta)
			{
				odd++;
				pontos += 4;
			}
			if(carta[0] == 'k' && carta[1] == 'i')
				pontos += 4;
			else if(carta[0] == 'q')
				pontos += 3;
			else if(carta[0] == 'k' && carta[1] == 'n')
				pontos += 2;
			else if(carta[0] == 'j')
				pontos += 1;
			
		}
		if(odd == 3)
			pontos -= 36;
		else if(odd == 2)
			pontos -= 41;
		else if(odd)
			pontos -= 51;
		else
			pontos -= 56;
		
		if(pontos >= 0)
			printf("Hand #%d\nGame won by %d point(s).\n", hand++, pontos);
		else
			printf("Hand #%d\nGame lost by %d point(s).\n", hand++, -pontos);
	}
}
