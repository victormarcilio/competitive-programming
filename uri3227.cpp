#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    int n;
    int count = 0, M = 0, W = 0;
    cin >> n >> line;
    int last_pos = line.size() - 1;
    reverse(begin(line), end(line));
    while (last_pos >= 0)
    {
        count++;
        if (line.back() == 'W')
        {
            if (abs(W + 1 - M) <= n)
                ++W;
            else if (last_pos && line[last_pos - 1] == 'M')
            {
                line[last_pos - 1] = 'W';
                ++M;
            }
            else
            {
                count--;
                break;
            }
        }
        else
        {
            if (abs(M + 1 - W) <= n)
                ++M;
            else if (last_pos && line[last_pos - 1] == 'W')
            {
                line[last_pos - 1] = 'M';
                ++W;
            }
            else
            {
                count--;
                break;
            }
        }
        line.pop_back();
        last_pos--;
    }
    cout << count << '\n';
}
