#include <bits/stdc++.h>
using namespace std;

struct yogurt
{
    int valor;
    int volume;

    bool operator<(const yogurt &y2) const
    {
        return (double)valor / volume > (double)y2.valor / y2.volume;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        vector<yogurt> yogurts(n);
        for (int i = 0; i < n; i++)
            cin >> yogurts[i].valor >> yogurts[i].volume;
        sort(begin(yogurts), end(yogurts));
        double total = 0;
        for (int i = 0; i < n; i++)
            if (yogurts[i].volume > x)
            {
                total += (double)x / yogurts[i].volume * yogurts[i].valor;
                break;
            }
            else
            {
                x -= yogurts[i].volume;
                total += yogurts[i].valor;
            }
        cout << setprecision(2) << fixed << total << '\n';
    }
}