// https://app.codesignal.com/interview-practice/task/TG4tEMPnAc3PnzRCs/description
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool hasPathWithGivenSum(Tree<int> * t, int s) {
    if(t)
    {
        bool possible = false;
        if(!t->right && !t->left)
            return t->value == s;
        if(t->right)
        {
            t->right->value += t->value;
            possible = possible || hasPathWithGivenSum(t->right, s);
        }
        if(t->left)
        {
            t->left->value += t->value;
            possible = possible || hasPathWithGivenSum(t->left, s);
        }
        return possible;
    }   
    return false;
}