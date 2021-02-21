#include <bits/stdc++.h>
using namespace std;

bool eh;

void parseSlump(deque<char> &d)
{
	if (d.empty() || d.front() != 'D' && d.front() != 'E')
	{
		eh = false;
		return;
	}
	d.pop_front();
	if (d.front() != 'F')
	{
		eh = false;
		return;
	}
	d.pop_front();
	while (!d.empty() && d.front() == 'F')
		d.pop_front();

	if (d.empty())
	{
		eh = false;
		return;
	}
	if (d.front() == 'G')
		d.pop_front();
	else if (d.front() == 'D' || d.front() == 'E')
		parseSlump(d);
	else
		eh = false;
}


void parseSlimp(deque<char> &d)
{
	if (d.empty() || d.front() != 'A')
	{
		eh = false;
		return;
	}
	d.pop_front();
	if (d.empty())
	{
		eh = false;
		return;
	}
	if (d.front() == 'H')
		d.pop_front();
	else if (d.front() == 'B')
	{
		d.pop_front();
		parseSlimp(d);
		if (d.empty() || d.front() != 'C')
		{
			eh = false;
			return;
		}
		d.pop_front();
	}
	else if (d.front() == 'E' || d.front() == 'D')
	{
		parseSlump(d);
		if (d.empty() || d.front() != 'C')
		{
			eh = false;
			return;
		}
		d.pop_front();
	}
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	scanf("%d\n", &n);
	printf("SLURPYS OUTPUT\n");
	while (n--)
	{
		char linha[80];
		scanf("%s%*c", linha);
		deque<char> d;
		for (int i = 0; linha[i]; i++)
			d.push_back(linha[i]);
		eh = true;
		parseSlimp(d);
		parseSlump(d);
		printf("%s\n", eh && d.empty()? "YES" : "NO");
	}
	printf("END OF OUTPUT\n");
}