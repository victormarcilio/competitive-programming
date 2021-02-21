#include <bits/stdc++.h>

using namespace std;

// Questão nao fala os tipos... a miseria do exemplo do box da a entender que podia ser inteiro mas não pode

struct teacher
{
	string departamento;
	char nome[100];
	char titulo[100];
	char last[400];
	char address[100];
	char phone1[100];
	char phone2[100];
	char box[20];
	
	teacher(string d)
	{
		departamento = d;
	}
	
	bool operator< (teacher t) const
	{
		string st = last;
		return st < t.last;
	}
	
	void print()
	{
		printf("----------------------------------------\n%s %s %s\n%s\nDepartment: %s\nHome Phone: %s\nWork Phone: %s\nCampus Box: %s\n", titulo,
		nome, last, address, departamento.c_str(), phone1, phone2, box);
	}
};

int main()
{	
	int n;
	scanf("%d\n", &n);
	char departamento[1000007], linha[1000007];
	vector<teacher> ts;
	int i = 0;
	while(n--)
	{
		gets(departamento);
		
		while(gets(linha), linha[0])
		{
			ts.push_back(teacher(departamento));
			sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", ts[i].titulo, ts[i].nome, ts[i].last, ts[i].address,
				ts[i].phone1, ts[i].phone2, ts[i].box);
			i++;
			linha[0] = 0;
		}
	}
	
	sort(ts.begin(), ts.end());
	for(auto it : ts)
		it.print();
	
    return 0;
}
