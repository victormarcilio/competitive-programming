#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, caso = 1, hi1, mi1, hf1, mf1, hf2, mf2, hi2, mi2;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d:%d %d:%d", &hi1, &mi1, &hf1, &mf1);
		scanf("%d:%d %d:%d", &hi2, &mi2, &hf2, &mf2);
		int ini1 = hi1*60 + mi1;
		int fim1 = hf1*60 + mf1;
		
		int ini2 = hi2*60 + mi2;
		int fim2 = hf2*60 + mf2;
		
		printf("Case %d: %s Meeting\n", caso++, ini1 > fim2 || fim1 < ini2 ?  "Hits" : "Mrs");
	}
    return 0;
}
