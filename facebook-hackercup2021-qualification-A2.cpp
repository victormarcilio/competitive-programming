//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2
#include <map>
#include <string>
#include <iostream>
#include <set>

using namespace std;

const int INF = 500000000;

void calculate_distances(map<pair<char, char>, int>& costs, set<char>& visited, char current, const char root)
{
    visited.insert(current);
    for (char destination = 'A'; destination <= 'Z'; destination++)
    {
        int from_current_to_destination = costs[{current, destination}];
        int from_root_to_destination = costs[{root, destination}];
        int from_root_to_current = costs[{root, current}];

        if (from_root_to_current + from_current_to_destination < from_root_to_destination)
        {
            costs[{root, destination}] = from_root_to_current + from_current_to_destination;
            calculate_distances(costs, visited, destination, root);
        }
        if (from_current_to_destination != INF && visited.find(destination) == visited.end())
            calculate_distances(costs, visited, destination, root);
    }
}

int main()
{
    int n, k;
    string word;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> word >> k;
        map<char, int> frequency;
        for (auto c : word)
            frequency[c]++;
        map<pair<char, char>, int> costs;
        for (char from = 'A'; from <= 'Z'; from++)
            for (char to = 'A'; to <= 'Z'; to++)
                costs[{from, to}] = INF;
            
        while (k--)
        {
            string transition;
            cin >> transition;
            costs[{transition[0], transition[1]}] = 1;
        }

        for (char from = 'A'; from <= 'Z'; from++)
            costs[{from, from}] = 0;

        for (char from = 'A'; from <= 'Z'; from++)
        {
            set<char> visited;
            calculate_distances(costs, visited, from, from);
        }
        int ans = INF;
        for (char target = 'A'; target <= 'Z'; target++)
        {
            bool possible = true;
            int current = 0;
            for (const auto& [letter, freq] : frequency)
            {
                auto par = make_pair(letter, target);
                if (costs[par] == INF)
                {
                    possible = false;
                    break;
                }
                current += costs[par] * freq;
            }
            if(possible)
                ans = min(ans, current);
        }
        if (ans == INF)
            ans = -1;
        cout << "Case #" << i << ": " << ans << '\n';
    }
}