#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, b, v[91];
	while(scanf("%d %d", &n, &b), n)
	{
		set<int> s;
		s.insert(0);
		for(int i = 0; i < b; i++)
		{
			scanf("%d", v + i);
			for(int j = 0; j < i; j++)
				s.insert(abs(v[i] - v[j]));
		}
		printf("%c\n", s.size() == n + 1 ? 'Y' : 'N');
	}
    return 0;
}
