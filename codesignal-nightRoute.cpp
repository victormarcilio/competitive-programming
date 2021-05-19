//https://app.codesignal.com/company-challenges/uber/tucq8L9FB7QyDZ4M6
int nightRoute(vector<vector<int>> city) {
    int N = city.size();
    for(int k = 0; k < N; k++)
        for(int j = 0; j < N; j++)
            if(city[k][j] == -1)
                city[k][j] = 5000000;
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
    return city[0][N - 1];
}
