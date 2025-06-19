/**
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

private: 
    ListNode* reverse(ListNode* head, ListNode* end)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr != end)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int rem = 0;
        ListNode* temp = head;
        while(rem < k && temp!=NULL)
        {
            temp = temp->next;
            rem++;
        }
        if(rem < k)
            return head;
        ListNode* new_head = reverse(head, temp);
        head->next = reverseKGroup(temp, k);
        return new_head;
    }
};