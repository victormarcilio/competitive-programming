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
	int n;
	while (scanf("%d", &n), n)
	{
		while (n--)
		{
			int c = 0, v;
			char res;
			for (char i = 'A'; i < 'F'; i++)
			{
				scanf("%d", &v);
				if (v < 128)
				{
					res = i;
					c++;
				}
			}
			printf("%c\n", c == 1 ? res : '*');
		}
	}
	
}