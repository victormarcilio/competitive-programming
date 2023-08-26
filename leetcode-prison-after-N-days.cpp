//https://leetcode.com/problems/prison-cells-after-n-days/
class Solution {
public:
    vector<int> get_next(vector<int>& cells) {
        vector<int> next(8);
        for(int i = 1; i < 7; i++)
            next[i] = cells[i - 1] == cells[i + 1];
        return next;
    }
    vector<int> prisonAfterNDays(const vector<int>& cells, int n) {
        set<vector<int>> s;
        vector<vector<int>> vs;
        int i, cycle = -1;
        auto next = cells;
        s.insert(next);
        vs.push_back(next);
        for(i = 0; i < n; i++)
        {
            next = get_next(next);
            if(s.count(next))
                break;

            s.insert(next);
            vs.push_back(next);
        }
        if (i == n)
            return next;

        for (int j = 0; j < vs.size(); j++)
            if(vs[j] == next)
            {
                i = j;
                break;
            }
        n -= i;
        vector<vector<int>> loop{vs.begin() + i, vs.end()};
        return loop[n % loop.size()];
    }
};
