// https://app.codesignal.com/interview-practice/task/2oxNWXTS8eWBzvnRB/description
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
long long digitTreeSum(Tree<int> * t) {
    long long ans = 0;
    queue<pair<string, Tree<int>*>> q;
    if(t)
    {
        q.push({"", t});
        while(!q.empty())
        {
            auto [number, root] = q.front();
            q.pop();
            number += to_string(root->value);
            if(!root->left && !root->right)
            {
                ans += stol(number);
                continue;
            }
            if(root->left)
                q.push({number, root->left});
            if(root->right)
                q.push({number, root->right});
        }
    }
    return ans;
}
