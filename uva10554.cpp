#include <bits/stdc++.h>

using namespace std;

int main()
{
	char linha[100];
	while(gets(linha), linha[0] != '-')
	{
		
		int num = 0, percent = 0, vcal;
		double calorias = 0, fat = 0;
		int elemento = 0;
		char c;
		
		for(int i = 0; linha[i]; i++)
		{
			if(isdigit(linha[i]))
				num = num * 10 + linha[i] - '0';
			else if((linha[i]) != ' ')
			{
				elemento++;
				if(elemento == 1)
				{
					c = linha[i];
					vcal = num;
				}
				if(linha[i] == '%')
					percent += num;
				else if(linha[i] == 'C')
					calorias += num;
				else if(linha[i] == 'g')
				{
					if(elemento == 1)
						calorias += 9*num;
					else if(elemento == 5)
						calorias += 7*num;
					else
						calorias += 4*num;
				}
				num = 0;
			}
		}
		double cal_alimento = (calorias*100.)/(100 - percent);
		double calorias_totais = cal_alimento;
		
		if(c == 'g')
			vcal *= 9;
		
		if(c == '%')
			fat += vcal/100.*cal_alimento;
		else
			fat += vcal;

		while(gets(linha), linha[0] != '-')
		{
			calorias = percent = elemento = num = 0;
			for(int i = 0; linha[i]; i++)
			{
				if(isdigit(linha[i]))
					num = num * 10 + linha[i] - '0';
				else if((linha[i]) != ' ')
				{
					elemento++;
					if(elemento == 1)
					{
						c = linha[i];
						vcal = num;
					}
					if(linha[i] == '%')
						percent += num;
					else if(linha[i] == 'C')
						calorias += num;
					else if(linha[i] == 'g')
					{
						if(elemento == 1)
							calorias += 9*num;
						else if(elemento == 5)
							calorias += 7*num;
						else
							calorias += 4*num;
					}
					num = 0;
				}
			}
			cal_alimento = (calorias*100.)/(100 - percent);
			calorias_totais += cal_alimento;
			
			if(c == 'g')
				vcal *= 9;
			
			if(c == '%')
				fat += vcal/100.*cal_alimento;
			else
				fat += vcal;
		}
		// qualquer um dos printfs vai funcionar!
		//printf("%d%%\n", (int)floor(100.*fat/calorias_totais + 0.5));
		printf("%d%%\n", (int)round(100.*fat/calorias_totais));
	}
}
