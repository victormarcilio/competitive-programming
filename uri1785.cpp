#include <bits/stdc++.h>
using namespace std;
 
int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        bool ok = false;
        int cnt = -1;

        string s = to_string(x);
        while (s.size() < 4)
            s.push_back('0');
        for(int j = 1; j < s.size(); j++)
            if (s[j] != s[j - 1])
            {
                ok = true;
                cnt = 0;
                break;
			}
		if (ok)
            while (x != 6174)
            {
                string s = to_string(x);
                while (s.size() < 4)
                    s.push_back('0');
                sort(begin(s), end(s));
                int menor = stoi(s);
                reverse(begin(s), end(s));
                int maior = stoi(s);
                x = maior - menor;
                cnt++;
            }
        
        cout << "Caso #" << i << ": " << cnt << '\n';
    }
}
