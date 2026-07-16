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

};

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

//Counting the Length of the LinkedList----------------------------------------------
int lengthOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while (temp)
    {
        
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

//Checking if the element is present in the Linked list----------------------------------------------
bool checkIfpresent(Node* head,int val){
    Node* temp=head;
    while (temp)
    {
        if (temp->data==val)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

//Deleting head----------------------------------------------
Node* removeHead(Node* head){
    if (head==NULL)
    {
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}


//Deleting tail----------------------------------------------
Node* removeTail(Node* head){
    if (head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

//Deleting Kth element in the LL----------------------------------------------
Node* removeKthElement(Node* head,int k){
    int cnt=0;
    if (head==NULL)
    {
        return head;
    }
    if (k==1)
    {
        Node* temp=head;
        head=head->next;
        free (temp);
        return head;
    }
    Node* temp=head;
    Node* previous=NULL;
    while (temp!=NULL)
    {
        cnt++;
        if (cnt== k)
        {
            previous->next=previous->next->next;
            free (temp);
            break;
        }
        previous=temp;
        temp=temp->next;
    }
    return head;
}

//Removing element from the LL----------------------------------------------
Node* removeElement(Node* head,int el){
    
    if (head==NULL)
    {
        return head;
    }
    if (head->data==el)
    {
        Node* temp=head;
        head=head->next;
        free (temp);
        return head;
    }
    Node* temp=head;
    Node* previous=NULL;
    while (temp!=NULL)
    {

        if (temp->data==el)
        {
            previous->next=previous->next->next;
            free (temp);
            break;
        }
        previous=temp;
        temp=temp->next;
    }
    return head;
}

//Inserting in the head----------------------------------------------
Node* insertingHead(Node* head, int val){
    return new Node(val,head);
}

//Inserting in the tail
Node* insertTail(Node* head,int val){
    if (head==NULL)
    {
        return new Node(val,nullptr);
    }
    Node* temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* newNode=new Node(val,nullptr);
    temp->next=newNode;
    return head;
}

//Inserting in the kth position----------------------------------------------
Node* insertKthElement(Node* head,int el,int k){
    if (head==NULL)
    {
        if (k==1)
        {
            return new Node(el,nullptr);
        }
        else{
            return head;
        }
        
    }
    if (k==1)
    {
        return new Node(el,head);
    }
    int cnt=0;
    Node* temp= head;
    while (temp!=NULL)
    {
        cnt++;
        if (cnt==k-1)
        {
            Node* x = new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Inserting Element before value
Node* insertingElementBeforeValue(Node* head,int el,int val){
    if (head==NULL)
    {
        return NULL;
        
    }
    if (head->data==val)
    {
        return new Node(el,head);
    }
    int cnt=0;
    Node* temp= head;
    while (temp->next!=NULL)
    {
        
        if (temp->next->data==val)
        {
            Node* x = new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}


int main(){
    vector<int> arr={2,5,8,7};
    
    //Printing the Linkedlist----------------------------------------------
    Node* head=converterArr2LL(arr);
    Node* temp=head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    //Printing the length of the LinkedList----------------------------------------------
    // cout<<"The length of LL is "<<lengthOfLL(head)<<endl;

    //Output of thee checking----------------------------------------------
    // cout<<checkIfpresent(head,8)<<endl;
    
    //Deleting the head and printing the rest of the LinkedList----------------------------------------------
    // removeHead(head);
    // print(head);

    //Deleting the tail and printing the rest of the LinkedList----------------------------------------------
    // removeTail(head);
    // print(head);
    
    //removing the Kth element in the linkedlist----------------------------------------------
    // removeKthElement(head,2);
    // print(head);

    //Removing the element value in the LL----------------------------------------------
    // head=removeElement(head,5);
    // print(head);

    //Inserting Element in the head position---------------------------------------------
    // head=insertingHead(head,1);
    // print(head);

    //Inserting Element in the tail position---------------------------------------------
    // head=insertTail(head,4);
    // print(head);

    //Inserting Element in the kth Position and displaying the LL----------------------------------------------
    // head=insertKthElement(head,6,3);
    // print(head);

    //Inserting Element before the value and displaying the LL----------------------------------------------
    // head=insertingElementBeforeValue(head,6,5);
    // print(head);
    
    return 0;
}