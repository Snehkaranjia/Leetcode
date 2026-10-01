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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) 
            return head;
        int cnt = 1;
        ListNode* curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
            cnt++;
        }
        k = k % cnt;
        if(k==0)
            return head;
        curr->next = head;
        int steps = cnt-k;
        ListNode* newcurr = head;
        while(--steps)
            newcurr = newcurr->next;
        ListNode* newhead = newcurr->next;
        newcurr->next = NULL;
        return newhead;
    }
};