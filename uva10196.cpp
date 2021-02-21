#include <bits/stdc++.h>

using namespace std;

int main()
{
	int pos1[] = {1, -1};
	int pos2[] = {2, -2};
	vector<int> v1(pos1, pos1 + 2), v2(pos2, pos2 + 2);
	char board[8][9], c;
	int flag, game = 1;
	while(1)
	{
		flag = 0;
		for(int i = 0; i < 8; i++)
			gets(board[i]);
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				flag += board[i][j] != '.';
		if(!flag)
			break;
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
			{
				c = board[i][j];
				if(c == 'p')
				{					
					if(j > 0 && i < 7 && board[i + 1][j - 1] == 'K' || j < 7 && i < 7 && board[i + 1][j + 1] == 'K')
					{
						printf("Game #%d: white king is in check.\n", game++);
						goto prox;
					}
				}
				else if(c == 'P')
				{
					if(j > 0 && i > 0 && board[i - 1][j - 1] == 'k' || j < 7 && i > 0 && board[i - 1][j + 1] == 'k')
					{
						printf("Game #%d: black king is in check.\n", game++);
						goto prox;
					}
				}
				else if(c == 'n')
				{
					for(auto u : v1)
						for(auto v : v2)
						{
							int x = i + u, y = j + v;
							if(x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x][y] == 'K')
							{
								printf("Game #%d: white king is in check.\n", game++);
								goto prox;
							}
							
							x = i + v, y = j + u;
							if(x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x][y] == 'K')
							{
								printf("Game #%d: white king is in check.\n", game++);
								goto prox;
							}
						}
				}
				else if(c == 'N')
				{					
					for(auto u : v1)
						for(auto v : v2)
						{
							int x = i + u, y = j + v;
							if(x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x][y] == 'k')
							{
								printf("Game #%d: black king is in check.\n", game++);
								goto prox;
							}
							
							x = i + v, y = j + u;
							if(x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[x][y] == 'k')
							{
								printf("Game #%d: black king is in check.\n", game++);
								goto prox;
							}
						}
				}
				else if(c == 'r')
				{					
					for(flag = i + 1; flag < 8 && board[flag][j] == '.'; flag++);
					if(flag < 8 && board[flag][j] == 'K')
					{
						printf("Game #%d: white king is in check.\n", game++);
						goto prox;
					}
					for(flag = i - 1; flag >= 0 && board[flag][j] == '.'; flag--);
					if(flag >= 0 && board[flag][j] == 'K')
					{
						printf("Game #%d: white king is in check.\n", game++);
						goto prox;
					}
					for(flag = j + 1; flag < 8 && board[i][flag] == '.'; flag++);
					if(flag < 8 && board[i][flag] == 'K')
					{
						printf("Game #%d: white king is in check.\n", game++);
						goto prox;
					}
					for(flag = j - 1; flag >= 0 && board[i][flag] == '.'; flag--);
					if(flag >= 0 && board[i][flag] == 'K')
					{
						printf("Game #%d: white king is in check.\n", game++);
						goto prox;
					}
				}
				else if(c == 'R')
				{					
					for(flag = i + 1; flag < 8 && board[flag][j] == '.'; flag++);
					if(flag < 8 && board[flag][j] == 'k')
					{
						printf("Game #%d: black king is in check.\n", game++);
						goto prox;
					}
					for(flag = i - 1; flag >= 0 && board[flag][j] == '.'; flag--);
					if(flag >= 0 && board[flag][j] == 'k')
					{
						printf("Game #%d: black king is in check.\n", game++);
						goto prox;
					}
					for(flag = j + 1; flag < 8 && board[i][flag] == '.'; flag++);
					if(flag < 8 && board[i][flag] == 'k')
					{
						printf("Game #%d: black king is in check.\n", game++);
						goto prox;
					}
					for(flag = j - 1; flag >= 0 && board[i][flag] == '.'; flag--);
					if(flag >= 0 && board[i][flag] == 'k')
					{
						printf("Game #%d: black king is in check.\n", game++);
						goto prox;
					}
				}
				else if(c == 'b' || c == 'q')
				{					
					for(flag = 1; flag + i < 8 && flag + j < 8 && board[flag + i][flag + j] == '.'; flag++);
						if(flag + i < 8 && flag + j < 8 && board[flag + i][flag + j] == 'K')
						{
							printf("Game #%d: white king is in check.\n", game++);
							goto prox;
						}
					for(flag = -1; flag + i >= 0 && flag + j >= 0 && board[flag + i][flag + j] == '.'; flag--);
						if(flag + i >= 0 && flag + j >= 0 && board[flag + i][flag + j] == 'K')
						{
							printf("Game #%d: white king is in check.\n", game++);
							goto prox;
						}
					for(flag = 1; flag + i < 8 && j - flag >= 0 && board[flag + i][j - flag] == '.'; flag++);
						if(flag + i < 8 && j - flag >= 0 && board[flag + i][j - flag] == 'K')
						{
							printf("Game #%d: white king is in check.\n", game++);
							goto prox;
						}
					for(flag = 1; i - flag >= 0 && flag + j < 8 && board[i - flag][flag + j] == '.'; flag++);
						if(i - flag >= 0 && flag + j < 8 && board[i - flag][flag + j] == 'K')
						{
							printf("Game #%d: white king is in check.\n", game++);
							goto prox;
						}
				}
				else if(c == 'B' || c == 'Q')
				{
					for(flag = 1; flag + i < 8 && flag + j < 8 && board[flag + i][flag + j] == '.'; flag++);
						if(flag + i < 8 && flag + j < 8 && board[flag + i][flag + j] == 'k')
						{
							printf("Game #%d: black king is in check.\n", game++);
							goto prox;
						}
					for(flag = -1; flag + i >= 0 && flag + j >= 0 && board[flag + i][flag + j] == '.'; flag--);
						if(flag + i >= 0 && flag + j >= 0 && board[flag + i][flag + j] == 'k')
						{
							printf("Game #%d: black king is in check.\n", game++);
							goto prox;
						}
					for(flag = 1; flag + i < 8 && j - flag >= 0 && board[flag + i][j - flag] == '.'; flag++);
						if(flag + i < 8 && j - flag >= 0 && board[flag + i][j - flag] == 'k')
						{
							printf("Game #%d: black king is in check.\n", game++);
							goto prox;
						}
					for(flag = 1; i - flag >= 0 && flag + j < 8 && board[i - flag][flag + j] == '.'; flag++);
						if(i - flag >= 0 && flag + j < 8 && board[i - flag][flag + j] == 'k')
						{
							printf("Game #%d: black king is in check.\n", game++);
							goto prox;
						}
				}
				// gambiarrinha pra não ter que repetir o codigo de torre e bispo pra rainha
				if(c == 'Q' || c == 'q')
					board[i][j--] = c + 1;
					
			}
		
		printf("Game #%d: no king is in check.\n", game++);
		prox: gets(board[0]);
	}
    return 0;
}
