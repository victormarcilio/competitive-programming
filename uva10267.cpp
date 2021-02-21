
#include <bits/stdc++.h>
using namespace std;


int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	char linha[400], c;
	int cont = 0;
	char table[255][255];
	int n, m, x, y, y2, x2;
	while (cin.getline(linha, sizeof linha), linha[0] != 'X')
	{
		if (linha[0] == 'I' || linha[0] == 'C')
		{
			if (linha[0] == 'I')
				sscanf(&linha[2], "%d %d", &m, &n);
			memset(table, 'O', sizeof table);
			for (int i = 0; i < n; i++)
				table[i][m] = 0;
		}
		else if (linha[0] == 'L')
		{
			sscanf(&linha[2], "%d %d %c", &x, &y, &c);
			x--; y--;
			table[y][x] = c;
		}
		else if (linha[0] == 'V')
		{
			sscanf(&linha[2], "%d %d %d %c", &x, &y, &y2, &c);
			x--; y--; y2--;
			if (y > y2)
				swap(y, y2);
			for (int i = y; i <= y2; i++)
				table[i][x] = c;
		}
		else if (linha[0] == 'H')
		{
			sscanf(&linha[2], "%d %d %d %c", &x, &x2, &y, &c);
			x--; x2--; y--;
			if (x > x2)
				swap(x, x2);
			for (int i = x; i <= x2; i++)
				table[y][i] = c;
		}
		else if (linha[0] == 'K')
		{
			sscanf(&linha[2], "%d %d %d %d %c", &x, &y, &x2, &y2, &c);
			x--; y--; x2--; y2--;
			if (x > x2)
				swap(x, x2);
			if (y > y2)
				swap(y, y2);
			for (int i = y; i <= y2; i++)
				for (int j = x; j <= x2; j++)
					table[i][j] = c;
		}
		else if (linha[0] == 'F')
		{
			sscanf(&linha[2], "%d %d %c", &x, &y, &c);
			x--; y--;
			if (table[y][x] != c)
			{
				char old = table[y][x];
				queue<pair<int, int>> q;
				q.push({ y, x });
				table[y][x] = c;
				while (!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					if (x > 0 && table[x - 1][y] == old)
					{
						q.push({ x - 1, y });
						table[x - 1][y] = c;
					}
					if (x < n - 1 && table[x + 1][y] == old)
					{
						q.push({ x + 1, y });
						table[x + 1][y] = c;
					}
					if (y > 0 && table[x][y - 1] == old)
					{
						q.push({ x, y - 1 });
						table[x][y - 1] = c;
					}
					if (y < m - 1 && table[x][y + 1] == old)
					{
						q.push({ x, y + 1 });
						table[x][y + 1] = c;
					}
				}
			}
		}
		else if (linha[0] == 'S')
		{
			cont++;
			printf("%s\n", &linha[2]);
			for (int i = 0; i < n; i++)
				printf("%s\n", table[i]);
		}
	}
}

