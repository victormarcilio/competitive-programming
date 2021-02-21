#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, d, m, y;
	int mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int anos400 = 97 * 366 + 303 * 365;

	while(scanf("%d %d %d %d", &n, &d, &m, &y), d)
	{
		y += 400*(n/anos400);
		n = n%anos400;
		
		m--;
		
		if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			mes[1] = 29;
		else
			mes[1] = 28;
		while(n--)
		{
			d++;
			if(d > mes[m])
			{
				d = 1;
				m++;
				if(m == 12)
				{
					m = 0;
					y++;
					if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
						mes[1] = 29;
					else
						mes[1] = 28;
				}
			}
		}
		
		printf("%d %d %d\n", d, m + 1, y);
	}
	
    return 0;
}
