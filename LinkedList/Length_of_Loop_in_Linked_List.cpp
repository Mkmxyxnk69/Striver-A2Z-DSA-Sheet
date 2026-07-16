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

//Optimal
int findlength(Node* slow,Node* fast){
    int cnt=1;
    fast=fast->next;
    while (fast!=slow)
    {
        fast=fast->next;
        cnt++;
    }
    return cnt;
    
}
int lengthOfLoop(Node* head){
    Node* fast=head;
    Node* slow=head;
    int cnt=0;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (fast==slow)
        {
            return findlength(slow,fast);
        }
    }
    
}


int main(){
    
    return 0;
}

/*optimal*/