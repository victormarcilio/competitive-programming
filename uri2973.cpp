#include <bits/stdc++.h>

using namespace std;

int check(const vector<int>& pipocas, int players, int limit)
{
    int player_count = 1;
    int eat_count = 0;
    int most_eaten = 0;
    for(int i = 0; i < pipocas.size(); i++)
    {
        if(pipocas[i] > limit)
            return 0;
        if(pipocas[i] + eat_count > limit)
        {
            ++player_count;
            if(player_count > players)
                return 0;
            most_eaten = max(most_eaten, eat_count);
            eat_count = pipocas[i];
        }
        else
            eat_count += pipocas[i];
    }

    return max(eat_count, most_eaten);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C, T;
    cin >> N >> C >> T;
    vector<int> pipocas(N);
    for(int i = 0; i < N; i++)
        cin >> pipocas[i];
    
    int mid, L = 1, R = accumulate(begin(pipocas), end(pipocas), 0);
    int temp;
    while(L <= R)
    {
        mid = (L + R)/2;
        if(temp = check(pipocas, C, mid))
            if(check(pipocas, C, temp - 1))
                R = mid - 1;
            else
                break;
        else
            L = mid + 1;
    }
    int temp2 = temp - 1;
    while(check(pipocas, C, temp2--))
        temp = temp2;

    cout << temp/T + (temp % T != 0) << '\n';
}
