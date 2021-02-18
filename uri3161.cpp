#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    vector<string> fruits(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> fruits[i];
        for (auto &c : fruits[i])
            c = tolower(c);
    }
    vector<string> lines(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> lines[i];
        for (auto &c : lines[i])
            c = tolower(c);
    }
    for (auto &fruit : fruits)
    {
        string reversed(fruit);
        reverse(begin(reversed), end(reversed));
        bool likes = false;
        for (auto &line : lines)
            if (line != fruit && (line.find(fruit) != string::npos || line.find(reversed) != string::npos))
            {
                likes = true;
                break;
            }
        cout << "Sheldon " << (likes ? "come" : "detesta") << " a fruta " << fruit << '\n';
    }
}