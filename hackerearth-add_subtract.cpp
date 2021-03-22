#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, k, x;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &k);
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			v[i] = x;
		}
		int best = 500000;

		for (int i = 1; i <= 100; i++)
		{
			vector<int> w(n);
			for (int j = 0; j < n; j++)
				if (i > v[j])
					w[j] = (i - v[j]) * 3;
				else if (i < v[j])
					w[j] = (v[j] - i) * 5;
			sort(begin(w), end(w));
			best = min(best, accumulate(begin(w), begin(w) + k, 0));
		}
		printf("%d\n", best);
	}
}
