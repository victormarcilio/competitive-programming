//https://app.codesignal.com/company-challenges/codesignal/gJMBmTwHHMF8mbQvH
double companyBotStrategy(vector<vector<int>> trainingData) {
    double ans = 0;
    int correct = 0;
    for(auto& data : trainingData)
        if(data[1] == 1)
        {
            correct++;
            ans += data[0];
        }
    return correct ? ans/correct : 0;
}
