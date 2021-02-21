#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);

	int k, n;
	
	while (scanf("%d %d", &n, &k), k)
	{
		vector<int> v(n + 1, 40);
		queue<int> q;
		for (int i = 1; i <= n; i++)
			q.push(i);
		int remaining = 1, coins = 1;
		while (!q.empty())
		{
			int front = q.front();
			q.pop();
			if (!remaining)
			{
				coins++;
				if (coins > k)
					coins = 1;
				remaining = coins;
			}
			if (remaining >= v[front])
			{
				remaining -= v[front];
				v[front] = 0;
				printf("%3d", front);
			}
			else
			{
				v[front] -= remaining;
				remaining = 0;
				q.push(front);
			}
		}
		printf("\n");
	}
}
