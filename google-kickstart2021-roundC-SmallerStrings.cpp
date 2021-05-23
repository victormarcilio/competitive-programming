//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ebe5e
//Solution for test set 1
#include<iostream>
#include<vector>
#include<algorithm>

#pragma warning(disable: 4996)
using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, N, K;
    string S;
    cin >> T;
	for(int i = 1; i <= T; i++)
	{        
        cin >> N >> K >> S;
        auto pal = [](string& s)
        {
            for (int i = 0, j = s.size() - 1; i < j; i++, j--)
                if (s[i] != s[j])
                    return false;
            return true;
        };
        string s(N, 'a');
        char const last = 'a' + K - 1;
        int ans = 0;
		while(s != S)
		{
            if (pal(s))
                ans++;
            [last](string& x)
            {
                int pos = x.size() - 1;
                x[pos]++;
            	while(x[pos] > last)
            	{
                    x[pos] = 'a';
                    pos--;
                    x[pos]++;
            	}
            }(s);
            
		}
        
        cout << "Case #" << i << ": " << ans << '\n';
	}
}