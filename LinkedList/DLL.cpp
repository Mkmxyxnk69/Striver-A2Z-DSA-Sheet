#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

//Coverting array to DLL----------------------------------------------
Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i= 1; i < arr.size(); i++)
    {
        Node* temp= new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

//printing the DLL----------------------------------------------
void print(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//Deleting the head in DLL----------------------------------------------
Node* deleteHead(Node* head){
    if (head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}

//Deleting the tail in DLL----------------------------------------------
Node* deleteTail(Node* head){
    if (head==NULL)
    {
        return NULL;
    }
    if (head->next==NULL)
    {
        delete head;
    }
    Node* tail=head;
    while (tail->next!=nullptr)
    {
        tail=tail->next;
    }
    Node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    delete tail;
    return head;
}

//Deleting the Kth element----------------------------------------------
Node* deleteKthElement(Node* head,int kth){
    if (head==NULL)
    {
        return NULL;
    }
    int cnt=0;
    Node* kNode=head;
    while (kNode!=NULL)
    {
        cnt++;
        if (cnt==kth)
        {
            break;
        }
        kNode=kNode->next;
    }
    Node* front=kNode->next;
    Node* prev=kNode->back;

    if (prev==NULL || front==NULL)
    {
        return NULL;
    }
    else if (prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;

    kNode->next=nullptr;
    kNode->back=nullptr;
    delete(kNode);
    return head;
}

//Deleting element ---------------------------------------------
Node* deleteElement(Node* head,int ele){
    if (head==NULL)
    {
        return NULL;
    }

    Node* kNode=head;
    while (kNode!=NULL)
    {

        if (kNode->data==ele)
        {
            break;
        }
        kNode=kNode->next;
    }
    Node* front=kNode->next;
    Node* prev=kNode->back;

    if (prev==NULL || front==NULL)
    {
        return NULL;
    }
    else if (prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;

    kNode->next=nullptr;
    kNode->back=nullptr;
    delete(kNode);
    return head;
}

//Inserting new head before old head---------------------------------------------
Node* insertingNewHead(Node* head,int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

// Inserting before tail ---------------------------------------------
Node* insertingBeforeTail(Node* head,int val){
    if (head->next==NULL)
    {
        return insertingNewHead(head,val);
    }
    Node* tail=head;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node* previous=tail->back;
    Node* newNode= new Node(val,tail,previous);
    previous->next=newNode;
    tail->back=newNode;
    return head;
}

//Inserting before the kth element---------------------------------------------
Node* insertingBeforekthElement(Node* head,int kth,int val){
    if (kth==1)
    {
        return insertingNewHead(head,val);
    }
    int cnt=1;
    Node* temp=head;
    while (temp!=NULL)
    {
        if (cnt==kth)
        {
            break;
        }
        cnt++;
        
        temp=temp->next;
    }
    Node* previous=temp->back;
    Node* newNode= new Node(val,temp,previous);
    previous->next=newNode;
    temp->back=newNode;
    return head;
}

//Inserting before the element ---------------------------------------------
void insertingBeforeNode(Node* node,int val){
    
    Node* prev=node->back;
    Node* newNode= new Node(val,node,prev);
    node->back=newNode;
    prev->next=newNode;
}
int main(){
    vector<int> arr={2,5,8,7};
    
    //Printing the DoubleLinkedlist----------------------------------------------
    Node* head=convertArr2DLL(arr);
    print(head);

    //Deleteing Head from DLL----------------------------------------------
    // head=deleteHead(head);
    // print(head);

    //Deleting tail from DLL----------------------------------------------
    // head=deleteTail(head);
    // print(head);

    //Deleting Kth element in the DLL;----------------------------------------------
    // head=deleteKthElement(head,2);
    // print(head);

    // Deleting the element in the DLL---------------------------------------------
    // head=deleteElement(head,8);
    // print(head);

    // Inserting before the head---------------------------------------------
    // head=insertingNewHead(head,5);
    // print(head);

    //Inserting before tail---------------------------------------------
    // head=insertingBeforeTail(head,12);
    // print(head);

    //Inserting before kth element---------------------------------------------
    // head=insertingBeforekthElement(head,3,22);
    // print(head);

    //Inserting before node---------------------------------------------
    // insertingBeforeNode(head->next,1);
    // print(head);

    return 0;
}