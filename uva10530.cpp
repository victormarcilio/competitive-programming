#include <bits/stdc++.h>

using namespace std;

int main()
{
	int guess;
	char c[100];
	while(scanf("%d\n", &guess), guess)
	{
		int MAX = 10, MIN = 0;
		
		while(gets(c), c[0] != 'r')
		{
			
			if(c[4] == 'h')
				MAX = min(MAX, guess - 1);
			else
			
				MIN = max(MIN, guess + 1);
			scanf("%d\n", &guess);
		}
		printf("Stan %shonest\n", guess >= MIN && guess <= MAX ? "may be " : "is dis");
	}
    return 0;
}
