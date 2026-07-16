#include <iostream>
#include <unordered_set>

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

// Brute Force Method-------------------------------------------------
Node *startingLoopNode(Node *head)
{
    Node *temp = head;
    unordered_set<Node *> st;
    while (temp != NULL)
    {
        if (st.find(temp) != st.end())
        {
            return temp;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return NULL;
}

// Optimal Method-------------------------------------------------
Node *startingLoopNode2(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        return NULL;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main()
{

    return 0;
}

/*
Brute Force Method-------------------------------------------------
Time Complexity: O(N) where N is the number of nodes in the linked list. Each node is visited only once during traversal. Hashing allows O(1) lookup to check for previously visited nodes.

Space Complexity: O(N) due to the additional hash set used to store visited nodes. In the worst case (no cycle), all N nodes will be stored in the hash set.
*/

/*
Optimal Method-------------------------------------------------
Time Complexity: O(N) where N is the number of nodes in the linked list. In the worst case, we traverse the entire list once with the slow and fast pointers, and then again to find the entry point of the loop.

Space Complexity: O(1) constant extra space. No additional data structures are used, only two pointers
*/