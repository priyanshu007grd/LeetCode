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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* h1=head,*t1=head,*t2=head;
        while(--k) h1=h1->next;
        t1=h1;
        while(h1->next)
        {
            t2=t2->next;
            h1=h1->next;
        }
        
        int t=t1->val;
        t1->val=t2->val;
        t2->val=t;
        
        return head;
    }
};