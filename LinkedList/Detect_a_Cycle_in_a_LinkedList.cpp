#include<iostream>
#include <unordered_set> 

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

// Brute Force Method------------------------------------------------------ 
bool detectingLoop(Node* head){
    Node* temp=head;
    unordered_set<Node*> mpp;
    while (temp!=NULL)
    {
        if (mpp.find(temp)!=mpp.end())
        {
            return true;
        }   
        else{
            mpp.insert(temp);
            temp=temp->next;
        }
    }
    return false;
}

//Optimal Method------------------------------------------------------ 
bool detectingLoop2(Node* head){
    Node* fast=head->next;
    Node* slow=head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)
        {
            return true;
        }
    }
    

}
int main(){
    vector<int> arr={1,2,3,5};
    Node* head = converterArr2LL(arr);
    cout<<detectingLoop2(head);
    return 0;
}

/*
Brute Force Method------------------------------------------------------ 
Time Complexity: O(N*LogN), we traverse the entire linked list once and store and retrieve nodes from the hash map. Map operations have a worst time space complexiy of O(LogN).
Space Complexity: O(N) , additional amount of extra space is used to store nodes in a set.
*/

/*
Optimal Method------------------------------------------------------ 
Time Complexity: O(N), we traverse the entire linked list once. The fast pointer either reaches the end of the list or meets the slow pointer in linear time.
Space Complexity: O(1) , constant amount of extra space is used detect a cycle using Floyd's Cycle Detection Algorithm
*/