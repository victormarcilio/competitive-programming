//https://app.codesignal.com/company-challenges/spacex/EcQD8xYZotKM77FKM
bool launchSequenceChecker(vector<string> systemNames, vector<int> stepNumbers) {
    map<string, int> m;
    for(int i = 0; i < systemNames.size(); i++)
        if(m[systemNames[i]] >= stepNumbers[i])
            return false;
        else
            m[systemNames[i]] = stepNumbers[i];
    return true;
}
