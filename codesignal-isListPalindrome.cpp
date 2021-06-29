//https://app.codesignal.com/interview-practice/task/HmNvEkfFShPhREMn4/solutions
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * l) {
    vector<int> v;
    while(l)
    {
        v.push_back(l->value);
        l = l->next;
    }
    for(int i = 0, j = (int)v.size() - 1; i < j; i++, j--)
        if(v[i] != v[j])
            return false;
    return true;
}
