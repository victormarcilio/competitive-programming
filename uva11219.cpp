#include <bits/stdc++.h>

using namespace std;

struct data
{
	int d, m, y;
	
	data(int D, int M, int Y)
	{
		d = D; m = M; y = Y;
	}
	
	bool operator<(data d2) const
	{
		if(d2.y != y)
			return y < d2.y;
		if(d2.m != m)
			return m < d2.m;
		return d < d2.d;
	}
	
	int operator-(data d2) const
	{
		int res = y - d2.y;
		if(m < d2.m || m == d2.m && d < d2.d)
			res--;
		return res;
	}

};

int main()
{	
	int n, m1, m2, d1, d2, y1, y2, caso = 1;
	scanf("%d", &n);
	while(n--)
	{
		printf("Case #%d: ", caso++);
		scanf("%d/%d/%d", &d1, &m1, &y1);
		scanf("%d/%d/%d", &d2, &m2, &y2);
		data D1(d1, m1, y1);
		data D2(d2, m2, y2);
		if(D1 < D2)
			printf("Invalid birth date\n");
		else if( (m1 = D1 - D2) > 130)
			printf("Check birth date\n");
		else 
			printf("%d\n", m1);
	}
    return 0;
}
