//https://app.codesignal.com/company-challenges/wizeline/toyP6DzaKAPq2Yhma
struct method
{
    string name;
    int count;  
};
struct subproject
{
    string name;
    int count;
    vector<method> methods;  
};
struct project
{
    string name;
    int count;
    vector<subproject> subprojects;
};

void insertM(vector<method>& v, string met)
{
    for(int i = 0; i < v.size(); i++)
        if(v[i].name == met)
        {
            v[i].count++;
            return;
        }
    v.push_back({met, 1});
}

void insertS(vector<subproject>& v, string sub, string met)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].name == sub)
        {
            v[i].count++;
            insertM(v[i].methods, met);
            return;
        }
    }
    v.push_back({sub, 1, {}});
    insertM(v.back().methods, met);
}

void insertP(vector<project>& v, string proj, string sub, string met)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].name == proj)
        {
            v[i].count++;
            insertS(v[i].subprojects, sub, met);
            return;
        }
    }
    v.push_back({proj, 1, {}});
    insertS(v.back().subprojects, sub, met);
}
void recM(const vector<method>& v, vector<string>& ans)
{
    for(int i = 0; i < v.size(); i++)
        ans.push_back(v[i].name + " (" + to_string(v[i].count) + ")");
}

void recS(const vector<subproject>& v, vector<string>& ans)
{
    for(int i = 0; i < v.size(); i++)
    {
        ans.push_back(v[i].name + " (" + to_string(v[i].count) + ")");
        recM(v[i].methods, ans);
    }
}

void recP(const vector<project>& v, vector<string>& ans)
{
    for(int i = 0; i < v.size(); i++)
    {
        ans.push_back(v[i].name + " (" + to_string(v[i].count) + ")");
        recS(v[i].subprojects, ans);
    }
}

vector<string> countAPI(vector<string> calls) {
    vector<project> projects;
    for(auto& call : calls)
    {
        istringstream iss(call.substr(1));
        string proj, sub, met;
        getline(iss, proj, '/');
        getline(iss, sub, '/');
        getline(iss, met);
        proj = "--" + proj;
        sub = "----" + sub;
        met = "------" + met;
        insertP(projects, proj, sub, met);
    }
    vector<string> ans;
    recP(projects, ans);
    return ans;
}
