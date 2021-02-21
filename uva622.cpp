#include <bits/stdc++.h>
#include <regex>
using namespace std;

bool eh;

int parseN(deque<char> &d)
{
	if (d.empty() || !isdigit(d.front()))
	{
		eh = false;
		return 0;
	}
	int n = 0;
	while (!d.empty() && isdigit(d.front()))
	{
		n = n * 10 + d.front() - '0';
		d.pop_front();
	}
	return n;
}

int ParseExpression(deque<char> &d);
int ParseFactor(deque<char> &d)
{
	if (!d.empty() && d.front() == '(')
	{
		d.pop_front();
		int n = ParseExpression(d);
		if (d.empty() || d.front() != ')')
		{
			eh = false;
			return 0;
		}
		d.pop_front();
		return n;
	}
	else if (!d.empty() && isdigit(d.front()))
		return parseN(d);
	else
	{
		eh = false;
		return 0;
	}
}

int ParseComponent(deque<char> &d)
{
	int n1 = ParseFactor(d);
	if (!d.empty() && d.front() == '*')
	{
		d.pop_front();
		return n1 * ParseComponent(d);
	}
	return n1;
}

int ParseExpression(deque<char> &d)
{
	int n1 = ParseComponent(d);
	if (!d.empty() && d.front() == '+')
	{
		d.pop_front();
		int n2 = ParseExpression(d);
		return n1 + n2;
	}
	return n1;
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	scanf("%d\n", &n);
	while (n--)
	{
		char linha[1000];
		scanf("%s\n", linha);
		deque<char> d;
		for (int i = 0; linha[i]; i++)
			d.push_back(linha[i]);
		eh = true;
		
		int res = ParseExpression(d);
		if (eh && d.empty())
			printf("%d\n", res);
		else
			printf("ERROR\n");
	}
}
