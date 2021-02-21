#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n;
	vector<int> v;
	while(scanf("%d", &n) != EOF)
	{
		v.push_back(n);
		sort(v.begin(), v.end());
		if(v.size() & 1)
			printf("%d\n", v[v.size()/2]);
		else
			printf("%d\n", (v[v.size()/2] + v[v.size()/2 -1])/2);
	}
    return 0;
}
