#include <bits/stdc++.h>

using namespace std;
int mapa[500];
int aux[5];

int straight(string *v)
{
	for(int i = 0; i < 5; i++)
		aux[i] = mapa[v[i][0]];
	
	sort(aux, aux + 5);
	
	for(int i = 1; i < 4; i++)
		if(aux[i] != aux[i - 1] + 1)
			return 0;
	
	// AQUI É CHECANDO A 2 3 4 5, MAS NÃO É NECESSÁRIO, ENUNCIADO NAO FALA NELE
	if(aux[4] == 14 && aux[3] == 5)
		return 5;
	else if(aux[4] != aux[3] + 1)
		return 0;
	return aux[4];
}

int straight_flush(string *v)
{
	for(int i = 1; i < 5; i++)
		if(v[i][1] != v[i - 1][1])
			return 0;
		
	return straight(v);
}

int four(string *v)
{
	for(int i = 0; i < 5; i++)
		aux[i] = mapa[v[i][0]];
	sort(aux, aux + 5);
	if(aux[0] == aux[3] || aux[1] == aux[4])
		return aux[2];
	return 0;
}

int full(string *v)
{
	for(int i = 0; i < 5; i++)
		aux[i] = mapa[v[i][0]];
	sort(aux, aux + 5);
	if(aux[0] == aux[2] || aux[2] == aux[4])
		return aux[2];
	return 0;
}

int flush(string *v)
{
	for(int i = 1; i < 5; i++)
		if(v[i][1] != v[i - 1][1])
			return 0;
	
	for(int i = 0; i < 5; i++)
		aux[i] = mapa[v[i][0]];
	sort(aux, aux + 5);	
	return aux[4];
}

int three(string *v)
{
	for(int i = 0; i < 5; i++)
		aux[i] = mapa[v[i][0]];
	sort(aux, aux + 5);	
	if(aux[0] == aux[2] || aux[2] == aux[4])
		return aux[2];
	
	return 0;
}

vector<int> two(string *v)
{
	vector<int> res;
	for(int i = 0; i < 5; i++)
		aux[i] = mapa[v[i][0]];
	sort(aux, aux + 5);	
	int rep = 0;
	for(int i = 1; i < 5; i++)
		if(aux[i] == aux[i - 1])
			rep++;
	if(rep != 2)
		res.push_back(0);
	else
	{
		for(int i = 4; i > 0; i--)
			if(aux[i] == aux[i - 1])
				res.push_back(aux[i]);
		
		for(int i = 4; i >= 0; i--)
			if(aux[i] != res[0] && aux[i] != res[1])
				res.push_back(aux[i]);
	}
	return res;
}

vector<int> PAIR(string *v)
{
	int rep = -1;
	vector<int> res;
	for(int i = 0; i < 5; i++)
		aux[i] = mapa[v[i][0]];
	sort(aux, aux + 5);	
	for(int i = 1; i < 5; i++)
		if(aux[i] == aux[i - 1])
			rep = aux[i];
	if(rep != -1)
	{
		res.push_back(rep);
		for(int i = 4; i >= 0; i--)
			if(aux[i] != rep)
				res.push_back(aux[i]);
				
	}
	else
		res.push_back(0);
	return res;
}

vector<int> high(string *v)
{
	vector<int> res;
	for(int i = 0; i < 5; i++)
		res.push_back(mapa[v[i][0]]);
	sort(res.begin(), res.end());
	swap(res[0], res[4]);
	swap(res[1], res[3]);
	return res;	
}
#define bw "Black wins."
#define ww "White wins."
int main()
{
	char s[100], *p;
	vector<int> A, X;
	
	// pro sort
	for(char c = '2'; c <= '9'; c++)
		mapa[c] = c - '0';
	mapa['T'] = 10; mapa['J'] = 11; mapa['Q'] = 12; mapa['K'] = 13; mapa['A'] = 14;
	
	int b, w;
	vector<int> B, W;
	string black[5];
	string white[5];
    while(gets(s))
	{
		p = strtok(s, " ");
		int i = 0;
		while(i < 5)
		{
			black[i++] = p;
			p = strtok(NULL, " ");
		}

		i = 0;
		while(i < 5)
		{
			white[i++] = p;
			p = strtok(NULL, " ");
		}
		
		b = straight_flush(black);
		w = straight_flush(white);
		if(b > w)
			puts(bw);
		else if(w > b)
			puts(ww);
		else
		{
			b = four(black);
			w = four(white);
			
			if(b > w)
				puts(bw);
			else if(w > b)
				puts(ww);
			else
			{
				b = full(black);
				w = full(white);
				
				if(b > w)
					puts(bw);
				else if(w > b)
					puts(ww);
				else
				{
					b = flush(black);
					w = flush(white);
					
					if(b > w)
						puts(bw);
					else if(w > b)
						puts(ww);
					else
					{
						b = straight(black);
						w = straight(white);
						
						if(b > w)
							puts(bw);
						else if(w > b)
							puts(ww);
						else
						{
							b = three(black);
							w = three(white);
							
							if(b > w)
								puts(bw);
							else if(w > b)
								puts(ww);
							else
							{
								B = two(black);
								W = two(white);
								
								if(B > W)
									puts(bw);
								else if(W > B)
									puts(ww);
								else
								{
									B = PAIR(black);
									W = PAIR(white);
									if(B > W)
										puts(bw);
									else if(W > B)
										puts(ww);
									else
									{
										B = high(black);
										W = high(white);										
										if(B > W)
											puts(bw);
										else if(W > B)
											puts(ww);
										else
											printf("Tie.\n");
									}
								}
							}
						}
					}
				}
			}
		}	
	}
}
