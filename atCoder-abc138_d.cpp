//https://vjudge.net/problem/AtCoder-abc138_d/origin
//https://atcoder.jp/contests/abc138/tasks/abc138_d?lang=en
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include<sstream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <bitset>
#include<numeric>
#include<thread>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P, X, A, B, N, Q;

    cin >> N >> Q;
    vector<vector<int>> children(N + 1);
    vector<long long> weight(N + 1);
  
    for (int i = 1; i < N; i++)
    {
        cin >> A >> B;
        children[A].push_back(B);
        children[B].push_back(A);
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> P >> X;
        weight[P] += X;
    }
    bitset<200010> visited;
    visited.reset();
    queue<pair<int, long long>> q;
    q.push({ 1 , weight[1]});
    visited.set(1);
    while (!q.empty())
    {
        auto [curr, acc] = q.front();
        q.pop();
        for (int i = 0; i < children[curr].size(); i++)
        {
            int destination = children[curr][i];
            if (!visited[destination])
            {
                visited[destination] = 1;
                weight[destination] += acc;
                q.push({ destination, weight[destination] });
            }
        }
    }
    for (int i = 1; i <= N; i++)
        cout << weight[i] << ' ';
    
}