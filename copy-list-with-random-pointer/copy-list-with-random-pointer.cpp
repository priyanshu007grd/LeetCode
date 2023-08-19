/*
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
        
        if(head==NULL) return head;
        Node* p1=head;
        
        while(p1) {
            Node* temp = new Node(p1->val);
            temp->next=p1->next;
            p1->next=temp;
            p1=temp->next;
        }
        
        for(p1=head;p1 && p1->next;p1=p1->next->next) {
            if(p1->random) p1->next->random=p1->random->next;
        }
        
    
        Node* p2;
        Node* newHead=head->next;
        
        for(p1=head,p2=newHead;p1 && p2;p1=p1->next,p2=p2->next) {
            if(p1->next) p1->next=p1->next->next;
            if(p2->next) p2->next=p2->next->next;
        }
        
        return newHead;
    }
};