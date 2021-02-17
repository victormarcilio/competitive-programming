#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string number;
    while(N--)
    {
        cin >> number;
        sort(begin(number), end(number));
        if(number[0] == '0')
            swap(number[0], number[number.find_first_not_of('0')]);
        cout << number << '\n';
    }
}
