#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, a, b, c;
    cin >> N >> M;
    vector<vector<ii>> AdjList(N + 1);
    while (M--)
    {
        cin >> a >> b >> c;
        AdjList[a].push_back(ii(b, c));
        AdjList[b].push_back(ii(a, c));
    }
    vi distances(N + 1, 1'000'000);
    distances[1] = 0;
    priority_queue< ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, 1));
    while(!pq.empty())
    {
        ii front = pq.top();
        pq.pop();
        int d = front.first;
        int u = front.second;
        if (d > distances[u])
            continue;
        for (int j = 0; j < AdjList[u].size(); j++)
        {
            ii v = AdjList[u][j];
            if (distances[u] + v.second < distances[v.first])
            {
                distances[v.first] = distances[u] + v.second;
                pq.push(ii(distances[v.first], v.first));
            }
        }
    }
    cout << distances[N] << '\n';
}
