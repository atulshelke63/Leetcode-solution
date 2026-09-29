#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head=tail=NULL;
    }

    void push_back(int val){
        Node* newNode=new Node(val);

        if (head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    bool isSorted(){
        Node* temp=head;

        while(temp!=NULL && temp->next!=NULL){
            if (temp->data > temp->next->data){
                return false;
            }
            temp=temp->next;
        }
        return true;
    }

    void mergeMinPair(){
        Node* temp=head;
        Node* minNode=head;
        int minSum=INT_MAX;

        while (temp!=NULL && temp->next!=NULL){
            long long sum=(long long)temp->data+temp->next->data;

            if (sum<minSum){
                minSum=sum;
                minNode=temp;
            }
            temp=temp->next;
        }
        Node* removeNode=minNode->next;

        minNode->data = minSum;
        minNode->next = removeNode->next;

        if (removeNode->next != NULL){
            removeNode->next->prev=minNode;
        }else{
            tail=minNode;
        }
        delete removeNode;
    } 
};    

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        DoublyList list;

        for (int num:nums){
            list.push_back(num);
        }

        int operation=0;

        while (!list.isSorted()){
            list.mergeMinPair();
            operation++;
        }
        return operation;   
    }
};