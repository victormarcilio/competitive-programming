#include <bits/stdc++.h>

using namespace std;
int main()
{
	string temp;
	vector<string> v;
	char st[100], c;
	int k = 0;
	
	while(scanf("%c", &c), c != '0')
	{
		if(isalpha(c))
			st[k++] = c;
		else if(isdigit(c))
		{
			int num = c - '0';
			while(scanf("%c", &c), isdigit(c))
				num = num * 10 + c - '0';
			printf("%s%c", (temp = v[v.size() - num]).c_str(), c);
			v.erase(v.end() - num);
			v.push_back(temp);
		}
		else
		{
			if(k)
			{
				st[k] = 0;
				v.push_back(st);
				
				printf("%s", st);
				k = 0;
			}
			printf("%c", c);
		}
	}
}
