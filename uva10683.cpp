#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h, m, s, c;
	
	while(scanf("%2d%2d%2d%2d", &h, &m, &s, &c) != EOF)
	{
		int MS = h * 360000 + m * 6000 + s*100 + c;
		double D = MS/864.0;
		printf("%07lld\n", (long long)(1000*D));
	}
    return 0;
}
