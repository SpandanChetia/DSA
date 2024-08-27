#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(int data) : data(data), next(NULL) {}
};

struct Compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->data < b->data;
    }
};

ListNode* betterMerge(vector<ListNode*>lists){
    priority_queue<ListNode*, vector<ListNode*>, function<bool(const ListNode*, const ListNode*)>> pq(
        [&](const ListNode* a, const ListNode* b) {
            return a->data > b->data; 
        }
    );
    ListNode* dummy = new ListNode(-1);

    for(auto& l : lists){
        if(l){
            pq.push(l);
        }
    }

    ListNode* curr = dummy;

    while(!pq.empty()){
        ListNode* c = pq.top();
        pq.pop();

        curr->next = c;
        curr = curr->next;

        if(c->next){
            pq.push(c->next);
        }
    }
    ListNode* head = dummy->next;
    delete(dummy);
    return head;
}

void printList(ListNode* node){
    while(node){
        cout << node->data << " ";
        node = node->next;
    }
}
int main(){
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);
    ListNode* d = new ListNode(40);

    a->next = b; b->next = c; c->next = d;

    ListNode* w = new ListNode(15);
    ListNode* x = new ListNode(25);
    ListNode* y = new ListNode(35);

    w->next = x; x->next = y;

    vector<ListNode*>lists = {a, w};
    ListNode* head = betterMerge(lists);

    printList(head);
}