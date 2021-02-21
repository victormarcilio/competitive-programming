#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, d;
	int meses[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char days[][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &m, &d);
		int k = 1, dias = -1;
		
		while(k < m)
			dias += meses[k++];
		dias += d;
		
		printf("%s\n", days[dias%7]);
	}
    return 0;
}
