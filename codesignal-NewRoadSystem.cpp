//https://app.codesignal.com/arcade/graphs-arcade/kingdom-roads/nCMisf4ZKpDLdHevE
bool newRoadSystem(vector<vector<bool>> roadRegister) {
    int size = roadRegister.size();
    for(int i = 0; i < size; i++)
    {
        int row = 0;
        int col = 0;
        for(int j = 0; j < size; j++)
        {
            row += roadRegister[i][j];
            col += roadRegister[j][i];
        }
        if(row != col)
            return false;
    }
    return true;
}
