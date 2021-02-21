#include <bits/stdc++.h>

using namespace std;

int main()
{
	int k, m, num, c, r;
	while(scanf("%d", &k), k)
	{
		scanf("%d", &m);
		bool pode = true;
		set<int> s;
		for(int i = 0; i < k; i++)
		{
			scanf("%d", &num);
			s.insert(num);
		}
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &c, &r);
			for(int i = 0; i < c; i++)
			{
				scanf("%d", &num);
				if(s.find(num) != s.end())
					r--;
			}
			pode = pode && r < 1;
		}
		printf("%s\n", pode ? "yes" : "no");
	}
	
}
