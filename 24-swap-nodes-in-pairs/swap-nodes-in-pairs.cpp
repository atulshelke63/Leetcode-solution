/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head==NULL || head->next==NULL){
            return head;
        }

        ListNode* prevNode=NULL;
        ListNode* curr=head;
        ListNode* nextNode=curr->next;

        while (curr != NULL && nextNode != NULL){
            ListNode* third=nextNode->next;

            nextNode->next=curr;
            curr->next=third;

            if (prevNode != NULL){
                prevNode->next=nextNode;
            }else {
                head=nextNode;
            }

            prevNode=curr;
            curr=third;
            if (third != NULL){
                nextNode=third->next;
            }else {
                nextNode=NULL;
            }
        }
        return head;
    }
};