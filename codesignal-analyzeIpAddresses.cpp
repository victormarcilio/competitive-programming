//https://app.codesignal.com/company-challenges/verkada/LgTPsbkr3hikeSNsD
#include<bits/stdc++.h>

using namespace std;
using namespace std::filesystem;
set<string> m;
char s[10000];
void rec(string path)
{
    for (const auto & entry : directory_iterator(path))
        if(is_directory(entry.path()))
           rec(entry.path());
        else
        {
            ifstream ifs(entry.path());
            string S;
            while(ifs >> S)
            {
                strcpy(s, S.c_str());
                char *p = strtok(s, ",");
                while(p)
                {
                  	if(regex_match(p, regex("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$")))
                    	m.insert(p);
                    p = strtok(NULL, ",");
                }
            }
        }
}

int main() {
  
  string path = "/root/data/";
  rec(path);
  
  for(auto it : m)
    cout << it << endl;
  return 0;
}
