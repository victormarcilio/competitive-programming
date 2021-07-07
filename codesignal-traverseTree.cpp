// https://app.codesignal.com/interview-practice/task/PhNPP45hZGNwpPchi/description
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
vector<int> traverseTree(Tree<int> * t) {
    vector<int> ans;
    queue<Tree<int>*> q;
    if(t)
        q.push(t);
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        ans.push_back(top->value);
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);
    }
    return ans;
}
