
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		a = a % b;
		swap(a, b);
	}
	return a;
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, x, caso = 1;
	while (scanf("%d", &n), n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			sum += x;
		}
		printf("Case %d:\n", caso++);
		bool neg = sum < 0;
		if (sum < 0)
			sum = -sum;
		if (sum % n == 0)
		{
			if (neg)
				printf("- ");
			printf("%d\n", sum / n);
		}
		else if (sum < n)
		{
			int g = gcd(sum, n);
			sum = sum / g;
			n = n / g;
			int dnum = int(1 + log10(sum));
			int dden = int(1 + log10(n));

			if (neg)
				printf("  ");
			for (int i = 0; i < dden - dnum; i++)
				printf(" ");
			printf("%d\n", sum);
			if (neg)
				printf("- ");
			for (int i = 0; i < dden; i++)
				printf("-");
			printf("\n%s%d\n", neg ? "  " : "", n);
		}
		else
		{
			int integer = sum / n;
			sum = sum % n;
			int g = gcd(sum, n);
			sum = sum / g;
			n = n / g;
			int dint = int(1 + log10(integer));
			int dnum = int(1 + log10(sum));
			int dden = int(1 + log10(n));

			if (neg)
				printf("  ");
			for (int i = 0; i < dden - dnum + dint; i++)
				printf(" ");
			printf("%d\n", sum);
			if (neg)
				printf("- ");
			printf("%d", integer);
			for (int i = 0; i < dden; i++)
				printf("-");
			printf("\n");
			if (neg)
				printf("  ");
			for (int i = 0; i < dint; i++)
				printf(" ");
			printf("%d\n", n);
		}
	}
}

