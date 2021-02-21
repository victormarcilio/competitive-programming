#include <bits/stdc++.h>

using namespace std;
struct p
{
	char nome[30];
	int y, d, m;
	
	bool operator< (p p2) const
	{
		if (y != p2.y)
			return y < p2.y;
		if(m != p2.m)
			return m < p2.m;
		return d < p2.d;
	}
};
int main()
{	
	int n;
	p v[100];
	scanf("%d\n", &n);
	
	for(int i = 0; i < n; i++)
		scanf("%s %d %d %d\n", &v[i].nome, &v[i].d, &v[i].m, &v[i].y);
	
	sort(v, v + n);
	printf("%s\n%s\n", v[n - 1].nome, v[0].nome);
	
    return 0;
}
