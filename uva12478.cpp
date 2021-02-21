#include <bits/stdc++.h>

using namespace std;

int main()
{
	char horizontal[][10] = {"OBIDAIBKR", "RKAULHISP", "SADIYANNO", "HEISAWHIA", "IRAKIBULS", "MFBINTRNO", "UTOYZIFAH", "LEBSYNUNE", "EMOTIONAL"};
	char vertical[][10]   = {"ORSHIMULE", "BKAERFTEM", "IADIABOBO", "DUISKIYST", "ALYAINZYI", "IHAWBTINO", "BINHURFUN", "KSNILNANA", "RPOASOHEL"};
	
	string s[] = {"RAKIBUL", "ANINDYA",	"MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"};
	for(int i = 0; i < 8; i++)
	{
		int cont = 0;
		string vez = s[i];
		int tam = vez.size();
		
		sort(vez.begin(), vez.end());
		
		for(int j = 0; j < 9; j++)
		{
			string temp = string(horizontal[j]);
			for(int k = 0; k < 9 - tam + 1; k++)
			{
				string temp2 = temp.substr(k, tam);
				sort(temp2.begin(), temp2.end());
				
				if(vez == temp2)
					cont++;
			}
			
			temp = string(vertical[j]);
			for(int k = 0; k < 9 - tam; k++)
			{
				string temp2 = temp.substr(k, tam);
				sort(temp2.begin(), temp2.end());
				if(vez == temp2)
					cont++;
			}
		
		}
		if(cont == 2)
		{
			printf("%s\n", s[i].c_str());
			return 0;
		}
	}
	
	
}
