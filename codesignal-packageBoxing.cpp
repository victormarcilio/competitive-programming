//https://app.codesignal.com/company-challenges/jet/SrM76w6eoxioTMiCK
int packageBoxing(vector<int> pkg, vector<vector<int>> boxes) {
    sort(begin(pkg), end(pkg));
    int ans = -1, vol = 100000000;
    for(int i = 0; i < boxes.size(); i++)
    {
        sort(begin(boxes[i]), end(boxes[i]));
        int v = boxes[i][0] * boxes[i][1] * boxes[i][2];
        if(v <= vol && boxes[i][0] >= pkg[0] && boxes[i][1] >= pkg[1] && boxes[i][2] >= pkg[2])
        {
            ans = i;
            vol = v;
        }
    }
    return ans;
}
