#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	char l[550], s[] = "TFPSUBM";
	int v[200];
	v['M'] = 1000000;
	v['T'] = 100000;
	v['F'] = 10000;
	v['P'] = 1000;
	v['S'] = 100;
	v['U'] = 10;
	v['B'] = 1; 
	prox: while(n--)
	{
		map<char, int> m;
		gets(l);
		int res = 0;
		for(int i = 0; l[i]; i++)
		{
			m[l[i]]++;
			res += v[l[i]];
		}
		for(int i = 0; s[i]; i++)
			if(m[s[i]] > 9)
			{
				printf("error\n");
				goto prox;
			}
		bool asc = true;
		for(int i = 1; l[i]; i++)
			if(l[i] != l[i - 1])
			{
				if(v[l[i]] < v[l[i - 1]])
					asc = false;
				break;
			}
		for(int i = 1; l[i]; i++)
			if(v[l[i]] < v[l[i - 1]] && asc || !asc && v[l[i]] > v[l[i - 1]])
			{
				printf("error\n");
				goto prox;
			}
		printf("%d\n", res);
	}
}
