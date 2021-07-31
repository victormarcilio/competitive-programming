//https://leetcode.com/problems/01-matrix/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 100000));
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(!mat[i][j])
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if(x < rows - 1 && ans[x + 1][y] > ans[x][y] + 1)
            {
                q.push({x + 1, y});
                ans[x + 1][y] = ans[x][y] + 1;
            }
            if(x > 0 && ans[x - 1][y] > ans[x][y] + 1)
            {
                q.push({x - 1, y});
                ans[x - 1][y] = ans[x][y] + 1;
            }
            if(y < cols - 1 && ans[x][y + 1] > ans[x][y] + 1)
            {
                q.push({x, y + 1});
                ans[x][y + 1] = ans[x][y] + 1;
            }
            if(y > 0 && ans[x][y - 1] > ans[x][y] + 1)
            {
                q.push({x, y - 1});
                ans[x][y - 1] = ans[x][y] + 1;
            }
        }
        return ans;
    }
};
