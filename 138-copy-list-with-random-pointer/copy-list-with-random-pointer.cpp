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
        if (head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> m;
        Node* newhead=new Node(head->val);
        Node* old_temp=head->next;
        Node* new_temp=newhead;
        m[head]=newhead;

        while (old_temp!=NULL){
            Node* copynode=new Node(old_temp->val);
            m[old_temp]=copynode;
            new_temp->next=copynode;
            old_temp=old_temp->next;
            new_temp=new_temp->next;
        }

        old_temp=head;
        new_temp=newhead;
        while (old_temp!=NULL){
            new_temp->random=m[old_temp->random];

            old_temp=old_temp->next;
            new_temp=new_temp->next;
        }

        return newhead;
    }
};