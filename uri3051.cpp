#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    deque<int> d;

    int sum = 0;
    long long ans = 0;
    if (k)
        for (int i = 0; i < n; i++)
        {
            d.push_back(v[i]);
            sum += v[i];
            while (sum > k)
            {
                sum -= d.front();
                d.pop_front();
            }
            if (sum == k && d.size())
            {
                while (i + 1 < n && !v[i + 1])
                {
                    i++;
                    d.push_back(0);
                }
                int zero_left = 0;
                int zl_count = 0;
                for (int &i = zero_left; i < d.size() && !d[i]; i++)
                    zl_count++;
                int zero_right = d.size() - 1;
                int zr_count = 0;
                if (zero_left != d.size())
                    for (int &i = zero_right; i >= 0 && !d[i]; i--)
                        zr_count++;
                if (zl_count != d.size())
                    ans += (zl_count + 1LL) * (zr_count + 1);
                else
                    ans += zl_count + 1LL;
            }
        }
    else
    {
        for (int i = 0; i < n; i++)
            if (v[i])
            {
                ans += (1LL + sum) * sum / 2;
                sum = 0;
            }
            else
                sum++;
        ans += (1LL + sum) * sum / 2;
    }
    cout << ans << '\n';
}