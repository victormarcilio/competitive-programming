//https://leetcode.com/problems/jump-game-ii/submissions/
class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        int target = nums.size() - 1;
        vector<bool> visited(100100);
        while(true)
        {
            auto [pos, jumps] = q.front();
            q.pop();
            if(pos == target)
                return jumps;
            for(int i = 1; i <= nums[pos]; i++)
                if(!visited[pos + i])
                {
                    q.push({pos + i, jumps + 1});
                    visited[pos + i] = true;
                }
        }
    }
};
