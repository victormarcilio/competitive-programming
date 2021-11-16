//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008d9a88
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
#include<queue>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T, N;
    string s;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> N >> s;
        int ans = 0;
        //blue
        for (int j = 0; j < N; ++j)
        {
            if (s[j] == 'B' || s[j] == 'G' || s[j] == 'A' || s[j] == 'P')
            {
                ++ans;                
                while (j + 1 < N && (s[j + 1] == 'B' || s[j + 1] == 'G' || s[j + 1] == 'A' || s[j + 1] == 'P'))
                    ++j;
            }
        }
        //red
        for (int j = 0; j < N; ++j)
        {
            if (s[j] == 'R' || s[j] == 'O' || s[j] == 'P' || s[j] == 'A')
            {
                ++ans;                
                while (j + 1 < N && (s[j + 1] == 'R' || s[j + 1] == 'O' || s[j + 1] == 'P' || s[j + 1] == 'A'))
                    ++j;
            }
        }
        //yellow
        for (int j = 0; j < N; ++j)
        {
            if (s[j] == 'Y' || s[j] == 'O' || s[j] == 'G' || s[j] == 'A')
            {
                ++ans;                
                while (j + 1 < N && (s[j + 1] == 'Y' || s[j + 1] == 'O' || s[j + 1] == 'G' || s[j + 1] == 'A'))
                    ++j;
            }
        }
        cout << "Case #" << i << ": " << ans << '\n';
    }
}
