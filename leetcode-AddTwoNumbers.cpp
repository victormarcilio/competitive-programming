/** https://leetcode.com/problems/add-two-numbers/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *second = head;
        int carry = 0;
        while(l1 && l2)
        {
            int result = carry + l1->val + l2->val;
            if(result > 9)
            {
                carry = 1;
                result -= 10;
            }
            else
                carry = 0;
            second->next = new ListNode(result);
            second = second->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1)
            l1 = l2;
        while(l1)
        {
            int result = carry + l1->val;
            if(result > 9)
            {
                carry = 1;
                result -= 10;
            }
            else
                carry = 0;
            second->next = new ListNode(result);
            second = second->next;
            
            l1 = l1->next;
        }
        if(carry)
            second->next = new ListNode(1);
        return head->next;
    }
};
