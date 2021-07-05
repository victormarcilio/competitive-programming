//https://app.codesignal.com/interview-practice/task/gX7NXPBrYThXZuanm/description
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    ListNode<int>* ans, *first;
    while(l && l->value == k)
        l = l->next;
        
    first = ans = l;
    
    while(first)
    {
        if(first->next && first->next->value == k)
        {
            ListNode<int> *toRemove = first->next;
            first->next = first->next->next;
            delete toRemove;
        }
        else
            first = first->next;
    }
    
    return ans;
}
