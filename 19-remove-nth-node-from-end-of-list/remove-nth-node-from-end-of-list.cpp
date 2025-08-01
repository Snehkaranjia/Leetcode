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
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseList(head);
        ListNode* curr = head;
        ListNode* prev = NULL;
        if(n==1)
        {
            head = curr->next;
            curr->next = NULL;
        }
        else
        {
            while(n > 1)
            {
                prev = curr;
                curr = curr->next;
                n--;
            }
            prev->next = curr->next;
            curr->next = NULL;
        }
        
        head = reverseList(head);
        return head;
    }
};