#include <bits/stdc++.h>
#pragma warning(disable : 4996)

using namespace std;

const vector<char> vals{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
const vector<char> naipes{ 'S', 'D', 'C', 'H' };
map<char, int> m;

bool check_sequence(const vector<string>& v, int inicio, int tam_sequencia)
{
	for (int i = 0; i < tam_sequencia; i++)
	{
		if (find_if(begin(v), end(v),
			[&inicio](const string& s) { return vals[inicio] == s[0]; }) == end(v))
			return false;
		inicio++;
		if (inicio > 12)
			inicio = 0;
	}
	return true;
}

bool check32(const vector<string>& v)
{
	map<int, int> temp;
	for (int i = 0; i < 5; i++)
		temp[m[v[i][0]]]++;
	bool achou3 = false;
	for (int i = 1, j = 1, k = 2; i < 14; i++)
	{
		if (++k == 14)
			k = 1;
		if (++j == 14)
			j = 1;
		if (temp[i] && temp[j] && temp[k])
		{
			achou3 = true;
			temp[i]--;
			temp[j]--;
			temp[k]--;
			break;
		}
	}
	if (achou3)
	{
		for (int i = 1, j = 2; i < 13; i++, j++)
			if (temp[i] && temp[j])
				return true;
		return temp[1] && temp[13];
	}
	else
		return false;
}

bool check22(const vector<string>& v)
{
	map<int, int> temp;
	for (int i = 0; i < 5; i++)
		temp[m[v[i][0]]]++;
	bool achou2 = false;
	for (int i = 1, j = 1; i < 14; i++)
	{
		if (++j == 14)
			j = 1;
		if (temp[i] && temp[j])
		{
			achou2 = true;
			temp[i]--;
			temp[j]--;
			break;
		}
	}
	if (achou2)
	{
		for (int i = 1, j = 2; i < 13; i++, j++)
			if (temp[i] && temp[j])
				return true;
		return temp[1] && temp[13];
	}
	else
		return false;
}


//a ideia eh fazer uma copia mesmo por causa do sort
int valor(vector<string> v)
{
	sort(begin(v), end(v), [](const string& s1, const string& s2)
		{
			return m[s1[0]] < m[s2[0]];
		});

	for (int i = 0; i < 13; i++)
		if (check_sequence(v, i, 5))
			return 100;

	for (int i = 0; i < 13; i++)
		if (check_sequence(v, i, 4))
			return 10;

	if (check32(v))
		return 5;

	for (int i = 0; i < 13; i++)
		if (check_sequence(v, i, 3))
			return 3;

	return check22(v);
}


int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	vector<string> hand(5);
	cin >> hand[0];
	for (int i = 2; i < 10; i++)
		m['0' + i] = i;
	m['A'] = 1;
	m['T'] = 10;
	m['J'] = 11;
	m['Q'] = 12;
	m['K'] = 13;
	char st[3] = "aa";
	while (hand[0][0] != '#')
	{
		set<string> s;
		for (int i = 0; i < naipes.size(); i++)
		{
			st[1] = naipes[i];
			for (int j = 0; j < vals.size(); j++)
			{
				st[0] = vals[j];
				s.insert(st);
			}
		}
		s.erase(hand[0]);
		for (int i = 1; i < 5; i++)
		{
			cin >> hand[i];
			s.erase(hand[i]);
		}
		//for (int i = 0; i < 5; i++)
		//	cout << hand[i] << ' ';
		//cout << '(' << valor(hand) << ") " << '=';
		double best = valor(hand) - 1.0;

		string trocado;
		for (int i = 0; i < 5; i++)
		{
			string temp = hand[i];
			double score = 0.0;
			for (auto& it : s)
			{
				hand[i] = it;
				score += valor(hand) * 1.0 / 47;
			}
			hand[i] = temp;
			if (score - 2 > best)
			{
				trocado = temp;
				best = score - 2;
			}
		}
		if (trocado.size())
			cout << "Exchange " << trocado << endl; 
		else
			cout << "Stay\n";

		cin >> hand[0];
	}
}