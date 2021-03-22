#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<char, char> m;
	m['A'] = m['B'] = m['C'] = m['D'] = m['E']= 'C';
	m['F'] = m['G'] = m['H'] = 'G';
	m['I'] = m['J'] = m['K'] = m['L'] = 'I';
	m['M'] = m['N'] = m['O'] = m['P'] = m['Q'] = 'O';
	m['R'] = m['S'] = m['T'] = m['U'] = m['V'] = 'S';
	m['W'] = m['X'] = m['Y'] = m['Z'] = 'Y';

	m['a'] = m['b'] = m['c'] = 'a';
	m['d'] = m ['e'] = m['f'] = 'e';
	m['g'] = m['h'] = m['i'] = 'g';
	m['j'] = m['k'] = m['l'] = 'k';
	m['m'] = m['n'] = m['o'] = 'm';
	m['p'] = m['q'] = m['r'] = m['s'] = m['t'] =
	m['u'] = m['v'] = m['w'] = m['x'] = m['y'] = m['z'] = 'q';


	int t, tam;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> tam >> s;
		for(char c : s)
			cout << m[c];
		cout << '\n';
	}
}
