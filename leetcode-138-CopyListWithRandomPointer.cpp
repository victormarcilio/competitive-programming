/* https://leetcode.com/problems/copy-list-with-random-pointer/
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    if(!head)
        return nullptr;
    unordered_map<Node*, Node*> map;
    Node* new_head = new Node(head->val);
    map[head] = new_head;
    Node* curr = new_head;
    Node *original = head->next;
    while(original)
    {
        curr->next = new Node(original->val);
        curr = curr->next;
        map[original] = curr;
        original = original->next;
    }
    original = head;
    curr = new_head;
    while(original)
    {
        if(original->random)
            curr->random = map[original->random];
        curr = curr->next;
        original = original->next;
    }
    return new_head;
    }
};
