#include <bits/stdc++.h>

using namespace std;


int main()
{
	char letra, numero[15];
	int hi, sum, hf, mi, mf;
	int m[][3] = {{10, 6, 2}, {25, 15, 5}, {53, 33, 13}, {87, 47, 17}, {144, 80, 30}};
	while(scanf("%c", &letra), letra != '#')
	{
		scanf("%s %d %d %d %d\n", numero, &hi, &mi, &hf, &mf);
		if(hi == hf && mi == mf)
		{
			sum = m[letra - 'A'][0]*600 + m[letra - 'A'][1]*240 + m[letra - 'A'][2]*600;
			printf("%10s%6d%6d%6d%3c%8.2lf\n", numero, 600, 240, 600, letra, sum/100.0);
		}
		else
		{
			int manha = 0, tarde = 0, noite = 0;
			while(hi != hf || mi != mf)
			{
				if(hi >= 8 && hi < 18)
					manha++;
				else if(hi >= 18 && hi < 22)
					tarde++;
				else
					noite++;
				
				mi++;
				if(mi == 60)
				{
					mi = 0;
					hi++;
					if(hi == 24)
						hi = 0;
				}
			}
			sum = m[letra - 'A'][0]*manha + m[letra - 'A'][1]*tarde + m[letra - 'A'][2]*noite;
			
			printf("%10s%6d%6d%6d%3c%8.2lf\n", numero, manha, tarde, noite, letra, sum/100.0);
		}
	}
    return 0;
}
