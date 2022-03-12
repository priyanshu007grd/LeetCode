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

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if(head==NULL) return head;
        Node* c1;
        
        for(c1=head;c1!=NULL;)
        {
            Node* t1 = new Node(c1->val);
            t1->next=c1->next;
            c1->next=t1;
            c1=t1->next;
        }
        
        //for(c1=head;c1!=NULL;c1=c1->next) cout<<c1->val<<"   ";cout<<endl;
        
        for(c1=head;c1!=NULL && c1->next!=NULL;c1=c1->next->next) 
        {
            if(c1->random!=NULL) c1->next->random = c1->random->next;
        }
        
        Node* newH = head->next;
        Node* c2=newH;
        
        
        for(c1=head,c2=newH;c1!=NULL && c2!=NULL;c1=c1->next,c2=c2->next)
        {
            if(c1->next) c1->next=c1->next->next;
            if(c2->next) c2->next=c2->next->next;
            
        }
        
        //for(l1=head;l1!=NULL;l1=l1->next) cout<<l1->val<<"   ";cout<<endl;
        //for(l1=newH;l1!=NULL;l1=l1->next) cout<<l1->val<<"   ";cout<<endl;
        return newH;
    }
};