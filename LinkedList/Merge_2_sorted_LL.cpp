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
//Converting array to LinkedList----------------------------------------------
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

//Optimal Method
Node* merging2LL(Node* head1, Node* head2){
    Node* temp1=head1;
    Node* temp2 = head2;
    Node* dummy= new Node (-1);
    Node* temp=dummy;
    while (temp1!=NULL && temp2!=NULL)
    {
        if (temp1->data<=temp2->data)
        {
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }
    if (temp1==NULL)
    {
        temp->next=temp2;
    }
    else temp->next=temp1;

    return dummy->next;
}
int main(){
    vector<int> arr1={1,3,5,6,8,13};
    vector<int> arr2={3,6,8,16,23,25};
    Node* head1=converterArr2LL(arr1);
    Node* head2=converterArr2LL(arr2);
    Node* head=merging2LL(head1,head2);
    print(head);
    return 0;
}

/*
Optimal Method
TC: O(n1+n2)
SC: O(1)
*/