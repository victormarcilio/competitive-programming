//http://codeforces.com/group/btcK4I5D5f/contest/341073/problem/J
#include<bits/stdc++.h>
 
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
 
void remove_sufix(string &s)
{
    string s2 = s;
    reverse(begin(s2), end(s2));
    int pops = 3;
    if(s2.find("hcive") == 0 || s2.find("anhci") == 0 || s2.find("hcivo") == 0)
        pops = 5;
    else if(s2.find("anvo") == 0 || s2.find("anve") == 0)
        pops = 4;

    while(pops--)
        s.pop_back();
}
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);        
    string nome, patro, family;
    int N;
 
    string n, p, f;
    cin >> nome >> patro >> family >> N;
    if(family.back() == 'a')
        family.pop_back();
    
    remove_sufix(patro);
    int irmaos = 0;
    int parentes = 0;
 
    while(N--)
    {
        cin >> n >> p >> f;
        if(f.back() == 'a')
            f.pop_back();
 
        if(family == f)
        {
            parentes++;
            remove_sufix(p);
            if(p == patro)
                irmaos++;
        }   
    }
    printf("%d %d\n", parentes, irmaos);
}