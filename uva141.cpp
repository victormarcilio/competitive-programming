#include <bits/stdc++.h>
#include <regex>
using namespace std;

//O estado inicial não é contabilizado!!

vector<string> rot(vector<string> &v, int n)
{
	vector<string> res(v);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res[i][j] = v[j][n - 1 - i];
	return res;
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in2", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, x, y;
	char c;
	while (scanf("%d", &n), n)
	{
		vector<string> v(n, string(n, '0'));	
		bool acabou = false;
		set<vector<string>> s;
		
		for (int i = 0; i < 2 * n; i++)
		{
			scanf("%d %d %c", &x, &y, &c);
			if (!acabou)
			{
				v[x - 1][y - 1] = (v[x - 1][y - 1] == '0' ? '1' : '0');

				set<vector<string>> temp;
				for (int j = 0; j < 4; j++)
				{
					v = rot(v, n);
					if (s.find(v) != s.end())
					{
						acabou = true;
						printf("Player %d wins on move %d\n", (i + 1) % 2 + 1, i + 1);
						break;
					}
					temp.insert(v);
				
				}
				for (auto t : temp)
					s.insert(t);
			}
		}
		if (!acabou)
			printf("Draw\n");
	}
}