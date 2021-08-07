//https://codeforces.com/group/nituVTsHQX/contest/339649/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
struct pokemon
{
    string name;
    int level;
 
    bool operator<(const pokemon& other) const
    {
        return level < other.level;
    }
};
 
int main()
{
    int n, q;
    cin >> n >> q;
    map<string, int> pokelevel;
    string name;
    vector<pokemon> pokemons(n);
    int level;
    for(int i = 0; i < n; i++)
    {
        cin >> name >> level;
        pokelevel[name] = level;
        pokemons[i].name = name;
        pokemons[i].level = level;
    }
    sort(begin(pokemons), end(pokemons));
 
    while(q--)
    {
        pokemon p;
        cin >> p.name;
        p.level = pokelevel[p.name] - 1;
        cout << upper_bound(begin(pokemons), end(pokemons), p) - begin(pokemons) << endl;
    }
}