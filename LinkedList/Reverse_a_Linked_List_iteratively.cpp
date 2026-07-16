#include<iostream>
#include<stack>
#include<set>
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
//printing the LL
void print(Node* head){
    Node* temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}

//Brute Forced Method
Node* reversingLL(Node* head){
    stack<int> st;
    Node* temp = head;
    while (temp!=nullptr)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while (temp!=nullptr)
    {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

//Optimal Method
Node* reversingLL2(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while (temp!=NULL)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=converterArr2LL(arr);
    print(head);
    head=reversingLL2(head);
    print(head);
    return 0;
}

/*
Brute Force Method
Time Complexity: O(N) ,We traverse the linked list twice once to push all node values into the stack, and once to reassign values. Each traversal takes O(N) time, where N is the number of nodes.
Space Complexity: O(N) , We use an extra stack to store all the node values, which requires O(N) additional space.
*/

/*
Optimal Method
Time Complexity: O(N) Because we are traversing each node of the linked list exactly once. Each pointer reversal is done in constant time.
Space Complexity: O(1) We are not using any additional data structure or recursion. All modifications are done in-place using pointers.
*/