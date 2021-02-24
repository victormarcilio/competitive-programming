#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int P, L, from, to;

    cin >> P >> L;
    vector<int> link_in(P + 1), weights(P + 1);
    vector<pair<int, int>> graph(L);
    for(int i = 0; i < L; i++)
    {
        cin >> from >> to;
        graph[i] = {from, to};
        ++link_in[to];
    }

    for(int i = 0; i < L; i++)
        weights[graph[i].second] += link_in[graph[i].first];
    for(int i = 1; i < P + 1; i++)
        cout << i << ": " << link_in[i] + weights[i] << '\n'; 
}
