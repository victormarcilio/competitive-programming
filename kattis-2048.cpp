#include <bits/stdc++.h>
using namespace std;

void left(int grid[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            if (grid[i][j])
            {
                int k = j + 1;
                while (!grid[i][k] && k < 4)
                    ++k;
                if (k < 4 && grid[i][k] == grid[i][j])
                {
                    grid[i][j] <<= 1;
                    grid[i][k] = 0;
                }
            }
            else
            {
                int k = j + 1;
                while(k < 4 && !grid[i][k])
                    k++;
                if(k == 4)
                    break;
                swap(grid[i][k], grid[i][j]);
                j--;
            }
        for (int j = 0; j < 3; j++)
        {
            if (!grid[i][j] && grid[i][j + 1])
                swap(grid[i][j], grid[i][j + 1]);
        }
    }
}

void right(int grid[4][4])
{
    for (int i = 0; i < 4; i++)
        reverse(grid[i], grid[i] + 4);
    left(grid);
    for (int i = 0; i < 4; i++)
        reverse(grid[i], grid[i] + 4);
}
void up(int grid[4][4])
{
    for(int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if(grid[i][j])
            {
                int k = i + 1;
                while(k < 4 && !grid[k][j])
                    k++;
                
                if(k < 4 && grid[k][j] == grid[i][j])
                {
                    grid[i][j] <<= 1;
                    grid[k][j] = 0;
                }

            }
            else
            {
                int k = i + 1;
                while(k < 4 && !grid[k][j])
                    k++;
                if(k == 4)
                    break;
                swap(grid[k][j], grid[i][j]);
                i--;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (!grid[i][j] && grid[i + 1][j])
                swap(grid[i][j], grid[i + 1][j]);
        }
    }
}

void myswap(int grid[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        swap(grid[0][i], grid[3][i]);
        swap(grid[1][i], grid[2][i]);
    }
}

void down(int grid[4][4])
{
    myswap(grid);
    up(grid);
    myswap(grid);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int grid[4][4], op;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> grid[i][j];
    cin >> op;
    if (!op)
        left(grid);
    else if (op == 1)
        up(grid);
    else if (op == 2)
        right(grid);
    else
        down(grid);
    for (int i = 0; i < 4; i++)
    {
        cout << grid[i][0];
        for (int j = 1; j < 4; j++)
            cout << ' ' << grid[i][j];
        cout << '\n';
    }
}
