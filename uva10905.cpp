#include <bits/stdc++.h>

using namespace std;

bool f(string s1, string s2)
{
	return s1 + s2 > s2 + s1;
}
int main()
{	
	int n, x;
	char c[5000];
	string a[50];
	while(scanf("%d\n", &n), n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%s", c);
			a[i] = c;
		}
		sort(a, a + n, f);
		for(int i = 0; i < n; i++)
			printf("%s", a[i].c_str());
		printf("\n");
	}
    return 0;
}
