//https://app.codesignal.com/company-challenges/autodeskasia/GoLJBtXYnWXgFHavf
#include<bits/stdc++.h>

using namespace std;
using namespace std::filesystem;
map<string, int> m;
void check(string path)
{
    for (const auto & entry : directory_iterator(path))
    {
        string filename = entry.path().filename();
        if(filename.substr(filename.size() - 4) == ".log")    
        {
            ifstream ifs(entry.path());
            string S;
            while(getline(ifs,S))
            {
                istringstream iss(S);
                string name, category;
                getline(iss, name, '|');
                getline(iss, category, '|');
                if(category == "ERROR")
                {
                    getline(iss, name, '|');
                    m[name]++;
                }
            }
        }
    }
}

bool f(const pair<string, int>& p1, const pair<string, int>& p2)
{
    if(p1.second != p2.second)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main() {
  string path = "/root/devops/logs/";
  check(path);
  vector<pair<string, int>> v{m.begin(), m.end()};
  sort(begin(v), end(v), f);
  for(auto& it : v)
    cout << it.first << ' ' << it.second << '\n';
  return 0;
}
