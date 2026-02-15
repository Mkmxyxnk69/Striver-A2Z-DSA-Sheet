#include<iostream>
using namespace std;
vector<int> temp;
//METHOD 1--------------------------------------------------------------------------------------------
void leftRotate1(vector<int> &arr){
    for (int j = 1; j < arr.size(); j++)
    {
        temp.push_back(arr[j]);
        
    }
    temp.push_back(arr[0]);      
}
// METHOD 2--------------------------------------------------------------------------------------------
void leftRotate2(vector<int> &arr,int d){
    for (int k= 0; k< d; k++)
    {
        
        int temp=arr[0];
        for (int j = 1; j < arr.size(); j++)
        {
            arr[j-1]=arr[j];
            
        }
        arr[arr.size()-1]=temp;    
    }
    
}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    // leftRotate1(arr); // (METHOD 1)-------------------------------------------------------------------
    for (int i = 0; i < temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }

    leftRotate2(arr,4); // (METHOD 2)---------------------------------------------------------------------
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    
     
    return 0;
}

// Time Complexity: O(N), We traverse the entire original array only once.
// Space Complexity: O(1), Extra space required and if interview asked space complexity for the whole algorithm will be O(N)