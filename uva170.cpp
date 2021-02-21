#include <bits/stdc++.h>

using namespace std;

int main()
{
	int v[500];
	for(int i = '2'; i <= '9'; i++)
		v[i] = i - '0';
	v['T'] = 10;
	v['A'] = 1;
	v['Q'] = 12;
	v['K'] = 0;
	v['J'] = 11;
	
	char carta[3];
	
	while(scanf("%s", carta), carta[0] != '#')
	{
		queue<string> deck[13];
		deck[0].push(carta);
		for(int i = 1, pos = 12; i < 52; i++)
		{
			scanf("%s", carta);
			deck[pos%13].push(carta);
			pos--;
			if(pos < 0)
				pos = 12;
		}
		string ultima;	
		for(int i = 0, ind = 0; ; i++)
			if(deck[ind].empty())
			{
				printf("%02d,%s\n", i, ultima.c_str());
				break;
			}
			else
			{
				ultima = deck[ind].front();
				deck[ind].pop();
				ind = v[ultima[0]];
			}
	}
	
	
    return 0;
}
