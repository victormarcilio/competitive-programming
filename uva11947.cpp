#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, m, d, y, caso = 1;
	scanf("%d", &n);
	while(n--)
	{
		int mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		scanf("%2d%2d%4d", &m, &d, &y);
		if(y % 4 == 0 && y % 100 != 100 || y % 400 == 0)
			mes[1] = 29;
		m--;
		for(int i = 0; i < 280; i++)
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
					if(y % 4 == 0 && y % 100 != 100 || y % 400 == 0)
						mes[1] = 29;
					else 
						mes[1] = 28;
				}
			}
		}
		m++;
		printf("%d %02d/%02d/%d ", caso++, m, d, y);
		if(m == 1 && d > 20 || m == 2 && d < 20)
			printf("aquarius\n");
		else if(m == 2 || m == 3 && d < 21)
			printf("pisces\n");
		else if(m == 3 || m == 4 && d < 21)
			printf("aries\n");
		else if(m == 4 || m == 5 && d < 22)
			printf("taurus\n");
		else if(m == 5 || m == 6 && d < 22)
			printf("gemini\n");
		else if(m == 6 || m == 7 && d < 23)
			printf("cancer\n");
		else if(m == 7 || m == 8 && d < 22)
			printf("leo\n");
		else if(m == 8 || m == 9 && d < 24)
			printf("virgo\n");
		else if(m == 9 || m == 10 && d < 24)
			printf("libra\n");
		else if(m == 10 || m == 11 && d < 23)
			printf("scorpio\n");
		else if(m == 11 || m == 12 && d < 23)
			printf("sagittarius\n");
		else
			printf("capricorn\n");
	}
    return 0;
}
