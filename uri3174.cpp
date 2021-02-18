#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h;
	cin >> n;
	string nome, tipo;
	map<string, int> cont;
	while(n--)
	{
		cin >> nome >> tipo >> h;
		cont[tipo] += h;
	}
	cout << cont["bonecos"]/8 + cont["arquitetos"]/4 + cont["musicos"]/6 + cont["desenhistas"]/12 << endl;
}