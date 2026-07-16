#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *converterArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
// printing the LL
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

//Brute Force Method-----------------------------------------
Node* sortingLL(Node* head){
    Node* temp=head;
    vector<int> arr;
    while (temp!=NULL)
    {
        arr.push_back(temp->data);
        temp=temp->next;
    }
    temp=head;
    sort(arr.begin(),arr.end());
    int i =0;
    while (temp!=NULL)
    {
        temp->data=arr[i];
        temp=temp->next;
        i++;
    }
    return head;
}

//Optimal Method----------------------------------------
Node* middle(Node* head){
    Node* fast=head->next;
    Node* slow=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
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

Node* sortingLL2(Node* head){
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* mid=middle(head);
    Node* leftHead=head;
    Node* rightHead=mid->next;
    mid->next = NULL; 
    leftHead=sortingLL2(leftHead);
    rightHead=sortingLL2(rightHead);
    return merging2LL(leftHead,rightHead);

}
int main(){
    vector<int> arr = { 5,3,2,3,5,1,2,3};
    Node *head = converterArr2LL(arr);
    head=sortingLL2(head);
    print(head);
    return 0;
}
/*
Brute Force Method----------------------------------------
Time Complexity: O(2*N + N*LogN), we traverse the linked list, store its elements in an array, sort it, and then copy the sorted values back into the original list.
Space Complexity: O(N) , additional space required to store all the elements of linked list in an array.
*/

/*
Optimal Method----------------------------------------
Time Complexity: O(N*LogN), we recursively divide the linked list into two halves and then merge two sorted halves.
Space Complexity: O(1) , constant additional space is required to sort the entire linked list.
*/