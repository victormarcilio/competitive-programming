#include <bits/stdc++.h>

using namespace std;
int v[1000000];
int main()
{	
	int n;
	
	while(~scanf("%d", &n))
	{
		map<int, int> m;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &v[i]);
			m[v[i]]++;
		}
		sort(v, v + n);
		
		if(n & 1 || v[n/2 - 1] == v[n/2])
			printf("%d %d 1\n", v[n/2], m[v[n/2]]);
		else
			printf("%d %d %d\n", v[n/2 - 1], m[v[n/2]] + m[v[n/2 - 1]], v[n/2] - v[n/2 - 1] + 1);
	}
    return 0;
}
