#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while(getline(cin, line), line.rfind("#include"sv, 8) != string::npos || line.rfind("#define"sv, 8) != string::npos)
        cout << line << '\n';
    int indent = 0;
    bool opened = false;
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] == '(')
            opened = true;
        else if(line[i] == ')')
            opened = false;

        if(line[i] == '{')
        {
            cout << '\n';
            cout << setw(indent) << setfill('.') << "";
            cout << "{\n";
            indent += 4;
            cout << setw(indent) << setfill('.') << "";
        }
        else if(line[i] == '}')
        {
            cout << '\n';
            indent -= 4;
            cout << setw(indent) << setfill('.') << "";
            cout << "}";
            if(line[i + 1] != '}')
            {
                cout << '\n';
               cout << setw(indent) << setfill('.') << "";
            }
        }
        else if(line[i] == ';')
        {
            cout << ';';
            if(!opened && line[i + 1] != '}')
            {
                cout << '\n';
                cout << setw(indent) << setfill('.') << "";
            }
        }
        else
            cout << line[i];
    }
}
