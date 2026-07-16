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

//Optimal Method-------------------------------------------------------------------------
Node *deleteMiddleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{
    vector<int> arr={1,2,3,4,5,6,6,7};
    Node* head=converterArr2LL(arr);
    print(head);
    head=deleteMiddleNode(head);
    print(head);
}

/*
Optimal Method-------------------------------------------------------------------------
Time Complexity: O(N/2), we traverse the entire linked list using slow and fast pointers, effectively covering about half the list before reaching the midpoint.
Space Complexity: O(1) , we have fixed number of pointers and variables to delete the Kth node.
*/
