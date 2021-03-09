#include <bits/stdc++.h>

using namespace std;

int lcs( string& X, string &Y, int m, int n )  
{  
    int L[500][500];  
    int i, j;  
      
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  

    return L[m][n];  
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line, s1, s2;
    cin >> line;
    for(auto i : line)
    {
        if(isupper(i))
            s1.push_back(i);
        else
        {
            s1.push_back(toupper(i));
            s1.push_back(toupper(i));
        }
    }
    cin >> line;
    for(auto i : line)
    {
        if(isupper(i))
            s2.push_back(i);
        else
        {
            s2.push_back(toupper(i));
            s2.push_back(toupper(i));
        }
    }
    cout << lcs(s1, s2, s1.size(), s2.size()) << '\n';
}