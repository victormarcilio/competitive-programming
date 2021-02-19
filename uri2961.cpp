#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    cin.ignore();
    string guesses[4], garbage;
    vector<int> scores(4);
    while (N--)
    {
        getline(cin, garbage);
        for (int i = 0; i < 4; i++)
            getline(cin, guesses[i]);

        getline(cin, garbage);
        for (int i = 0; i < 4; i++)
        {
            getline(cin, garbage);
            if (garbage == guesses[i])
                scores[i]++;
        }
    }
    vector<pair<int, int>> order;
    for (int i = 0; i < 4; i++)
        order.push_back({scores[i], i + 1});
    sort(begin(order), end(order));
    cout << order[0].second;
    for (int i = 1; i < 4 && order[i].first == order[0].first; i++)
        cout << ' ' << order[i].second;
    cout << '\n';
}