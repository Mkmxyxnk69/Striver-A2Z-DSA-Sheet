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

//Iteratively-----------------------------------------------------------------
Node* adding1_1(Node* head){
    head=reversingLL2(head);
    Node* temp=head;
    int carry=1;
    while (temp!=NULL)
    {
        temp->data=temp->data+carry;
        if (temp->data<10)
        {
            carry=0;
            break;
        }
        else{
            carry=1;
            temp->data=0;
        }
        temp=temp->next;
    }
    if (carry==1)
    {
        Node* newNode=new Node(1);
        head=reversingLL2(head);
        newNode->next=head;
        return newNode ;
    }
    head=reversingLL2(head);
    return head;
}

//Recursion-----------------------------------------------------------------
int helper(Node* temp){
    int carry;
    if (temp==NULL)
    {
        return 1;
    }
    carry=helper(temp->next);
    temp->data=temp->data+carry;
    if (temp->data<10)
    {
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* adding1_2(Node* head){
    Node* temp= head;
    int carry=helper(temp);
    if (carry==1)
    {
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr={9};
    Node* head = converterArr2LL(arr);
    print(head);
    head=adding1_2(head);
    print(head);
    return 0;
}

/*
Iteratively-----------------------------------------------------------------
Time Complexity: O(3n), Two reversals + one pass for addition.
Space Complexity: O(1), Iterative, no extra stack used.*/
/*
Recursive-----------------------------------------------------------------
Time Complexity: O(n), One pass for addition.
Space Complexity: O(n), Auxiliary stack space.
*/