#include <bits/stdc++.h>
#include <regex>
using namespace std;
char grid[9][10], current, outro;

bool right(int i, int j)
{
	int k;
	for (k = j + 1; grid[i][k] == outro; k++);
	return k != j + 1 && grid[i][k] == current;
}

bool left(int i, int j)
{
	int k;
	for (k = j - 1; grid[i][k] == outro; k--);
	return k != j - 1 && grid[i][k] == current;
}

bool top(int i, int j)
{
	int k;
	for (k = i - 1; grid[k][j] == outro; k--);
	return k != i - 1 && grid[k][j] == current;
}

bool bot(int i, int j)
{
	int k;
	for (k = i + 1; grid[k][j] == outro; k++);
	return k != i + 1 && grid[k][j] == current;
}

bool topright(int i, int j)
{
	int k;
	for (k = 1; grid[i + k][j + k] == outro; k++);
	return k != 1 && grid[i + k][j + k] == current;
}

bool botleft(int i, int j)
{
	int k;
	for (k = -1; grid[i + k][j + k] == outro; k--);
	return k != -1 && grid[i + k][j + k] == current;
}

bool botright(int i, int j)
{
	int k;
	for (k = 1; grid[i + k][j - k] == outro; k++);
	return k != 1 && grid[i + k][j - k] == current;
}

bool topleft(int i, int j)
{
	int k;
	for (k = 1; grid[i - k][j + k] == outro; k++);
	return k != 1 && grid[i - k][j + k] == current;
}

bool check(int i, int j)
{
	if (grid[i][j] != '-')
		return false;

	return right(i, j) || left(i, j) || top(i, j) || bot(i, j) ||
	topright(i, j) || botleft(i, j) || botright(i, j) || topleft(i, j);

}

void play(int i, int j)
{
	if (!check(i, j))
		swap(current, outro);

	grid[i][j] = current;
	if (left(i, j))
		for (int k = j - 1; grid[i][k] == outro; k--)
			grid[i][k] = current;
			
	if (right(i, j))
		for (int k = j + 1; grid[i][k] == outro; k++)
			grid[i][k] = current;

	if (top(i, j))
		for (int k = i - 1; grid[k][j] == outro; k--)
			grid[k][j] = current;

	if (bot(i, j))
		for (int k = i + 1; grid[k][j] == outro; k++)
			grid[k][j] = current;
	if (topright(i, j))
		for (int k = 1; grid[i + k][j + k] == outro; k++)
			grid[i + k][j + k] = current;

	if (botleft(i, j))
		for (int k = -1; grid[i + k][j + k] == outro; k--)
			grid[i + k][j + k] = current;

	if (botright(i, j))
		for (int k = 1; grid[i + k][j - k] == outro; k++)
			grid[i + k][j - k] = current;
	if (topleft(i, j))
		for (int k = 1; grid[i - k][j + k] == outro; k++)
			grid[i - k][j + k] = current;
	swap(current, outro);
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	char comando[5];
	scanf("%d\n", &n);
	while (n--)
	{
		for (int i = 1; i <= 8; i++)
			scanf("%s\n", &grid[i][1]);
		scanf("%c\n", &current);
		outro = (current == 'W' ? 'B' : 'W');
		while (scanf("%s", &comando), comando[0] != 'Q')
		{
			if (comando[0] == 'M')
			{
				play(comando[1] - '0', comando[2] - '0');				
				int b = 0, w = 0;
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
						if (grid[i][j] == 'W')
							w++;
						else if (grid[i][j] == 'B')
							b++;
				printf("Black - %2d White - %2d\n", b, w);
			}
			else
			{
				int achou = false;
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
						if (check(i, j))
						{
							printf("%s%d,%d)", achou ? " (" : "(", i, j);
							achou = true;
						}
				printf("%s", achou ? "\n" : "No legal move.\n");
			}
		}
		for (int i = 1; i <= 8; i++)
			printf("%s\n", &grid[i][1]);
		if (n)
			printf("\n");
	}

}