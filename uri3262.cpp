#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    unordered_map<string, int> ascii;
    ascii["**** ** ** ****"] = 0;
    ascii["  *  *  *  *  *"] = 1;
    ascii["***  *****  ***"] = 2;
    ascii["***  ****  ****"] = 3;
    ascii["* ** ****  *  *"] = 4;
    ascii["****  ***  ****"] = 5;
    ascii["****  **** ****"] = 6;
    ascii["***  *  *  *  *"] = 7;
    ascii["**** ***** ****"] = 8;
    ascii["**** ****  ****"] = 9;
    vector<string> numbers;
    getline(cin, line);
    for (int i = 0; i < line.size(); i += 4)
        numbers.push_back(line.substr(i, 3));

    for (int i = 1; i < 5; i++)
    {
        getline(cin, line);
        for (int j = 0; j < numbers.size(); j++)
            numbers[j] += line.substr(j * 4, 3);
    }   

    int sum = 0;
    for (string &num : numbers)
    {
        if (!ascii.count(num))
        {
            cout << "BOOM!!\n";
            return 0;
        }
        sum += ascii[num];
    }
    if (sum % 3 == 0 && ascii[numbers.back()] % 2 == 0)
        cout << "BEER!!\n";
    else
        cout << "BOOM!!\n";
}
