//https://www.urionlinejudge.com.br/judge/pt/challenges/view/605/2
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x;
    vector<string> v(101);
    v[1] = "ONE";
    v[2] = "TWO";
    v[3] = "THREE";
    v[4] = "FOUR";
    v[5] = "FIVE";
    v[6] = "SIX";
    v[7] = "SEVEN";
    v[8] = "EIGHT";
    v[9] = "NINE";
    v[10] = "TEN";
    v[11] = "ELEVEN";
    v[12] = "TWELVE";
    v[13] = "THIRTEEN";
    v[14] = "FOURTEEN";
    v[15] = "FIFTEEN";
    v[16] = "SIXTEEN";
    v[17] = "SEVENTEEN";
    v[18] = "EIGHTEEN";
    v[19] = "NINETEEN";
    v[20] = "TWENTY";
    v[30] = "THIRTY";
    v[40] = "FORTY"; 
    v[50] = "FIFTY";
    v[60] = "SIXTY";
    v[70] = "SEVENTY";
    v[80] = "EIGHTY";
    v[90] = "NINETY";
    v[100] = "ONE HUNDRED";
    for (int i = 1; i < 10; i++)
    {
        for (int j = 20; j < 100; j += 10)
            v[j + i] = v[j] + " " + v[i];
    }
    
    cin >> x;
    for (int i = 0; i < 1000; i++)
        x = v[x].size();
    cout << x << '\n';
    
}