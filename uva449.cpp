#include <bits/stdc++.h>

using namespace std;

int main()
{	
	
	vector <string> A = {"A", "B", "C#", "D", "E", "F#", "G#"};
	vector <string> Bb = {"Bb", "C", "D", "Eb", "F", "G", "A"};
	vector <string> B = {"B", "C#", "D#", "E", "F#", "G#", "A#"};
	vector <string> Cb = {"Cb", "Db", "Eb", "Fb", "Gb", "Ab", "Bb"};
	vector <string> C = {"C", "D", "E", "F", "G", "A", "B",};
	vector <string> Cs = {"C#", "D#", "E#", "F#", "G#", "A#", "B#"};
	vector <string> Db = {"Db", "Eb", "F", "Gb", "Ab", "Bb", "C"};
	vector <string> D = {"D", "E", "F#", "G", "A", "B", "C#"};
	vector <string> Eb = {"Eb", "F", "G", "Ab", "Bb", "C", "D"};
	vector <string> E = {"E", "F#", "G#", "A", "B", "C#", "D#"};
	vector <string> F = {"F", "G", "A", "Bb", "C", "D", "E"};
	vector <string> Fs = {"F#", "G#", "A#", "B", "C#", "D#", "E#"};
	vector <string> Gb = {"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F"};
	vector <string> G = {"G", "A", "B", "C", "D", "E", "F#"};
	vector <string> Ab = {"Ab", "Bb", "C", "Db", "Eb", "F", "G"};
	
	map<string, vector<string>> m;
	
	
	m["A"] = A ;
	m["Bb"] = Bb;
	m["B"] = B ;
	m["Cb"] = Cb;
	m["C"] = C ;
	m["Cs"] = Cs;
	m["Db"] = Db;
	m["D"] = D ;
	m["Eb"] = Eb;
	m["E"] = E ;
	m["F"] = F ;
	m["Fs"] = Fs;
	m["Gb"] = Gb;
	m["G"] = G ;
	m["Ab"] = Ab;
	
	map<string, int> ind;
	ind["SECOND"] = 1;
	ind["THIRD"] = 2;
	ind["FOURTH"] = 3;
	ind["FIFTH"] = 4;
	ind["SIXTH"] = 5;
	ind["SEVENTH"] = 6;
	ind["OCTAVE"] = 0;
	char key[3];
	int up;
	char linha[100000], comando[100];
	while(gets(key))
	{
		printf("Key of %s\n", key);
		gets(linha);
		
		char *p = strtok(linha, ";");
		vector<string> comandos;
		while(p)
		{
			comandos.push_back(p);
			p = strtok(NULL, ";");
		}
		
		for(auto k : comandos)
		{
			strcpy(comando, k.c_str());
			p = strtok(comando, " ");
			printf("%s: ", p);
			for(int i = 0; i < m[key].size(); i++)
				if(p == m[key][i])
				{
					p = strtok(NULL, " ");
					printf("%s ", p);
					up = (*p == 'U' ? 1 : -1);
					p = strtok(NULL, " ");
					printf("%s > %s\n", p, m[key][(7 + i + up*ind[p])%7].c_str());
					goto prox;
				}
			printf("invalid note for this key\n");		
			prox: ;
		}
		printf("\n");
	}
    return 0;
}
