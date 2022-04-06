//https://www.beecrowd.com.br/judge/pt/problems/view/3367
#include <bits/stdc++.h>
using namespace std;

map<string, string> next_day{{"Sun", "Mon"}, {"Mon", "Tue"}, {"Tue", "Wed"}, {"Wed", "Thu"}, {"Thu", "Fri"}, {"Fri", "Sat"}, {"Sat", "Sun"}};
map<string, string> next_renew{{"Mon", "Wed"}, {"Tue", "Thu"}, {"Wed", "Fri"}, {"Thu", "Mon"}, {"Fri", "Mon"}};
map<string, int> days_to_renew{{"Mon", 30}, {"Tue", 30}, {"Wed", 30}, {"Thu", 32}, {"Fri", 31}};
string get_deposit_day(string curr, int days_elapsed)
{    
    while(days_elapsed % 7)
    {
        curr = next_day[curr];
        ++days_elapsed;
    }
    return curr;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string day;
    int N;
    cin >> day >> N;
    int64_t best = 35, elapsed_days;
    while(N--)
    {
        cin >> elapsed_days;
        string deposit_day = get_deposit_day(day, elapsed_days);
        if(!elapsed_days)
        {
            best = min<int64_t>(best, days_to_renew[deposit_day]);
            continue;
        }
        
        while(deposit_day != "Mon" && days_to_renew[deposit_day] <= elapsed_days)
        {
            elapsed_days -= days_to_renew[deposit_day];
            deposit_day = next_renew[deposit_day];
        }
        elapsed_days = elapsed_days % 91;        
        while(elapsed_days > 0)
        {
            int curr = 0;
            while(curr < 30 || deposit_day == "Sun" || deposit_day == "Sat")
            {
                ++curr;
                --elapsed_days;
                deposit_day = next_day[deposit_day];
            }
        }
        best = min(best, -elapsed_days);
    }
    cout << best << '\n';
}