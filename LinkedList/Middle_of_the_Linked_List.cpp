#include<iostream>
using namespace std;
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

//Brute Force Method
Node* middleNode(Node* head){
    Node* temp=head;
    int cnt=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    temp=head;
    int n=1;
    while (n<((cnt/2)+1))
    {
        temp=temp->next;
        n++;
    }
    return temp;
}

//Optimal Method
Node* middleNode2(Node* head){
    Node* fast=head;
    Node* slow=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* head=converterArr2LL(arr);
    print(head);

    Node* middle=middleNode2(head);
    cout<<middle->data;


    return 0;
}