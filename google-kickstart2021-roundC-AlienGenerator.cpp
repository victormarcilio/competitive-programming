//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ec1cb
//Solution for test set 1
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>

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
    int T, G;
    cin >> T;
    map<int, vector<int>> m;
    for (int i = 1; i <= 10000; i++)
    {
        int acc = 0;
        for (int j = i; acc <= 10000; j++)
        {
            acc += j;
            m[acc].push_back(i);
        }
    }
	for(int i = 1; i <= T; i++)
	{
        cin >> G;
        cout << "Case #" << i << ": " << m[G].size() << '\n';
	}
}