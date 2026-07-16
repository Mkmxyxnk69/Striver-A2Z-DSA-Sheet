#include <iostream>
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

//Brute Force Method-----------------------------------------------------------------------
Node* sort0s1s2s(Node *head)
{
    Node *temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            cnt0++;
        }
        else if (temp->data == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
        temp=temp->next;
    }
    temp=head;
    while (cnt0--)
    {
        temp->data = 0;
        temp= temp->next;
    }
    while (cnt1--)
    {
        temp->data = 1;
        temp= temp->next;
    }
    while (cnt2--)
    {
        temp->data = 2;
        temp= temp->next;
    }
    return head;
}

//Optimal Method-----------------------------------------------------------------------
Node* sort0s1s2s2(Node* head){
    Node* zero=new Node(-1);
    Node* zeroHead=zero;

    Node* one=new Node(-1);
    Node* oneHead=one;

    Node* two=new Node(-1);
    Node* twoHead=two;

    Node* temp=head;
    while (temp!=NULL)
    {
        if (temp->data==0)
        {
            zero->next=temp;
            zero=zero->next;
        }
        else if (temp->data==1)
        {
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=oneHead->next;
    one->next=twoHead->next;
    two->next=NULL;
    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    return zeroHead->next;
}

int main()
{
    vector<int> arr = { 0, 0, 2,2,2};
    Node *head = converterArr2LL(arr);
    head=sort0s1s2s2(head);
    print(head);
    return 0;
}

/*
Brute Force Method-----------------------------------------------------------------------
TC: O(2n)
SC: O(1)
*/

/*
Optimal Method-----------------------------------------------------------------------
Time Complexity: O(n), We traverse the entire list once.
Space Complexity: O(1), Only dummy nodes and pointers are used (constant space).
*/

