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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL)
        {
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    
    ListNode* middleNode(ListNode* head) 
    {
        if(head==NULL || head->next==NULL) return head;
        //if(head->next->next==NULL) return head->next;  this is line modified for this use case
        if(head->next->next==NULL) return head;
         
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return pre;
        
    }
    
    int pairSum(ListNode* head) 
    {
        //if(head->next->next==NULL) return (head->val + head->next->val);
        ListNode* l = head;
        ListNode* mid = middleNode(head);
        ListNode* r = reverseList(mid->next);
        
        mid->next=NULL;
        
        int ans=0;
        while(l&&r)
        {
            ans=max(ans,l->val+r->val);
            l=l->next;
            r=r->next;
        }
        return ans;
    }
};