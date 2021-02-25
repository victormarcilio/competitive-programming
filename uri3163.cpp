#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cardeal;
    string line;
    queue<string> queues[5];
    int total = 0;
    while(cin >> line, line[0] != '0')
        if(line[0] == '-')
            cardeal = line[1] - '0';
        else
        {
            total++;
            queues[cardeal].push(line);
        }
    int sequence[] = {1, 3, 2, 4};
    for(cardeal = 0; ; cardeal++)
        if(!queues[sequence[cardeal]].empty())
        {
            cout << queues[sequence[cardeal]].front();
            queues[sequence[cardeal]].pop();
            break;
        }
    total--;
    while(total)
    {
        ++cardeal;
        if(cardeal == 4)
            cardeal = 0;
        if(!queues[sequence[cardeal]].empty())
        {
            cout << ' ' << queues[sequence[cardeal]].front();
            queues[sequence[cardeal]].pop();
            --total;
        }
    }
    cout << '\n';
}
