#include <bits/stdc++.h>

using namespace std;

int main()
{
	set<int> graus;
	graus.insert(0);
	int h = 6, m = 72, n;
	while(h != 360 || m != 360)
	{
		if(m == 360)
			m = 0;
		graus.insert(min(abs(h - m), 360 - abs(h - m)));
		m += 72;
		h+= 6;
	}

	while(scanf("%d", &n) != EOF)
		printf("%c\n", graus.find(n) == graus.end()? 'N' : 'Y');
    return 0;
}
