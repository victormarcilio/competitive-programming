#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    string letters;
    for (int caso = 1; caso <= t; caso++)
    {
        cin >> n >> letters;
        
        int start_left = 0;
        int start_right = 0;
        bool left = true;
        for (int i = 0; i < n; i++)
        {
            if (left && letters[i] == 'O')
            {
                left = false;
                start_left++;
            }
            else if (!left && letters[i] == 'X')
            {
                left = true;
                start_left++;
            }
        }
        left = false;
        for (int i = 0; i < n; i++)
        {
            if (left && letters[i] == 'O')
            {
                left = false;
                start_right++;
            }
            else if (!left && letters[i] == 'X')
            {
                left = true;
                start_right++;
            }
        }

        cout << "Case #" << caso << ": " << min(start_left, start_right) << '\n';
    }
}