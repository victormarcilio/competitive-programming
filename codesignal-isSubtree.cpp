// https://app.codesignal.com/interview-practice/task/mDpAJnDQkJqaYYsCg/description
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool isSame(Tree<int> * t1, Tree<int> * t2)
{
    if(!t1 && !t2)
        return true;
    if(t1 && !t2 || t2 && !t1)
        return false;
    return t1->value == t2->value && isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
}

bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if(!t2)
        return true;
    
    if(t1)
    {
        queue<Tree<int>*> q;
        q.push(t1);
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front->value == t2->value && isSame(front, t2))
                return true;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }
    return false;
}
