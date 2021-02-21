#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int m, n, p, wall, x, y, custo, total = 0, points, dir, life;
	int mtx[53][53];
	memset(mtx, 0, sizeof mtx);
	map<pair<int, int>, pair<int, int>> Map;
	scanf("%d %d %d %d", &m, &n, &wall, &p);
	for (int i = 0; i < p; i++)
	{
		scanf("%d %d %d %d", &x, &y, &points, &custo);
		mtx[x][y] = 1;
		Map[{x, y}] = { points, custo };
	}
	int v[4] = { 3, 0, 1, 2 };
	while (~scanf("%d %d %d %d", &x, &y, &dir, &life))
	{
		points = 0;
		while (life > 1)
		{
			if (dir == 0)
			{
				if (x == m - 1)
				{
					dir = v[dir];
					life = life - wall;
				}
				else if (mtx[x + 1][y])
				{
					dir = v[dir];
					life -= Map[{x + 1, y}].second;
					points += Map[{x + 1, y}].first;
				}
				else
					x++;
			}
			else if (dir == 2)
			{
				if (x == 2)
				{
					dir = v[dir];
					life = life - wall;
				}
				else if (mtx[x - 1][y])
				{
					dir = v[dir];
					life -= Map[{x - 1, y}].second;
					points += Map[{x - 1, y}].first;
				}
				else
					x--;
			}
			else if (dir == 1)
			{
				if (y == n - 1)
				{
					dir = v[dir];
					life = life - wall;
				}
				else if (mtx[x][y + 1])
				{

					dir = v[dir];
					life -= Map[{x, y + 1}].second;
					points += Map[{x, y + 1}].first;

				}
				else
					y++;
			}
			else
			{
				if (y == 2)
				{
					dir = v[dir];
					life = life - wall;
				}
				else if (mtx[x][y - 1])
				{
					dir = v[dir];
					life -= Map[{x, y - 1}].second;
					points += Map[{x, y - 1}].first;
				}
				else
					y--;
			}
			life--;
		}
		printf("%d\n", points);
		total += points;
	}
	printf("%d\n", total);

}