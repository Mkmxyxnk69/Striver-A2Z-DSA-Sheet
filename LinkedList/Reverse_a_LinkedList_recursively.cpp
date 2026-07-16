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
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=converterArr2LL(arr);
    print(head);
    head=reverseLL(head);
    print(head);
    return 0;
}

/*
Complexity Analysis------------------------------
Time Complexity: O(n),Each node is visited exactly once during the recursive call, and we do constant-time work for each node (like flipping pointers).
Space Complexity: O(n),The recursion stack goes up to n levels deep (one for each node), which uses extra space on the call stack.
*/