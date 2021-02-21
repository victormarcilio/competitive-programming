#include <bits/stdc++.h>

using namespace std;

bool check(string s1, string s2, pair<string, string> p)
{
	return s1 == p.first && s2 == p.second || s1 == p.second && s2 == p.first;
}

int main()
{
	int n;
	char musica[300];
	scanf("%d%*c", &n);
	string s1, S1, s2, S2, s3, S3;
	map<string, string> b;
	b["Ab"] = "G#";
	b["Bb"] = "A#";
	b["Cb"] = "B";
	b["Db"] = "C#";
	b["Eb"] = "D#";
	b["Fb"] = "E";
	b["Gb"] = "F#";
	
	string notas[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
	map<pair<string, string>, pair<string, string>> acordes;
	for(int i = 0; i < 12; i++)
	{
		acordes[make_pair(notas[i], "Major")] = make_pair(notas[(i + 4)%12], notas[(i + 7)%12]);
		acordes[make_pair(notas[i], "Minor")] = make_pair(notas[(i + 3)%12], notas[(i + 7)%12]);
	}
	prox: while(gets(musica))
	{
		char *p = strtok(musica, " ");
		S1 = s1 = p;
		p = strtok(NULL, " ");
		S2 = s2 = p;
		p = strtok(NULL, " ");
		S3 = s3 = p;
		
		S1[0] = toupper(S1[0]); if(b.find(S1) != b.end()) S1 = b[S1];
		S2[0] = toupper(S2[0]); if(b.find(S2) != b.end()) S2 = b[S2];
		S3[0] = toupper(S3[0]); if(b.find(S3) != b.end()) S3 = b[S3];
		
		for(auto it : acordes)
		{
			if(it.first.first == S1 && check(S2, S3, it.second))
			{
				printf("%s %s %s is a %s %s chord.\n", s1.c_str(), s2.c_str(), s3.c_str(), S1.c_str(), it.first.second.c_str());
				goto prox;
			}
			
			if(it.first.first == S2 && check(S1, S3, it.second))
			{
				printf("%s %s %s is a %s %s chord.\n", s1.c_str(), s2.c_str(), s3.c_str(), S2.c_str(), it.first.second.c_str());
				goto prox;
			}
			
			if(it.first.first == S3 && check(S2, S1, it.second))
			{
				printf("%s %s %s is a %s %s chord.\n", s1.c_str(), s2.c_str(), s3.c_str(), S3.c_str(), it.first.second.c_str());
				goto prox;
			}
		}
		
		printf("%s %s %s is unrecognized.\n", s1.c_str(), s2.c_str(), s3.c_str());
	}
    return 0;
}
