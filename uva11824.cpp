#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int t, x;
	
	scanf("%d", &t);
	while(t--)
	{
		vector<int> v;
		while(scanf("%d", &x), x)
			v.push_back(x);
		sort(v.begin(), v.end());
		long long sum = v[v.size() - 1] << 1;
		for(int i = v.size() - 2, k = 2; ~i; i--, k++)
			sum += ((long long)pow(v[i], k)) << 1;
		
		if(sum > 5000000)
			printf("Too expensive\n");
		else
			printf("%lld\n", sum);
	}
	
    return 0;
}
