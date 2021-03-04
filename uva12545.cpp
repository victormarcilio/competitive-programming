#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string s1, s2;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> s1 >> s2;
        int marks = 0, zeros1 = 0, ones1 = 0, zeros2 = 0, ones2 = 0;
        for (int j = 0; j < s1.size(); j++)
        {
            if (s1[j] == '?')
                marks++;
            else if (s1[j] == '1')
                ones1++;
            else
                zeros1++;
            if (s2[j] == '1')
                ones2++;
            else
                zeros2++;
        }
        cout << "Case " << i << ": ";
        if (zeros1 + marks < zeros2)
            cout << "-1\n";
        else
        {
            int swaps = 0;
            int changes = 0;
            int to0 = zeros2 - zeros1;
            for (int i = 0; to0 > 0 && i < s1.size(); i++)
                if (s1[i] == '?' && s2[i] == '0')
                {
                    s1[i] = '0';
                    to0--;
                }
            for (int i = 0; to0 > 0; i++)
            {
                if (s1[i] == '?')
                {
                    to0--;
                    s1[i] = '0';
                }
            }
            for (int i = 0; i < s1.size(); i++)
                if (s1[i] == '?')
                    s1[i] = '1';

            int zeros2one = zeros1 - zeros2;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] == '0' && s2[i] == '1' && zeros2one > 0)
                {
                    changes++;
                    zeros2one--;
                }
                else if (s1[i] != s2[i])
                    swaps++;
            }

            cout << changes + marks + swaps / 2 << '\n';
        }
    }
}
