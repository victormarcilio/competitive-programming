#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int die[1000], i = 0, p, de, para, turn;
	while (scanf("%d", die + i), die[i])
		i++;
	int m[100], castigo[5], pos[5];
	while (scanf("%d", &p), p)
	{
		set<int> turns;
		memset(castigo, 0, sizeof castigo);
		memset(pos, 0, sizeof pos);
		memset(m, 0, sizeof m);
		while (scanf("%d %d", &de, &para), de)
			m[de] = para;
		while (scanf("%d", &de), de)
			turns.insert(de);
		turn = 0;
		for (int j = 0; ; j++, turn = (turn + 1) % p)
		{
			if (castigo[turn])
			{
				castigo[turn] = 0;
				turn = (turn + 1) % p;
			}
			if (pos[turn] + die[j] > 100)
				continue;
			pos[turn] += die[j];
			if (pos[turn] == 100)
			{
				printf("%d\n", turn + 1);
				break;
			}
			if (m[pos[turn]])
				pos[turn] = m[pos[turn]];
			else if (turns.find(pos[turn]) != turns.end())
				turn--;
			else if (turns.find(-pos[turn]) != turns.end())
				castigo[turn]++;
		}
	}


}