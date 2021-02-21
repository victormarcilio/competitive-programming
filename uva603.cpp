
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int t, x, salto;
	scanf("%d\n", &t);
	char n[4];
	while (t--)
	{
		vector<int> v;
		map<int, int> m, m2;
		while (cin.getline(n, sizeof n), strcmp(n, "99"))
		{
			x = atoi(n);
			v.push_back(x);
			m[x] = x;
		}
		while (cin.getline(n, sizeof n), n[0])
		{
			x = atoi(n);
			salto = 0;
			for (int i = x; ; i--, salto++)
			{
				if (i == 0)
					i = 20;
				bool achou = false;
				for(auto &el : m)
					if (el.second == i)
					{
						m2[el.first] = x;
						achou = true;
						m.erase(el.first);
						break;
					}
				if (achou)
				{
					if(salto)
						for (auto &el : m)
						{
							el.second += salto;
							if (el.second > 20)
								el.second -= 20;
						}
					break;
				}
			}
		}
		for (auto i : v)
			if (m2.find(i) == m2.end())
				printf("Original position %d did not park\n", i);
			else
				printf("Original position %d parked in %d\n", i, m2[i]);
		if (t)
			printf("\n");
	}
}

