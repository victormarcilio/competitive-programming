//https://app.codesignal.com/interview-practice/task/oJXTWuwEZiC6FTw3A/description
int climbingStairs(int n) {
    vector<int> v(n + 1);
    v[1] = 1;
    v[2] = 2;
    for(int i = 3; i <= n; i++)
        v[i] = v[i - 1] + v[i - 2];
    return v[n]; 
}
