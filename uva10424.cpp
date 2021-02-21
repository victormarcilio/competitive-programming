#include <bits/stdc++.h>

using namespace std;

int main()
{
	char nome1[10000], nome2[10000];
	while(gets(nome1))
	{
		gets(nome2);
		int sum1 = 0;
		
		for(int i = 0; nome1[i]; i++)
			if(isalpha(nome1[i]))
				sum1 += tolower(nome1[i]) - 'a' + 1;
		
		while(sum1 > 9)
		{
			sprintf(nome1, "%d", sum1);
			sum1 = 0;
			for(int i = 0; nome1[i]; i++)
				sum1 += nome1[i] - '0';
		}
		
		int sum2 = 0;
		for(int i = 0; nome2[i]; i++)
			if(isalpha(nome2[i]))
				sum2 += tolower(nome2[i]) - 'a' + 1;
		
		while(sum2 > 9)
		{
			sprintf(nome1, "%d", sum2);
			sum2 = 0;
			for(int i = 0; nome1[i]; i++)
				sum2 += nome1[i] - '0';
		}
		if(sum2 > sum1)
			swap(sum2, sum1);
		if(sum1 == sum2)
			printf("100.00 %%\n");
		else
			printf("%.2lf %%\n", 100.0*sum2/sum1);
	}
	
}
