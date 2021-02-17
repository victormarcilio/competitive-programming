#include <bits/stdc++.h>
using namespace std;

char estado[] = "*ogo*erdi";
int transition(int current_state, char letter)
{
    if(current_state == 4 || current_state == 9)
        return -1;
    if (current_state == 0)
        if (letter = 'j')
            return 1;
        else if (letter == 'p')
            return 5;
    if (letter == estado[current_state])
        return current_state + 1;
    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char text[100100];
    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        int state = 0;
        gets(text);
        int best = 0;
        int current = 0;
        for (char *c = text; *c; ++c)
            if (isalpha(*c))
            {
                ++current;
                state = transition(state, tolower(*c));
            }
            else
            {
                if (state == 4 || state == 9)
                {
                    best = max(best, current);
                    current = 0;
                }
                state = 0;
            }
        printf("%d\n", max(current, best));
    }
}
