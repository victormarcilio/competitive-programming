//https://app.codesignal.com/company-challenges/mz/jNLxCZe7feQMDvjH4
int resourceCatchUp(vector<int> logOut, vector<int> logIn) {
    int ini = logOut[0];
    int fim = logIn[0];
    int hours = 0;
    while(ini < fim)
    {
        ini += 3600;
        hours++;
    }
    return (logOut[1] - logIn[1])/hours;
}
