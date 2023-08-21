//https://leetcode.com/problems/stream-of-characters/description/
struct node{
    map<char, node*> m;
    bool ends = false;
};

class StreamChecker {
public:
    node root;
    string acc;
    StreamChecker(vector<string>& words) {
        for(auto& w : words)
        {
            auto current = &root;
            for(int i = w.size() - 1; i >= 0; i--)
            {
                auto c = w[i];
                if(current->m.find(c) == current->m.end())
                    current->m[c] = new node();
                current = current->m[c];
            }
            current->ends = true;
        }
    }
    
    bool query(char letter) {
        acc += letter;
        auto current = &root;
        for(int i = acc.size() - 1; i >= 0; i--)
            if(current->m.find(acc[i]) != current->m.end())
            {
                current = current->m[acc[i]];
                if(current->ends)
                    return true;
            }
            else 
                return false;
        
        return current->ends;
    }
};
