#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <bitset>
using namespace std;

int solve()
{
    int N, M, x;
    cin >> N >> M;
    multiset<int> available, changed;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        available.insert(x);
    }
    for (int i = 0; i < N; i++)
    {
        multiset<int> current_available, current_changed;
        vector<int> remaining;
        for (int j = 0; j < M; j++)
        {
            cin >> x;
            auto it = changed.find(x);
            if (it != changed.end())
            {
                current_changed.insert(x);
                changed.erase(it);
            }
            else
            {
                it = available.find(x);
                if (it != available.end())
                {
                    current_available.insert(x);
                    available.erase(it);
                }
                else
                    remaining.push_back(x);
            }
        }
        ans -= available.size();
        for (auto x : remaining)
        {
            current_changed.insert(x);
            ans++;
        }
        available = move(current_available);
        changed = move(current_changed);
    }
    return ans;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;

    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << solve() << "\n";
}