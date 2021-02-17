#include <bits/stdc++.h>
using namespace std;

//Statement not so clear about (lower/upper) cases.
//The input must be considered as case-insensitive.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char map[200];
    map['A'] = map['B'] = map['C'] = '2';
    map['D'] = map['E'] = map['F'] = '3';
    map['G'] = map['H'] = map['I'] = '4';
    map['J'] = map['K'] = map['L'] = '5';
    map['M'] = map['N'] = map['O'] = '6';
    map['P'] = map['Q'] = map['R'] = map['S'] = '7';
    map['T'] = map['U'] = map['V'] = '8';
    map['W'] = map['X'] = map['Y'] = map['Z'] = '9';
    map['*'] = '*';
    map['#'] = '#';
    for(char i = '0'; i <= '9'; i++)
        map[i] = i;
    char texto[400];
    while(gets(texto))
    {
        int j = 0;
        for(int i = 0; texto[i]; i++)
            if(isalnum(texto[i]) || texto[i] == '#' || texto[i] == '*')
                texto[j++] = map[toupper(texto[i])];
        texto[j] = 0;
        puts(texto);
    }
}
