#include <bits/stdc++.h>

using namespace std;

int main()
{	
	map<pair<int, int>, pair<int, int> > m;

	int h1 = 12, m1 = 0, h2 = 12, m2 = 0, n;
	while(m.find({h1, m1}) == m.end())
	{
		m[{h1, m1}] = {h2, m2};
		m[{h2, m2}] = {h1, m1};
		
		m1++;
		if(m1 == 60)
		{
			m1 = 0;
			h1++;
			if(h1 == 13)
				h1 = 1;
		}
		
		m2--;
		if(m2 == -1)
		{
			m2 = 59;
			h2--;
		}
		
	}
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d:%d", &h1, &m1);
		printf("%02d:%02d\n", m[{h1, m1}].first, m[{h1, m1}].second);
	}
    return 0;
}
