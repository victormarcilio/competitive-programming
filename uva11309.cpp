#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
	int res = 0;
	while(x)
	{
		res = res * 10 + x%10;
		x = x/10;
	}
	return res;
}

int main()
{
	int n, h, m;
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d:%d", &h, &m);
		
		do
		{
			m++;
			if(m == 60)
			{
				m = 0;
				h++;
				if(h == 24)
					h = 0;
			}
		}while(f(h * 100 + m) != h * 100 + m);
		printf("%02d:%02d\n", h, m);
	}
	
    return 0;
}
