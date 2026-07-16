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
int lenghtOfLL(Node *head)
{
    Node *temp = head;
    int cnt = 1;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
// Brute Force Method;--------------------------------------------------------------------------------------
Node *removeKthNodeFromEnd(Node *head, int n)
{
    int kth = lenghtOfLL(head) - n;
    if (kth == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        return head;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < kth - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *front = temp->next;
    temp->next = temp->next->next;
    front->next = NULL;
    return head;
}

// Optimal Method--------------------------------------------------------------------------------------
Node *removeKthNodeFromEnd2(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)
    {
        return head->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delNode->next = NULL;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = converterArr2LL(arr);
    print(head);
    head = removeKthNodeFromEnd2(head, 2);
    print(head);
    return 0;
}

/*
Brute Force Method--------------------------------------------------------------------------------------
Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.
Space Complexity: O(1), constant additional space is used.
*/

/*
Optimal Method--------------------------------------------------------------------------------------
Time Complexity: O(N), since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
Space Complexity: O(1), constant additional space is used to check unique elements.
*/