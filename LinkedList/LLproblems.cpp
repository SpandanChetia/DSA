#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ListNode{
    int data;
    ListNode * next;

    ListNode(int data) : data(data), next(NULL) {};
};

ListNode*prevn=NULL;
ListNode*head=NULL;
void add(int data){
    ListNode*tmp=new ListNode(data);
    if(head==NULL){
        head=tmp;
        prevn=tmp;
    }
    else{
        prevn->next=tmp;
        prevn=tmp;
    }
}
void deleteNode(int data){
    ListNode* dummy= new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;

    while(curr->data != data){
        prev= curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete(curr);
    head = dummy->next;
    delete(dummy);
}

ll findLen(){
    ll len = 0;
    ListNode* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

ListNode* findmiddle(){
    ListNode* t = head;
    ListNode* h = head;

    while(h->next && h->next->next){
        t = t->next;
        h = h->next->next;
    }
    return t;
}
void reverseLL(){
    ListNode* curr = head;
    ListNode* prev = NULL;

    while(curr){
        ListNode* nx = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nx;
    }
    ListNode* newh = prevn;
    prevn = head;
    head = newh;
}

ListNode* loopDetection(){
    ListNode* curr = head;
    ListNode* prev = head;

    while(curr && curr->next){
        curr = curr->next->next;
        prev = prev->next;
        if(prev==curr){
            break;
        }
    }
    if(!curr || !curr->next){
        return NULL;
    }
    prev= head;
    while(prev!=curr){
        prev = prev->next;
        curr = curr->next;
    }
    return prev;
}

void printList(){
    ListNode*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
    add(20);
    add(30);
    add(40);
    add(25);
    add(45);

    ListNode* curr = new ListNode(10);          //   LOOP CREATION
    ListNode* curr1 = new ListNode(11);
    ListNode* curr2 = new ListNode(12);

    curr->next = curr1;
    curr1->next = curr2;
    curr2->next = curr;
    head = curr;


    //cout << "Length " << findLen();
    //cout << endl;
    //cout << findmiddle()->data <<" ";
    //cout << endl;
    //reverseLL();
    ListNode* cycle = loopDetection();
    if(!cycle){
        cout << "Loop doesn't exist" << " ";
    }
    else cout << "Intersection " << cycle->data;
}