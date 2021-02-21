#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& values, int limit, int players)
{
    int playersNeeded = 1;
    int cardsCount = 0;
    int maxCards = 0;
    int sum = 0;

    for(int i = 0; i < values.size(); i++)
    {
        if(values[i] > limit)
            return 0;
        if(values[i] + sum > limit)
        {
            if(++playersNeeded > players)
                return 0;
            maxCards = max(maxCards, cardsCount);
            sum = values[i];
            cardsCount = 1;
        }
        else
        {
            sum += values[i];
            cardsCount++;
        }
    }
    return max(maxCards, cardsCount);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> values{{"A", 1}, {"J", 11}, {"Q", 12}, {"K", 13}, {"10", 10}};
    for (char c = '2'; c <= '9'; c++)
        values[string{c}] = c - '0';

    int nCartas, nJogadores;
    cin >> nCartas >> nJogadores;

    string card;
    vector<int> cards(nCartas);

    for (int i = 0; i < nCartas; i++)
    {
        cin >> card;
        cards[i] = values[card];
    }
    
    for(int i = 1; ; i++)
    {
        int ans = check(cards, i, nJogadores);
        if(ans)
        {
            cout << ans << ' ' << i << '\n';
            break;
        }
    }
}
