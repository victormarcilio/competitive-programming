//https://app.codesignal.com/company-challenges/purestorage/6BaDrGM7xN9sK83bm
vector<vector<int>> blockStorageRewrites(int blockCount, vector<vector<int>> writes, int threshold) {
    vector<int> blocks(blockCount + 1);
    for(int i = 0; i < writes.size(); i++)
    {
        blocks[writes[i][0]]++;
        blocks[writes[i][1] + 1]--;
    }
    vector<vector<int>> answer;
    int start = -1, end = -1, current = 0;
    for(int i = 0; i < blockCount + 1; i++)
    {
        current += blocks[i];
        if(current >= threshold)
        {
            if(start == -1)
                start = end = i;
            else
            {
                if(i == end + 1)
                    end++;
                else
                {
                    answer.push_back({start, end});
                    start = end = i;
                }
            }
        }
        else if(start != -1)
        {
            answer.push_back({start, end});
            start = end = -1;
        }
    }
    if(start != -1)
        answer.push_back({start, end});
    return answer;
    
}
