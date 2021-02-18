#include <bits/stdc++.h>
using namespace std;

struct duende
{
	string nome;
	int idade;
	
	bool operator<(const duende& d2)
	{
		if(idade != d2.idade)
			return idade > d2.idade;
		return nome < d2.nome;
	}
	
	friend ostream& operator<<(ostream& out, const duende& d)
	{
		out << d.nome << ' ' << d.idade << '\n';
		return out;
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;
	vector<duende> duendes(n);
	for(int i = 0; i < n; i++)
		cin >> duendes[i].nome >> duendes[i].idade;
	sort(begin(duendes), end(duendes));
	int salto = n/3;
	for(int i = 0; i < salto; i++)
		cout << "Time " << i + 1 << '\n' << duendes[i] << duendes[i + salto] << duendes[i + salto*2] << '\n';
}