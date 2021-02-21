#include <bits/stdc++.h>
#include <regex>
using namespace std;

long long fat[21];

string f(string s, long long k)
{
	for (int i = 0; i < s.size(); i++)
	{
		sort(s.begin() + i, s.end());
		if (!k)
			break;
		swap(s[i], s[i + k/fat[s.size() - i - 1]]);
		k = k % fat[s.size() - i - 1];
	}
	return s;
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	long long k;
	scanf("%d\n", &n);

	char s1[30];
	fat[0] = 1;
	for (int i = 1; i <= 20; i++)
		fat[i] = i * fat[i - 1];
	while (n--)
	{
		scanf("%s", s1);
		scanf("%lld\n", &k);
		
		printf("%s\n", f(s1, k).c_str());
	}
}