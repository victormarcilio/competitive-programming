//https://app.codesignal.com/company-challenges/asana/2vJMZnQzdkkhCvmxs
vector<int> tasksTypes(vector<int> deadlines, int day) {
    int t = 0, up = 0, la = 0;
    for(int i : deadlines)
        if(i <= day)
            t++;
        else if(day + 7 >= i)
            up++;
        else
            la++;
    return {t, up, la};
}
