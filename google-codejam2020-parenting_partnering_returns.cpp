#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int index;
    int starts;
    int ends;
    bool operator<(const activity& a2) const
    {
        return starts < a2.starts;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        cin >> n;
        string ans(n, '$');
        vector<activity> activities(n);
        for(int i = 0; i < n; i++)
        {
            cin >> activities[i].starts >> activities[i].ends;
            activities[i].index = i;
        }
        sort(begin(activities), end(activities));
        int J = 0;
        int C = 0;
        for(int i = 0; i < activities.size(); i++)
        {
            if(J <= activities[i].starts)
            {
                J = activities[i].ends;
                ans[activities[i].index] = 'J';
            }
            else if(C <= activities[i].starts)
            {
                C = activities[i].ends;
                ans[activities[i].index] = 'C';
            }
            else
            {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << c << ": " << ans << '\n';
    }
}
