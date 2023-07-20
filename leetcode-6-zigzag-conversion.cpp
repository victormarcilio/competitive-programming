//https://leetcode.com/problems/zigzag-conversion/description/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> lines(numRows);
        int i = 0;
        bool increasing = true;
        for (auto c : s) {
            lines[i] += c;
            if (increasing) {
                i++;
                if(i == numRows) {
                    increasing = false;
                    i -= 2;
                }
            } else {
                i--;
                if (i < 0) {
                    increasing = true;
                    i += 2;
                }
            }
        }
        string answer;
        for (auto &line : lines)
            answer += line;
        return answer;
    }
};
