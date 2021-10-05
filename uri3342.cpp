//https://www.urionlinejudge.com.br/judge/pt/challenges/view/604/4
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int brancas = 0, pretas = 0;
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i % 2 == j % 2)
                brancas++;
            else
                pretas++;
        }
    printf("%d casas brancas e %d casas pretas\n", brancas, pretas);
    
}