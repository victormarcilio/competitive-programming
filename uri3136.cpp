#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string command;
    stack<int> s;
    int registers[100];
    while(t--)
    {
        cin >> command;
        if(command[1] == 'r') //print
        {
            int x1 = s.top();
            s.pop();
            cout << x1 << '\n';
        }
        else if(command[2] == 's') //push
        {
            if(command[5] == 'R')
                s.push(registers[stoi(command.substr(6))]);
            else
                s.push(stoi(command.substr(5)));
        }
        else if(command[1] == 'o') //pop
        {
            registers[stoi(command.substr(5))] = s.top();
            s.pop();
        }
        else
        {
            int x1 = s.top();
            s.pop();
            int x2 = s.top();
            s.pop();
            if(command[0] == 'a')
                s.push(x1 + x2);
            else if(command[0] == 's')
                s.push(x2 - x1);
            else if(command[0] == 'm')
                s.push(x1 * x2);
            else
                s.push(x2/x1);
        }
    }
}