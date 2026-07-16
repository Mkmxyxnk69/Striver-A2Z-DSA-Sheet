#include<iostream>
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

//Brute Force Method---------------------------------------------
Node* segregateOddEven(Node* head){
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    vector<int> arr={};
    Node* temp = head;
    while (temp!=NULL && temp->next!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if (temp!=NULL)
    {
        arr.push_back(temp->data);
    }
    
    temp=head->next;
    while (temp!=NULL && temp->next!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if (temp!=NULL)
    {
        arr.push_back(temp->data);
    }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    
    temp=head;
    for (int i = 0; i < arr.size(); i++)
    {
        temp->data=arr[i];
        temp=temp->next;
    }
    return head;
}

//Optimal Method---------------------------------------------
Node* segregateOddEven2(Node* head){
    Node* odd=head;
    Node* even = head->next;
    Node* evenHead=head->next;
    while (even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    Node* head=converterArr2LL(arr);
    print(head);
    head=segregateOddEven2(head);
    print(head);
    return 0;
}

/*
Brute Force Method---------------------------------------------
Time Complexity: O(2n)
Space Complexity: O(n)

*/

/*
Optimal Method---------------------------------------------
Time Complexity: O(n), We traverse the entire linked list only once to rearrange the nodes. Each node is visited exactly once. No nested traversal or re-traversal occurs. Hence, linear time in terms of the number of nodes n.
Space Complexity: O(1), We do not use any extra data structures
*/