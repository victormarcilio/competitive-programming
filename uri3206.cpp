#include <bits/stdc++.h>
using namespace std;

struct Robot
{
    char dir;
    int row;
    int col;

    Robot(int r = 0, int c = 0, char d = 0) : row{r}, col{c}, dir{d} {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<pair<char, char>, char> rotation;
    rotation[{'N', 'L'}] = 'W';
    rotation[{'W', 'L'}] = 'S';
    rotation[{'S', 'L'}] = 'E';
    rotation[{'E', 'L'}] = 'N';

    rotation[{'W', 'R'}] = 'N';
    rotation[{'N', 'R'}] = 'E';
    rotation[{'E', 'R'}] = 'S';
    rotation[{'S', 'R'}] = 'W';

    int K, A, B, N, M;
    cin >> K;
    while (K--)
    {
        cin >> A >> B >> N >> M;
        vector<vector<int>> grid(B + 1, vector<int>(A + 1));
        vector<Robot> robots(N + 1);

        int X, Y;
        char facing;
        for (int i = 1; i <= N; i++)
        {
            cin >> X >> Y >> facing;
            grid[Y][X] = i;
            robots[i] = {Y, X, facing};
        }

        int robot, repeat;
        char command;
        bool ok = true;
        for (int i = 0; i < M; i++)
        {
            cin >> robot >> command >> repeat;
            if (ok)
                if (command == 'F')
                {
                    int drow = 0, dcol = 0;
                    switch (robots[robot].dir)
                    {
                    case 'N':
                        drow = 1;
                        break;
                    case 'S':
                        drow = -1;
                        break;
                    case 'E':
                        dcol = 1;
                        break;
                    default:
                        dcol = -1;
                    }
                    int &row = robots[robot].row;
                    int &col = robots[robot].col;
                    int old_row = row;
                    int old_col = col;
                    while (repeat--)
                    {
                        row += drow;
                        col += dcol;
                        if (!row || !col || row > B || col > A)
                        {
                            ok = false;
                            cout << "Robot " << robot << " crashes into the wall\n";
                            break;
                        }
                        if (grid[row][col])
                        {
                            cout << "Robot " << robot << " crashes into robot " << grid[row][col] << '\n';
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                        swap(grid[old_row][old_col], grid[row][col]);
                }
                else
                {
                    repeat = repeat % 4;
                    while (repeat--)
                        robots[robot].dir = rotation[{robots[robot].dir, command}];
                }
        }
        if (ok)
            cout << "OK\n";
    }
}
