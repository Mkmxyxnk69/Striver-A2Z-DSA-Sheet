#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }

};

Node* converterArr2LL(vector<int> &arr){
    Node* head= new Node(arr[0],nullptr);
    Node* mover=head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp= new Node(arr[i],nullptr);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

//Brute Force Method------------------------------------------------------------
bool isPalindrome(Node* head){
    Node* temp= head;
    stack<int> st;
    while (temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL)
    {
        if (temp->data!=st.top())
        {
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;
}

//Optimal Method------------------------------------------------------------
Node* reverseLL(Node* head){
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* newhead=reverseLL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
    
}

bool isPalindrome2(Node* head){
    if (head==NULL || head->next==NULL)
    {
        return true;
    }
    Node* slow=head;
    Node* fast=head;
    while (fast->next!=NULL && fast->next->next!=NULL)
    {
     slow=slow->next;
     fast=fast->next->next;   
    }
    Node* newHead=reverseLL(slow->next);
    Node* first=head;
    Node* second=newHead;
    while (second!=NULL)
    {
        if (first->data!=second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;
}
int main(){
    
    return 0;
}

/*
Brute Force Method------------------------------------------------------------
Time Complexity: O(N), we traverse the entire linked list twice, once to push all elements into the stack, and once to compare them with the original list.

Space Complexity: O(N), we use a stack that stores all the elements of the linked list, which takes linear space in the worst case.
*/

/*
Better Method------------------------------------------------------------
Time Complexity: O(N), we traverse the list twice, once to reverse half of it and once to compare, each taking O(N/2), which simplifies to O(N).

Space Complexity: O(1), no extra space is used apart from a few pointers; operations are done in-place.
*/