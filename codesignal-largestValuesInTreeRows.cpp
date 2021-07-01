// https://app.codesignal.com/interview-practice/task/m9vC4ALaAeudkwRTF/description
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
vector<int> largestValuesInTreeRows(Tree<int> * t) {
    queue<Tree<int>*> q;
    if(t)
        q.push(t);
    vector<int> ans;
    while(!q.empty())
    {
        auto front = q.front();
        int high = front->value;
        
        queue<Tree<int>*> q2;
        while(!q.empty())
        {
            auto front = q.front();
            high = max(high,front->value);
            q.pop();
            if(front->left)
                q2.push(front->left);
            if(front->right)
                q2.push(front->right);
        }
        q = move(q2);
        ans.push_back(high);
    }
    return ans;
}
