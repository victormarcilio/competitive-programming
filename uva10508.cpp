#include <bits/stdc++.h>
using namespace std;

string s;

int dif(const string &s1, const string &s2)
{
	int d = 0;
	for (int i = 0; i < s1.size(); i++)
		d += (s1[i] != s2[i]);
	return d;
}

bool f(const string &s1, const string &s2)
{
	return dif(s1, s) < dif(s2, s);
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out2", "w", stdout);
	int n, k;
	char primeira[5000], ultima[5000];
	while (~scanf("%d %d\n", &n, &k))
	{
		vector<string> v;
		scanf("%s\n", primeira);
		printf("%s\n", primeira);
		scanf("%s\n", ultima);
		v.push_back(ultima);
		s = primeira;
		for (int i = 2; i < n; i++)
		{
			scanf("%s\n", primeira);
			v.push_back(primeira);
		}
		sort(v.begin(), v.end(), f);
		for (auto i : v)
			cout << i << endl;
	}
	
}