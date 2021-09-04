//http://codeforces.com/group/btcK4I5D5f/contest/341073/problem/F
#include<bits/stdc++.h>
 
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
 
string get(vector<string>&v, string& nota, int jump)
{
    int start = 0;
    while(v[start] != nota)
        start++;
    return v[(start + jump) % 12];
}
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    int N, M;
    cin >> N >> M;
    vector<string> notas(N);
    M = (M + 120) % 12;
    vector<string> escala = {"Ab", "A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G"};
 
    for(int i = 0; i < N; i++)
        cin >> notas[i];
    cout << get(escala, notas[0], M);
    for(int i = 1; i < N; i++)
        cout << ' ' << get(escala, notas[i], M);
    cout << '\n';
 
}