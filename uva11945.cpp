#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, c = 1;
	char res[100];
	scanf("%d", &n);
	while(n--)
	{
		double sum = 0, d ;
		for(int i = 0; i < 12; i++)
		{
			scanf("%lf", &d);
			sum += d;
		}
		sprintf(res, "%.2lf", sum/12);
		char *p = res + strlen(res) - 2;
	
		int inteiros = 0;
		
		string aux = "";
		int cont = 0;
	
		for(char *p2 = p - 2; p2 >= res; p2--) 
		{
			aux = *p2 + aux;
			cont++;
			if(cont % 3 == 0 && p2 >= res + 1)
				aux = "," + aux;
		}
		aux += ".";
		printf("%d $%s%s\n", c++, aux.c_str(), p);
	}
}
