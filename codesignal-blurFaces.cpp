//https://app.codesignal.com/company-challenges/verkada/GCykhwZcTrusPZfeQ
vector<vector<double>> blurFaces(vector<vector<int>> img) {
    int r = img.size();
    int c = img[0].size();
    vector<vector<int>> v2(r + 2, vector<int>(c + 2));
    for(int i = 0; i < r; i ++)
        for(int j = 0; j < c; j++)
            v2[i + 1][j + 1] = img[i][j];
        
    vector<vector<double>> ans(r, vector<double>(c));
    
    for(int i = 1; i <= r; i ++)
        for(int j = 1; j <= c; j++)
        {
            int neighbors = 8;
            if(i == 1)
                neighbors -= 3;
            if(i == r )
                neighbors -= 3;
            if(j == 1)
                neighbors -= 3;
            if(j == c)
                neighbors -= 3;
            if((i == 1 || i == r) && (j == 1 || j == c))
                neighbors++;   
            if(r > 1 || c > 1)
                neighbors = max(neighbors, 1);
            double acc = v2[i - 1][j - 1] + v2[i - 1][j] + v2[i - 1][j + 1] + v2[i][j - 1] + v2[i][j + 1] + v2[i + 1][j - 1] + v2[i + 1][j] + v2[i + 1][j + 1];
            
            ans[i - 1][j - 1] = acc/neighbors;
        }
    return ans;
}
