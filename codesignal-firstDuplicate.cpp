//https://app.codesignal.com/interview-practice/task/pMvymcahZ8dY4g75q/description
int firstDuplicate(vector<int> a) {
    bitset<100005> b;
    for(int i = 0; i < a.size(); i++)
        if(b[a[i]])
            return a[i];
        else
            b[a[i]] = true;
    return -1;
}
