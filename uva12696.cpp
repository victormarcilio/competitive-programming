//https://onlinejudge.org/external/126/12696.pdf
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int total = 0;
    double length, width, weight, depth;
    cin >> n;
    while(n--)
    {
        cin >> length >> width >> depth >> weight;
        if((length <= 56 && width <= 45 && depth <= 25 || length + width + depth <= 125) && weight <= 7)
        {
            total++;
            cout << "1\n";
        }
        else
            cout << "0\n";
    }
    cout << total << '\n';
}
