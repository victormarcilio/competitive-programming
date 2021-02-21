#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	while(scanf("%d %d", &a, &b), a != -1)
		printf("%d\n", min(abs(a - b), 100 - (abs(a - b))));
}
