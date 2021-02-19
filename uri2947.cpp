#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int problems, students;
    string unlucky, answers;
    cin >> problems >> unlucky >> students;
    vector<map<char, int>> alternatives_per_question(problems);
    while(students--)
    {
        cin >> answers;
        for(int i = 0; i < problems; ++i)
            if(answers[i] != unlucky[i])
                ++alternatives_per_question[i][answers[i]];
    }
    int result = 0;
    for(int i = 0; i < problems; ++i)
    {
        int best = 0;
        for(auto &it : alternatives_per_question[i])
            best = max(best, it.second);
        result += best;
    }
    cout << result << '\n';
}
