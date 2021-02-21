#include <bits/stdc++.h>
using namespace std;

struct frac
{
	int num, den;
	
	frac operator*(frac f2)
	{
		return frac(num*f2.num, den * f2.den);
	}
	
	frac(int n, int d = 1)
	{
		num = n;
		den = d;
	}
	
	void print()
	{
		if(!num)
			printf("0\n");
		
		else if(num >= den)
		{
			printf("%d", num/den);
			num = num % den;
			if(num)
			{
				for(int i = 2; i <= num; i++)
					while(num % i == 0 && den % i == 0)
					{
						num = num/i;
						den = den/i;
					}
				printf("-%d/%d\n", num, den);
			}
			else
				printf("\n");
		}
		else if(num)
		{
			for(int i = 2; i <= num; i++)
				while(num % i == 0 && den % i == 0)
				{
					num = num/i;
					den = den/i;
				}
			printf("%d/%d\n", num, den);
		}
	}
};


int main()
{
	int n;
	
	scanf("%d\n", &n);
	char eq[1000];
	while(n--)
	{
		gets(eq);
		string s(eq);
		smatch m;
		regex e("([[:digit:]]+-[[:digit:]]+/[[:digit:]]+)"
		"|([[:digit:]]+/[[:digit:]]+)|([[:digit:]]+)");
		
		sregex_iterator pos(s.cbegin(), s.cend(), e);
		sregex_iterator end;
		regex e1("[[:digit:]]+"), 
				e2("([[:digit:]]+/[[:digit:]]+)");
				
		frac res(1);
		
		for(; pos != end; pos++)
			if(regex_match(pos->str(0), e1))
				res = res *frac(atoi(pos->str(0).c_str()));
			else if(regex_match(pos->str(0), e2))
			{
				strcpy(eq, pos->str(0).c_str());
				int num, den;
				sscanf(eq, "%d/%d", &num, &den);
				res = res * frac(num, den);
			}
			else
			{
				int n, num, den;
				strcpy(eq, pos->str(0).c_str());
				sscanf(eq, "%d-%d/%d", &n, &num, &den);
				res = res * frac(n*den + num, den);
			}
		res.print();
	}
}