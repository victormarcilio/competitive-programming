#include <bits/stdc++.h>
using namespace std;

map<int, string> mapa;

void print(string numero)
{
    if(numero == "100")
    {
        cout << "cem";
        return;
    }
    if(mapa.count(stoi(numero)))
    {
        cout << mapa[stoi(numero)];
        return;
    }
    int T = numero.size();
    if(T < 2 || T == 2 && numero[0] == '1')
        cout << mapa[stoi(numero)];
    else if(T == 2)
    {
        cout << mapa[10*(numero[0] - '0')];
        if(numero[1] != '0')
            cout << " e " << mapa[numero[1] - '0'];
    }
    else if(T == 3)
    {
        if(numero == "100")
            cout << "cem";
        else
        {
            cout << mapa[100*(numero[0] - '0')] << " e ";
            if(numero[1] != '0')
            {
                if(numero[1] < '2')
                    cout << mapa[stoi(numero.substr(1))];
                else
                {
                    cout << mapa[10*(numero[1] - '0')];
                    if(numero[2] != '0')
                        cout << " e " << mapa[numero[2] - '0'];
                }
            }
            else
                cout << mapa[numero[2] - '0'];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mapa[0] = "zero";
    mapa[1] = "um";
    mapa[2] = "dois";
    mapa[3] = "tres";
    mapa[4] = "quatro";
    mapa[5] = "cinco";
    mapa[6] = "seis";
    mapa[7] = "sete";
    mapa[8] = "oito";
    mapa[9] = "nove";
    mapa[10] = "dez";
    mapa[11] = "onze";
    mapa[12] = "doze";
    mapa[13] = "treze";
    mapa[14] = "quatorze";
    mapa[15] = "quinze";
    mapa[16] = "dezesseis";
    mapa[17] = "dezessete";
    mapa[18] = "dezoito";
    mapa[19] = "dezenove";
    mapa[20] = "vinte";
    mapa[30] = "trinta";
    mapa[40] = "quarenta";
    mapa[50] = "cinquenta";
    mapa[60] = "sessenta";
    mapa[70] = "setenta";
    mapa[80] = "oitenta";
    mapa[90] = "noventa";
    mapa[100] = "cento";
    mapa[200] = "duzentos";
    mapa[300] = "trezentos";
    mapa[400] = "quatrocentos";
    mapa[500] = "quinhentos";
    mapa[600] = "seiscentos";
    mapa[700] = "setecentos";
    mapa[800] = "oitocentos";
    mapa[900] = "novecentos";
    
    string numero;
    while(cin >> numero)
    {
        if(numero.size() > 3)
        {
            if(numero.size() != 4 || numero[0] != '1')
            {
                print(numero.substr(0, numero.size() - 3));
                cout << " mil";
            }
            else
                cout << "mil";
            numero = numero.substr(numero.size() - 3);
            if(numero == "100")
            {
                cout << " e cem\n";
                continue;
            }
            if(stoi(numero) && mapa.count(stoi(numero)))
            {
                cout << " e " << mapa[stoi(numero)] << '\n';
                continue;
            }
            while(numero.size() && numero[0] == '0')
                numero = numero.substr(1);
            if(numero.size())
            {
                if(numero.size() < 3)
                    cout << " e ";
                else
                    cout << ' ';
                print(numero);
            }
        }
        else
            print(numero);
        cout << '\n';
    }
}
