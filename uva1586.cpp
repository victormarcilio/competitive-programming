#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string line;
    double v[200];
    v['C'] = 12.01;
    v['H'] = 1.008;
    v['O'] = 16;
    v['N'] = 14.01;
    while (N--)
    {
        cin >> line;
        double total = 0;
        for (int i = 0; i < line.size(); i++)
            if (isdigit(line[i]))
            {
                string numbers = "";
                double val = v[line[i - 1]];
                while (i < line.size() && isdigit(line[i]))
                {
                    numbers += line[i];
                    i++;
                }
                i--;
                total += val * (stoi(numbers) - 1);
            }
            else
                total += v[line[i]];

        printf("%.3lf\n", total);
    }
}
