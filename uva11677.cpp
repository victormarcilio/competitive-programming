#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int h1, m1, h2, m2;
	
	while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2), h1 || m1 || h2 || m2)
	{
		int t = 0;
		while(h1 != h2 || m1 != m2)
		{
			m1++;
			if(m1 == 60)
			{
				m1 = 0;
				h1++;
				if(h1 == 24)
					h1 = 0;
			}
			t++;
		}
		printf("%d\n", t);
	}
    return 0;
}
