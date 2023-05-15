#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d\n", &N);
    char command[50], str[50];
    unordered_map<string, int> m(50000);
    for(int i = 0; i < N; i++) 
    {
        scanf("%s %s", command, str);
        if(!strcmp(command, "add"))
        {
            for(int i = 1; str[i]; i++)
            {
                char temp = str[i];
                str[i] = 0;
                m[str]++;
                str[i] = temp;
            }
        }
        else
            printf("%d\n", m[str]);
    }
}
