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
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* adding2LL(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    int carry =0;
    int res=0;
    while (temp1!=NULL && temp2!=NULL)
    {
        int add=temp1->data+temp2->data+carry;
        if (add>9)
        {
            carry=1;
            res=add%10;
            Node* newHead=new Node(res);
        }
        else{
            carry=0;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
}
int main(){
    
    return 0;
}