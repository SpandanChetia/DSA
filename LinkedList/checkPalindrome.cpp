#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int data) : data(data), next(NULL) {}
};

ListNode *head = NULL, *prevn = NULL;

void add(int data) {
    ListNode *tmp = new ListNode(data);
    if (head == NULL) {
        head = tmp;
        prevn = tmp;
    } else {
        prevn->next = tmp;
        prevn = tmp;
    }
}

ListNode* findMiddle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseLL(ListNode *head) {
    ListNode *prev = NULL, *curr = head;
    while (curr) {
        ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode *head) {
    if (!head || !head->next){
        return true;
    }

    ListNode *mid = findMiddle(head);
    ListNode *secondHalfStart = reverseLL(mid->next);
    ListNode *firstHalfStart = head;
    ListNode *secondHalfCopy = secondHalfStart; 
    while (secondHalfStart) {
        if (firstHalfStart->data != secondHalfStart->data) {
            mid->next = reverseLL(secondHalfCopy);
            return false;
        }
        firstHalfStart = firstHalfStart->next;
        secondHalfStart = secondHalfStart->next;
    }

    mid->next = reverseLL(secondHalfCopy);

    return true;
}

void printList() {
    ListNode *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    add(20);
    add(30);
    add(40);
    add(30);
    add(20);

    if (isPalindrome(head)) {
        cout << "The list is a palindrome" << endl;
    } else {
        cout << "The list is not a palindrome" << endl;
    }

    printList(); 

    return 0;
}
