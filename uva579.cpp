#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h, m;
	while(scanf("%d:%d", &h, &m), h)
	{
		double am = m*6.0;
		double ah = 30*h + m*0.5;
		
		printf("%.3lf\n", min(abs(am - ah), 360 - abs(am - ah)));
	}
    return 0;
}
