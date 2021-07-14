//https://app.codesignal.com/challenge/MCvv9beeFd96hWwRe
vector<string> shoppingCart(vector<string> requests) {
    vector<string> ans;
    map<string, int> counts;
    for(auto& req : requests)
    {
        if(req == "checkout")
        {
            counts.clear();
            ans.clear();
        }
        else
        {
            istringstream iss(req);
            string command, item;
            getline(iss, command, ':');
            command.pop_back();
            iss.get();
            getline(iss, item, ':');
            if(command == "add")
            {
                counts[item] = 1;
                ans.push_back(item);
            }
            else if(command == "remove")
            {
                counts.erase(counts.find(item));
                ans.erase(find(begin(ans), end(ans), item));
            }
            else
            {
                item.pop_back();
                iss >> command;
                counts[item] += stoi(command);
            }
        }
    }
    for(int i = 0; i < ans.size(); i++)
        ans[i] += " : " + to_string(counts[ans[i]]);
    return ans;
}
