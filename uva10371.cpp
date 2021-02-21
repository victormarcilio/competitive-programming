#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n;
	char horario[20], zona1[10], zona2[10];
	scanf("%d\n", &n);
	map<string, int> fuso;
	map<int, int> transf;
	transf[0] = 12;
	for(int i = 1; i < 24; i++)
		transf[i] = (i > 12 ? i - 12 : i);
	fuso["WET"] = fuso["GMT"] = fuso["UTC"] = 0;
	
	fuso["CET"] = fuso["WEST"] = fuso["IST"] = fuso["BST"] = 60;
	fuso["EET"] = fuso["CEST"] = 120;
	fuso["MSK"] = fuso["EEST"] = 180;
	fuso["MSD"] = 240;
	fuso["EDT"] = fuso["AST"] = -240;
	fuso["ADT"] = -180;
	fuso["NST"] = -210;
	fuso["NDT"] = -150;
	fuso["CDT"] = fuso["EST"] = -300;
	fuso["MDT"] = fuso["CST"] = -360;
	fuso["PDT"] = fuso["MST"] = -420;
	fuso["AKDT"] = fuso["PST"] = -480;
	fuso["HST"] = -600;
	fuso["AKST"] = -540;
	fuso["AEST"] = 600;
	fuso["AEDT"] = 660;
	fuso["ACST"] = 570;
	fuso["ACDT"] = 630;
	fuso["AWST"] = 480;
	
	while(n--)
	{
		//esquecer esse \n pode atrapalhar um bocado
		scanf("%[^A-Z] %s %s\n", horario, zona1, zona2);
		int h, m;
		if(horario[0] == 'n')
		{
			h = 12;
			m = 0;
		}
		else if(horario[0] == 'm')
		{
			h = 0; 
			m = 0;
		}
		// Se ligar na soma e subtração desse else!!
		else
		{
			sscanf(horario, "%d:%d", &h, &m);
			h += (horario[strlen(horario) - 5] == 'p' && h != 12)*12;
			h -= (horario[strlen(horario) - 5] == 'a' && h == 12)*12;
		}
		
		int mins = fuso[zona2] - fuso[zona1];
		int delta = mins > 0 ? 1 : -1;
		mins = max(mins, -mins);
		while(mins--)
		{
			m += delta;
			if(m == 60)
			{
				m = 0;
				h++;
				if(h == 24)
					h = 0;
			}
			if(m < 0)
			{
				m = 59;
				h--;
				if (h < 0)
					h = 23;
			}
		}
		if(h == 12 && m == 0)
			printf("noon\n");
		else if(!h && !m)
			printf("midnight\n");
		else
			printf("%d:%02d %c.m.\n", transf[h], m, h > 11 ? 'p' : 'a');
	}
    return 0;
}
