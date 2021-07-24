//https://app.codesignal.com/interview-practice/task/XBWN6DYRqPrKdMZs8/description
int houseRobber(vector<int> nums) {
    unordered_map<int, int> taking, not_taking;
    if(nums.size())
        taking[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        taking[i] = not_taking[i - 1] + nums[i];
        not_taking[i] = max(not_taking[i - 1], taking[i - 1]);
    }
    return max(taking[nums.size() - 1], not_taking[nums.size() - 1]);
}
