#include<bits/stdc++.h>
using namespace std;

void imprime(set<string> &s)
{
	auto it = s.begin();
	if(!s.size())
		printf("IMPOSSIBLE");
	else if(s.size() > 1)
	{
		printf("{%s", it->c_str());
		for(it++; it != s.end(); it++)
			printf(", %s", it->c_str());
		printf("}");
	}
	else
		printf("%s", it->c_str());
}

int main() 
{
	map<pair<int, int>, set<string>> filhos;
	map<string, int> m;
	map<int, string> r;
	m["A+"] = 1;
	m["A-"] = 2;
	m["B+"] = 3;
	m["B-"] = 4;
	m["AB+"] = 5;
	m["AB-"] = 6;
	m["O+"] = 7;
	m["O-"] = 8;
	
	r[1] = "A+";
	r[2] = "A-";
	r[3] = "B+";
	r[4] = "B-";
	r[5] ="AB+";
	r[6] ="AB-";
	r[7] = "O+";
	r[8] = "O-";
	
	// A+ & A+
	filhos[make_pair(1, 1)].insert("A+");
	filhos[make_pair(1, 1)].insert("O+");
	filhos[make_pair(1, 1)].insert("A-");
	filhos[make_pair(1, 1)].insert("O-");
	
	//A+ & A-
	filhos[make_pair(1, 2)] = filhos[make_pair(1, 1)];
	
	//A+ & B+
	filhos[make_pair(1, 3)].insert("A+");
	filhos[make_pair(1, 3)].insert("O+");
	filhos[make_pair(1, 3)].insert("B+");
	filhos[make_pair(1, 3)].insert("AB+");
	filhos[make_pair(1, 3)].insert("A-");
	filhos[make_pair(1, 3)].insert("B-");
	filhos[make_pair(1, 3)].insert("AB-");
	filhos[make_pair(1, 3)].insert("O-");
	
	//A+ & B-
	filhos[make_pair(1, 4)] = filhos[make_pair(1, 3)];
	
	//A+ & AB+
	filhos[make_pair(1, 5)].insert("A+");
	filhos[make_pair(1, 5)].insert("B+");
	filhos[make_pair(1, 5)].insert("AB+");
	filhos[make_pair(1, 5)].insert("A-");
	filhos[make_pair(1, 5)].insert("B-");
	filhos[make_pair(1, 5)].insert("AB-");
	
	//A+ & AB-
	filhos[make_pair(1, 6)] = filhos[make_pair(1, 5)];
	
	//A+ & O+
	filhos[make_pair(1, 7)].insert("A+");
	filhos[make_pair(1, 7)].insert("A-");
	filhos[make_pair(1, 7)].insert("O+");
	filhos[make_pair(1, 7)].insert("O-");
	
	//A+ & O-
	filhos[make_pair(1, 8)] = filhos[make_pair(1, 7)];
	
	// A- & A-
	filhos[make_pair(2, 2)].insert("A-");
	filhos[make_pair(2, 2)].insert("O-");
	
	//A- & B+
	filhos[make_pair(2, 3)] = filhos[make_pair(1, 4)];
	
	//A- & B-
	filhos[make_pair(2, 4)].insert("A-");
	filhos[make_pair(2, 4)].insert("B-");
	filhos[make_pair(2, 4)].insert("AB-");
	filhos[make_pair(2, 4)].insert("O-");
	
	//A- & AB+
	filhos[make_pair(2, 5)] = filhos[make_pair(1, 5)];
	
	//A- & AB-
	filhos[make_pair(2, 6)].insert("A-");
	filhos[make_pair(2, 6)].insert("B-");
	filhos[make_pair(2, 6)].insert("AB-");
	
	//A- & O+
	filhos[make_pair(2, 7)] = filhos[make_pair(1, 7)];
	
	//A- & O-
	filhos[make_pair(2, 8)].insert("A-");
	filhos[make_pair(2, 8)].insert("O-");
	
	//B+ & B+
	filhos[make_pair(3, 3)].insert("B+");
	filhos[make_pair(3, 3)].insert("B-");
	filhos[make_pair(3, 3)].insert("O+");
	filhos[make_pair(3, 3)].insert("O-");
	
	//B+ & B-
	filhos[make_pair(3, 4)] = filhos[make_pair(3, 3)];
	
	//B+ & AB+
	filhos[make_pair(3, 5)] = filhos[make_pair(1, 5)];
	
	//B+ & AB-
	filhos[make_pair(3, 6)] = filhos[make_pair(3, 5)];
	
	//B+ & O+
	filhos[make_pair(3, 7)].insert("B+");
	filhos[make_pair(3, 7)].insert("O+");
	filhos[make_pair(3, 7)].insert("B-");
	filhos[make_pair(3, 7)].insert("O-");
	
	//B+ & O-
	filhos[make_pair(3, 8)] = filhos[make_pair(3, 7)];
	
	//B- & B-
	filhos[make_pair(4, 4)].insert("B-");
	filhos[make_pair(4, 4)].insert("O-");
	
	//B- & AB+
	filhos[make_pair(4, 5)] = filhos[make_pair(3, 5)];
		
	//B- & AB-
	filhos[make_pair(4, 6)] = filhos[make_pair(2, 6)];
	
	//B- & O+
	filhos[make_pair(4, 7)] = filhos[make_pair(3, 8)];
	//B- & O-
	filhos[make_pair(4, 8)].insert("B-");
	filhos[make_pair(4, 8)].insert("O-");
	
	//AB+ & AB+
	filhos[make_pair(5, 5)].insert("A+");
	filhos[make_pair(5, 5)].insert("B+");
	filhos[make_pair(5, 5)].insert("AB+");
	filhos[make_pair(5, 5)].insert("A-");
	filhos[make_pair(5, 5)].insert("B-");
	filhos[make_pair(5, 5)].insert("AB-");
	
	//AB+ & AB-
	filhos[make_pair(5, 6)] = filhos[make_pair(5, 5)];
	
	//AB+ & O+
	filhos[make_pair(5, 7)].insert("A+");
	filhos[make_pair(5, 7)].insert("B+");
	filhos[make_pair(5, 7)].insert("A-");
	filhos[make_pair(5, 7)].insert("B-");
	
	//AB+ & O-
	filhos[make_pair(5, 8)] = filhos[make_pair(5, 7)];
	
	//AB- & AB-
	filhos[make_pair(6, 6)].insert("A-");
	filhos[make_pair(6, 6)].insert("B-");
	filhos[make_pair(6, 6)].insert("AB-");
	
	//AB- & O+
	filhos[make_pair(6, 7)] = filhos[make_pair(5, 8)];
	
	//AB- & O-
	filhos[make_pair(6, 8)].insert("A-");
	filhos[make_pair(6, 8)].insert("B-");
	
	//O+ & O+
	filhos[make_pair(7, 7)].insert("O+");
	filhos[make_pair(7, 7)].insert("O-");
	
	//O+ & O-
	filhos[make_pair(7, 8)] = filhos[make_pair(7, 7)];
	
	//O- & O-
	filhos[make_pair(8, 8)].insert("O-");
	
	char pai[5], mae[5], filho[5];
	int caso = 1;
	while(scanf("%s %s %s", pai, mae, filho), pai[0] != 'E')
	{
		printf("Case %d: ", caso++);
		if(filho[0] == '?')
		{
			printf("%s %s ", pai, mae);
			int i = m[pai];
			int j = m[mae];
			if(j < i)
				swap(i, j);
			set<string> s = filhos[make_pair(i, j)];
			imprime(s);
			printf("\n");
		}
		else if(pai[0] == '?')
		{
			set<string> s;
			for(auto it: filhos)
				if(it.second.find(filho) != it.second.end())
					if(it.first.first == m[mae])
						s.insert(r[it.first.second]);
					else if(it.first.second == m[mae])
						s.insert(r[it.first.first]);
			imprime(s);
			printf(" %s %s\n", mae, filho);
		}
		else
		{
			printf("%s ", pai);
			set<string> s;
			for(auto it: filhos)
				if(it.second.find(filho) != it.second.end())
					if(it.first.first == m[pai])
						s.insert(r[it.first.second]);
					else if(it.first.second == m[pai])
						s.insert(r[it.first.first]);
			imprime(s);
			printf(" %s\n", filho);
		}
	}
	
    return 0;
}
