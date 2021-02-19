#include<bits/stdc++.h>

// HINT: don't forget to check if someone has won before the game even starts!
// In case of multiple possible winners, the winner will be one with smallest ID!

using namespace std;

map<char, int> values = { {'A', 1}, {'D', 10}, {'Q', 11}, {'J', 12}, {'K', 13} };

struct deck
{
    vector<int> cards;
    bool has_joker = false;
    bool joker_available = false;
    deck(string hand)
    {
        for (auto i : hand)
            cards.push_back(values[i]);
        sort(begin(cards), end(cards));
    }
    void receive(int card)
    {
        if (card == 500)
            has_joker = true;
        else
        {
            cards.push_back(card);
            sort(begin(cards), end(cards));
        }
    }

    int give()
    {
        if (has_joker)
        {
            if (joker_available)
            {
                joker_available = has_joker = false;
                return 500;
            }
            joker_available = true;
        }
        vector<int> count(14);
        int less = 5, less_repeated_number;
        for (int i : cards)
            ++count[i];
        for (int i = 1; i < 14; i++)
            if (count[i] && count[i] < less)
            {
                less = count[i];
                less_repeated_number = i;
            }
        auto it = find(begin(cards), end(cards), less_repeated_number);
        int chosen = *it;
        cards.erase(it);
        return chosen;
    }

    bool won()
    {
        return !has_joker && cards.front() == cards.back();
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    for (char i = '2'; i <= '9'; i++)
        values[i] = i - '0';
    cin >> N >> K;
    vector<deck> hands;
    
    string hand;
    for (int i = 0; i < N; ++i)
    {
        cin >> hand;
        hands.emplace_back(hand);
    }
    hands[--K].has_joker = true;
    for(int i = 0; i < N; i++)
        if(hands[i].won())
        {
            cout << i + 1 << '\n';
            return 0;
        }
    while (true)
    {
        int passed = hands[K].give();
        if(hands[K].won())
            break;
        if (++K == N)
            K = 0;
        hands[K].receive(passed);
    }
    cout << K + 1 << '\n';
}