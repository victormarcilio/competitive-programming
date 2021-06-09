//https://app.codesignal.com/company-challenges/purestorage/vfaESus49J4N9JHim
vector<int> longestUncorruptedSegment(vector<int> sourceArray, vector<int> destinationArray) {
    vector ans{0, 0};
    int best = 0, current = 0, start; 
    for(int i = 0; i < sourceArray.size(); i++)
        if(sourceArray[i] == destinationArray[i])
        {
            if(!current)
                start = i;
            current++;
            if(current > best)
                ans = {current, start};
            best = max(current, best);
        }
        else
            current = 0;
    return ans;        
        
}
